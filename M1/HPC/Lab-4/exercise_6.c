/*****************************************************
    AUTHOR  : Sébastien Valat
    MAIL    : sebastien.valat@univ-grenoble-alpes.fr
    LICENSE : BSD
    YEAR    : 2021
    COURSE  : Parallel Algorithms and Programming
*****************************************************/

//////////////////////////////////////////////////////
//
// Goal: Implement 2D grid communication with non-blocking
//       messages.
//
// SUMMARY:
//     - 2D splitting along X and Y
//     - 8 neighbors communications
//     - MPI type for non contiguous cells
// NEW:
//     - Non-blocking communications
//
//////////////////////////////////////////////////////

/****************************************************/
#include "src/lbm_struct.h"
#include "src/exercises.h"

static int lbm_neighbor_rank_ex6(const lbm_comm_t * comm, int dx, int dy)
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
void lbm_comm_init_ex6(lbm_comm_t * comm, int total_width, int total_height)
{
	//we use the same implementation than ex5
	lbm_comm_init_ex5(comm, total_width, total_height);
}

/****************************************************/
void lbm_comm_release_ex6(lbm_comm_t * comm)
{
	//we use the same implementation than ext 5
	lbm_comm_release_ex5(comm);
}

/****************************************************/
void lbm_comm_ghost_exchange_ex6(lbm_comm_t * comm, lbm_mesh_t * mesh)
{
	const int W = comm->width;
	const int H = comm->height;

	const int left       = lbm_neighbor_rank_ex6(comm, -1,  0);
	const int right      = lbm_neighbor_rank_ex6(comm, +1,  0);
	const int up         = lbm_neighbor_rank_ex6(comm,  0, -1);
	const int down       = lbm_neighbor_rank_ex6(comm,  0, +1);
	const int up_left    = lbm_neighbor_rank_ex6(comm, -1, -1);
	const int up_right   = lbm_neighbor_rank_ex6(comm, +1, -1);
	const int down_left  = lbm_neighbor_rank_ex6(comm, -1, +1);
	const int down_right = lbm_neighbor_rank_ex6(comm, +1, +1);

	const int col_count = H * DIRECTIONS;

	MPI_Irecv(lbm_mesh_get_cell(mesh, 0,     0), col_count, MPI_DOUBLE, left,  0, comm->communicator, &comm->requests[0]);
	MPI_Irecv(lbm_mesh_get_cell(mesh, W - 1, 0), col_count, MPI_DOUBLE, right, 1, comm->communicator, &comm->requests[1]);
	MPI_Irecv(lbm_mesh_get_cell(mesh, 0, 0),     1, comm->type, up,   2, comm->communicator, &comm->requests[2]);
	MPI_Irecv(lbm_mesh_get_cell(mesh, 0, H - 1), 1, comm->type, down, 3, comm->communicator, &comm->requests[3]);

	MPI_Isend(lbm_mesh_get_cell(mesh, 1,     0), col_count, MPI_DOUBLE, left,  1, comm->communicator, &comm->requests[4]);
	MPI_Isend(lbm_mesh_get_cell(mesh, W - 2, 0), col_count, MPI_DOUBLE, right, 0, comm->communicator, &comm->requests[5]);
	MPI_Isend(lbm_mesh_get_cell(mesh, 0, 1),     1, comm->type, up,   3, comm->communicator, &comm->requests[6]);
	MPI_Isend(lbm_mesh_get_cell(mesh, 0, H - 2), 1, comm->type, down, 2, comm->communicator, &comm->requests[7]);

	MPI_Waitall(8, comm->requests, MPI_STATUSES_IGNORE);

	const int corner_count = DIRECTIONS;

	MPI_Irecv(lbm_mesh_get_cell(mesh, 0,     0),     corner_count, MPI_DOUBLE, up_left,    4, comm->communicator, &comm->requests[0]);
	MPI_Irecv(lbm_mesh_get_cell(mesh, W - 1, 0),     corner_count, MPI_DOUBLE, up_right,   5, comm->communicator, &comm->requests[1]);
	MPI_Irecv(lbm_mesh_get_cell(mesh, 0,     H - 1), corner_count, MPI_DOUBLE, down_left,  6, comm->communicator, &comm->requests[2]);
	MPI_Irecv(lbm_mesh_get_cell(mesh, W - 1, H - 1), corner_count, MPI_DOUBLE, down_right, 7, comm->communicator, &comm->requests[3]);

	MPI_Isend(lbm_mesh_get_cell(mesh, 1,     1),     corner_count, MPI_DOUBLE, up_left,    7, comm->communicator, &comm->requests[4]);
	MPI_Isend(lbm_mesh_get_cell(mesh, W - 2, 1),     corner_count, MPI_DOUBLE, up_right,   6, comm->communicator, &comm->requests[5]);
	MPI_Isend(lbm_mesh_get_cell(mesh, 1,     H - 2), corner_count, MPI_DOUBLE, down_left,  5, comm->communicator, &comm->requests[6]);
	MPI_Isend(lbm_mesh_get_cell(mesh, W - 2, H - 2), corner_count, MPI_DOUBLE, down_right, 4, comm->communicator, &comm->requests[7]);

	MPI_Waitall(8, comm->requests, MPI_STATUSES_IGNORE);
}