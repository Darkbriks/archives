/*****************************************************
    AUTHOR  : Sébastien Valat
    MAIL    : sebastien.valat@univ-grenoble-alpes.fr
    LICENSE : BSD
    YEAR    : 2021
    COURSE  : Parallel Algorithms and Programming
*****************************************************/

//////////////////////////////////////////////////////
//
// Goal: Implement odd/even 1D blocking communication scheme 
//       along X axis.
//
// SUMMARY:
//     - 1D splitting along X
//     - Blocking communications
// NEW:
//     - >>> Odd/even communication ordering <<<<
//
//////////////////////////////////////////////////////

/****************************************************/
#include "src/lbm_struct.h"
#include "src/exercises.h"

/****************************************************/
void lbm_comm_init_ex2(lbm_comm_t * comm, int total_width, int total_height)
{
	//we use the same implementation then ex1
	lbm_comm_init_ex1(comm, total_width, total_height);
}

/****************************************************/
void lbm_comm_ghost_exchange_ex2(lbm_comm_t * comm, lbm_mesh_t * mesh)
{
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	const int left  = (comm->rank_x > 0)              ? rank - 1 : MPI_PROC_NULL;
	const int right = (comm->rank_x < comm->nb_x - 1) ? rank + 1 : MPI_PROC_NULL;

	const int count = comm->height * DIRECTIONS;

	constexpr int TAG_TO_RIGHT = 0;
	constexpr int TAG_TO_LEFT  = 1;

	const int is_even = (comm->rank_x % 2 == 0);

	if (is_even) {
		MPI_Recv(lbm_mesh_get_cell(mesh, 0, 0), count, MPI_DOUBLE, left,  TAG_TO_RIGHT, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Send(lbm_mesh_get_cell(mesh, comm->width - 2, 0), count, MPI_DOUBLE, right, TAG_TO_RIGHT, MPI_COMM_WORLD);
	} else {
		MPI_Send(lbm_mesh_get_cell(mesh, comm->width - 2, 0), count, MPI_DOUBLE, right, TAG_TO_RIGHT, MPI_COMM_WORLD);
		MPI_Recv(lbm_mesh_get_cell(mesh, 0, 0), count, MPI_DOUBLE, left,  TAG_TO_RIGHT, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}

	if (is_even) {
		MPI_Recv(lbm_mesh_get_cell(mesh, comm->width - 1, 0), count, MPI_DOUBLE, right, TAG_TO_LEFT, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		MPI_Send(lbm_mesh_get_cell(mesh, 1, 0), count, MPI_DOUBLE, left,  TAG_TO_LEFT, MPI_COMM_WORLD);
	} else {
		MPI_Send(lbm_mesh_get_cell(mesh, 1, 0), count, MPI_DOUBLE, left,  TAG_TO_LEFT, MPI_COMM_WORLD);
		MPI_Recv(lbm_mesh_get_cell(mesh, comm->width - 1, 0), count, MPI_DOUBLE, right, TAG_TO_LEFT, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
}
