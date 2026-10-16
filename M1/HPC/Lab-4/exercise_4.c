/*****************************************************
    AUTHOR  : Sébastien Valat
    MAIL    : sebastien.valat@univ-grenoble-alpes.fr
    LICENSE : BSD
    YEAR    : 2021
    COURSE  : Parallel Algorithms and Programming
*****************************************************/

//////////////////////////////////////////////////////
//
// Goal: Implement 2D grid communication scheme with
//       8 neighbors using manual copy for non
//       contiguous side and blocking communications
//
// SUMMARY:
//     - 2D splitting along X and Y
//     - 8 neighbors communications
//     - Blocking communications
//     - Manual copy for non continguous cells
//
//////////////////////////////////////////////////////

/****************************************************/
#include <stdlib.h>
#include <string.h>
#include "src/lbm_struct.h"
#include "src/exercises.h"

static int lbm_neighbor_rank(const lbm_comm_t * comm, int dx, int dy)
{
	const int cx = comm->rank_x + dx;
	const int cy = comm->rank_y + dy;

	if (cx < 0 || cx >= comm->nb_x || cy < 0 || cy >= comm->nb_y) {
		return MPI_PROC_NULL;
	}

	int coords[2] = { cx, cy };
	int r;
	MPI_Cart_rank(comm->communicator, coords, &r);
	return r;
}

/****************************************************/
void lbm_comm_init_ex4(lbm_comm_t * comm, int total_width, int total_height)
{
	int rank, comm_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);

	int dims[2] = { 0, 0 };
	MPI_Dims_create(comm_size, 2, dims);
	comm->nb_x = dims[0];
	comm->nb_y = dims[1];

	if (total_width  % comm->nb_x != 0) {
		fatal("total_width must be a multiple of nb_x !");
	}
	if (total_height % comm->nb_y != 0) {
		fatal("total_height must be a multiple of nb_y !");
	}

	int periods[2] = { 0, 0 };
	MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, /*reorder=*/0, &comm->communicator);

	int coords[2];
	MPI_Cart_coords(comm->communicator, rank, 2, coords);
	comm->rank_x = coords[0];
	comm->rank_y = coords[1];

	comm->width  = total_width  / comm->nb_x + 2;
	comm->height = total_height / comm->nb_y + 2;

	comm->x = comm->rank_x * (total_width  / comm->nb_x);
	comm->y = comm->rank_y * (total_height / comm->nb_y);

	const size_t row_bytes = (size_t)comm->width * DIRECTIONS * sizeof(double);
	comm->buffer_send_up   = malloc(row_bytes);
	comm->buffer_send_down = malloc(row_bytes);
	comm->buffer_recv_up   = malloc(row_bytes);
	comm->buffer_recv_down = malloc(row_bytes);
	if (comm->buffer_send_up   == NULL || comm->buffer_send_down == NULL || comm->buffer_recv_up   == NULL || comm->buffer_recv_down == NULL) {
		fatal("Failed to allocate ghost exchange buffers !");
	}

	//if debug print comm
	//lbm_comm_print(comm);
}

/****************************************************/
void lbm_comm_release_ex4(lbm_comm_t * comm)
{
	free(comm->buffer_send_up);
	free(comm->buffer_send_down);
	free(comm->buffer_recv_up);
	free(comm->buffer_recv_down);
	comm->buffer_send_up   = NULL;
	comm->buffer_send_down = NULL;
	comm->buffer_recv_up   = NULL;
	comm->buffer_recv_down = NULL;

	MPI_Comm_free(&comm->communicator);
}

/****************************************************/
void lbm_comm_ghost_exchange_ex4(lbm_comm_t * comm, lbm_mesh_t * mesh)
{
	const int W = comm->width;
	const int H = comm->height;

	const int left       = lbm_neighbor_rank(comm, -1,  0);
	const int right      = lbm_neighbor_rank(comm, +1,  0);
	const int up         = lbm_neighbor_rank(comm,  0, -1);
	const int down       = lbm_neighbor_rank(comm,  0, +1);
	const int up_left    = lbm_neighbor_rank(comm, -1, -1);
	const int up_right   = lbm_neighbor_rank(comm, +1, -1);
	const int down_left  = lbm_neighbor_rank(comm, -1, +1);
	const int down_right = lbm_neighbor_rank(comm, +1, +1);

	const int col_count = H * DIRECTIONS;

	MPI_Sendrecv(
		lbm_mesh_get_cell(mesh, 1,     0), col_count, MPI_DOUBLE, left,  0,
		lbm_mesh_get_cell(mesh, W - 1, 0), col_count, MPI_DOUBLE, right, 0,
		comm->communicator, MPI_STATUS_IGNORE);

	MPI_Sendrecv(
		lbm_mesh_get_cell(mesh, W - 2, 0), col_count, MPI_DOUBLE, right, 1,
		lbm_mesh_get_cell(mesh, 0,     0), col_count, MPI_DOUBLE, left,  1,
		comm->communicator, MPI_STATUS_IGNORE);

	const int row_count = W * DIRECTIONS;

	for (int x = 0; x < W; ++x) {
		const double * src = lbm_mesh_get_cell(mesh, x, 1);
		memcpy(&comm->buffer_send_up[x * DIRECTIONS], src, DIRECTIONS * sizeof(double));
	}
	for (int x = 0; x < W; ++x) {
		const double * src = lbm_mesh_get_cell(mesh, x, H - 2);
		memcpy(&comm->buffer_send_down[x * DIRECTIONS], src, DIRECTIONS * sizeof(double));
	}

	MPI_Sendrecv(
		comm->buffer_send_up,   row_count, MPI_DOUBLE, up,   2,
		comm->buffer_recv_down, row_count, MPI_DOUBLE, down, 2,
		comm->communicator, MPI_STATUS_IGNORE);

	MPI_Sendrecv(
		comm->buffer_send_down, row_count, MPI_DOUBLE, down, 3,
		comm->buffer_recv_up,   row_count, MPI_DOUBLE, up,   3,
		comm->communicator, MPI_STATUS_IGNORE);

	if (up != MPI_PROC_NULL) {
		for (int x = 0; x < W; ++x) {
			double * dst = lbm_mesh_get_cell(mesh, x, 0);
			memcpy(dst, &comm->buffer_recv_up[x * DIRECTIONS], DIRECTIONS * sizeof(double));
		}
	}
	if (down != MPI_PROC_NULL) {
		for (int x = 0; x < W; ++x) {
			double * dst = lbm_mesh_get_cell(mesh, x, H - 1);
			memcpy(dst, &comm->buffer_recv_down[x * DIRECTIONS], DIRECTIONS * sizeof(double));
		}
	}

	const int corner_count = DIRECTIONS;

	MPI_Sendrecv(
		lbm_mesh_get_cell(mesh, 1,     1),     corner_count, MPI_DOUBLE, up_left,    4,
		lbm_mesh_get_cell(mesh, W - 1, H - 1), corner_count, MPI_DOUBLE, down_right, 4,
		comm->communicator, MPI_STATUS_IGNORE);

	MPI_Sendrecv(
		lbm_mesh_get_cell(mesh, W - 2, H - 2), corner_count, MPI_DOUBLE, down_right, 5,
		lbm_mesh_get_cell(mesh, 0,     0),     corner_count, MPI_DOUBLE, up_left,    5,
		comm->communicator, MPI_STATUS_IGNORE);

	MPI_Sendrecv(
		lbm_mesh_get_cell(mesh, W - 2, 1),     corner_count, MPI_DOUBLE, up_right,   6,
		lbm_mesh_get_cell(mesh, 0,     H - 1), corner_count, MPI_DOUBLE, down_left,  6,
		comm->communicator, MPI_STATUS_IGNORE);

	MPI_Sendrecv(
		lbm_mesh_get_cell(mesh, 1,     H - 2), corner_count, MPI_DOUBLE, down_left,  7,
		lbm_mesh_get_cell(mesh, W - 1, 0),     corner_count, MPI_DOUBLE, up_right,   7,
		comm->communicator, MPI_STATUS_IGNORE);
}