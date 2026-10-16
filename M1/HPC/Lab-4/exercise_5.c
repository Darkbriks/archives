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
//      8 neighbors using MPI types for non contiguous
//      side.
//
// SUMMARY:
//     - 2D splitting along X and Y
//     - 8 neighbors communications
//     - Blocking communications
// NEW:
//     - >>> MPI type for non contiguous cells <<<
//
//////////////////////////////////////////////////////

/****************************************************/
#include "src/lbm_struct.h"
#include "src/exercises.h"

static int lbm_neighbor_rank_ex5(const lbm_comm_t * comm, int dx, int dy)
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
void lbm_comm_init_ex5(lbm_comm_t * comm, int total_width, int total_height)
{
	lbm_comm_init_ex4(comm, total_width, total_height);

	MPI_Type_vector(
		comm->width,
		DIRECTIONS,
		comm->height * DIRECTIONS,
		MPI_DOUBLE,
		&comm->type);
	MPI_Type_commit(&comm->type);
}

/****************************************************/
void lbm_comm_release_ex5(lbm_comm_t * comm)
{
	MPI_Type_free(&comm->type);

	//we use the same implementation than ex5 except for type destroy
	lbm_comm_release_ex4(comm);
}

/****************************************************/
void lbm_comm_ghost_exchange_ex5(lbm_comm_t * comm, lbm_mesh_t * mesh)
{
	const int W = comm->width;
	const int H = comm->height;

	const int left       = lbm_neighbor_rank_ex5(comm, -1,  0);
	const int right      = lbm_neighbor_rank_ex5(comm, +1,  0);
	const int up         = lbm_neighbor_rank_ex5(comm,  0, -1);
	const int down       = lbm_neighbor_rank_ex5(comm,  0, +1);
	const int up_left    = lbm_neighbor_rank_ex5(comm, -1, -1);
	const int up_right   = lbm_neighbor_rank_ex5(comm, +1, -1);
	const int down_left  = lbm_neighbor_rank_ex5(comm, -1, +1);
	const int down_right = lbm_neighbor_rank_ex5(comm, +1, +1);

	const int col_count = H * DIRECTIONS;

	MPI_Sendrecv(
		lbm_mesh_get_cell(mesh, 1,     0), col_count, MPI_DOUBLE, left,  0,
		lbm_mesh_get_cell(mesh, W - 1, 0), col_count, MPI_DOUBLE, right, 0,
		comm->communicator, MPI_STATUS_IGNORE);

	MPI_Sendrecv(
		lbm_mesh_get_cell(mesh, W - 2, 0), col_count, MPI_DOUBLE, right, 1,
		lbm_mesh_get_cell(mesh, 0,     0), col_count, MPI_DOUBLE, left,  1,
		comm->communicator, MPI_STATUS_IGNORE);

	MPI_Sendrecv(
		lbm_mesh_get_cell(mesh, 0, 1),     1, comm->type, up,   2,
		lbm_mesh_get_cell(mesh, 0, H - 1), 1, comm->type, down, 2,
		comm->communicator, MPI_STATUS_IGNORE);

	MPI_Sendrecv(
		lbm_mesh_get_cell(mesh, 0, H - 2), 1, comm->type, down, 3,
		lbm_mesh_get_cell(mesh, 0, 0),     1, comm->type, up,   3,
		comm->communicator, MPI_STATUS_IGNORE);

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