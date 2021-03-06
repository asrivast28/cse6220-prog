/**
 * @file    utils.h
 * @author  Patrick Flick <patrick.flick@gmail.com>
 * @brief   Implements common utility/helper functions.
 *
 * Copyright (c) 2014 Georgia Institute of Technology. All Rights Reserved.
 */

/*********************************************************************
 *             You can add new functions to this header.             *
 *********************************************************************/

#ifndef UTILS_H
#define UTILS_H

#include <mpi.h>

#include <limits>

/*********************************************************************
 * DO NOT CHANGE THE FUNCTION SIGNATURE OF THE FOLLOWING 3 FUNCTIONS *
 *********************************************************************/

inline int block_decompose(const int n, const int p, const int rank)
{
    return n / p + ((rank < n % p) ? 1 : 0);
}

inline int block_decompose(const int n, MPI_Comm comm)
{
    int rank, p;
    MPI_Comm_rank(comm, &rank);
    MPI_Comm_size(comm, &p);
    return block_decompose(n, p, rank);
}

inline int block_decompose_by_dim(const int n, MPI_Comm comm, int dim)
{
    // get dimensions
    int dims[2];
    int periods[2];
    int coords[2];
    MPI_Cart_get(comm, 2, dims, periods, coords);
    return block_decompose(n, dims[dim], coords[dim]);
}


/*********************************************************************
 *                  DECLARE YOUR OWN FUNCTIONS HERE                  *
 *********************************************************************/

// epsilon used for comparing double elements
const double DOUBLE_EPSILON = std::numeric_limits<double>::epsilon();

//subcommunicator for rows
inline MPI_Comm row_subcomm(MPI_Comm comm)
{
    MPI_Comm row_comm;
    int remain_dims[] = {0, 1};
    MPI_Cart_sub(comm, remain_dims, &row_comm);
    return row_comm;
}


//subcommunicator for columns
inline MPI_Comm col_subcomm(MPI_Comm comm)
{
    MPI_Comm col_comm;
    int remain_dims[] = {1, 0};
    MPI_Cart_sub(comm, remain_dims, &col_comm);
    return col_comm;
}

#endif // UTILS_H
