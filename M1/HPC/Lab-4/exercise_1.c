/*****************************************************
    AUTHOR  : Sébastien Valat
    MAIL    : sebastien.valat@univ-grenoble-alpes.fr
    LICENSE : BSD
    YEAR    : 2021
    COURSE  : Parallel Algorithms and Programming
*****************************************************/

//////////////////////////////////////////////////////
//
//
// GOAL: Implement a 1D communication scheme along
//       X axis with blocking communications.
//
// SUMMARY:
//     - 1D splitting along X
//     - Blocking communications
//
//////////////////////////////////////////////////////

/****************************************************/
#include "src/lbm_struct.h"
#include "src/exercises.h"

/****************************************************/
void lbm_comm_init_ex1(lbm_comm_t * comm, int total_width, int total_height)
{
	int rank, comm_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);

	if (total_width % comm_size != 0) {
		fatal("total_width must be a multiple of the number of MPI processes !");
	}

	comm->nb_x = comm_size;
	comm->nb_y = 1;

	comm->rank_x = rank;
	comm->rank_y = 0;

	comm->width  = total_width  / comm->nb_x + 2;
	comm->height = total_height              + 2;

	comm->x = comm->rank_x * (total_width  / comm->nb_x);
	comm->y = 0;

	//if debug print comm
	//lbm_comm_print(comm);
}

/****************************************************/
void lbm_comm_ghost_exchange_ex1(lbm_comm_t * comm, lbm_mesh_t * mesh)
{
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int left  = (comm->rank_x > 0)              ? rank - 1 : MPI_PROC_NULL;
	int right = (comm->rank_x < comm->nb_x - 1) ? rank + 1 : MPI_PROC_NULL;

	const int count = comm->height * DIRECTIONS;

	const int TAG_TO_RIGHT = 0;
	const int TAG_TO_LEFT  = 1;

	MPI_Send(lbm_mesh_get_cell(mesh, comm->width - 2, 0), count, MPI_DOUBLE, right, TAG_TO_RIGHT, MPI_COMM_WORLD);
	MPI_Recv(lbm_mesh_get_cell(mesh, 0, 0), count, MPI_DOUBLE, left, TAG_TO_RIGHT, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	MPI_Send(lbm_mesh_get_cell(mesh, 1, 0), count, MPI_DOUBLE, left, TAG_TO_LEFT, MPI_COMM_WORLD);
	MPI_Recv(lbm_mesh_get_cell(mesh, comm->width - 1, 0), count, MPI_DOUBLE, right, TAG_TO_LEFT, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}
