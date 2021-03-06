/**
 * @file    findmotifs.h
 * @author  Patrick Flick <patrick.flick@gmail.com>
 * @brief   Declares the sequential findmotifs function.
 *
 * Copyright (c) 2014 Georgia Institute of Technology. All Rights Reserved.
 */
// You DO NOT need to change anything in this file.
#ifndef FINDMOTIFS_H
#define FINDMOTIFS_H

#include <vector>
#include <stdint.h>

/// The datatype used for representing a (up to) 64 bit sequence.
typedef uint64_t bits_t;

/**
 * @brief   Solves the motif finding problem _sequentially_.
 *
 * @param n         The number of input sequences.
 * @param l         The length (in bits) of each input sequence.
 * @param d         The number of bits that are allowed to differ between
 *                  the answers and all input sequences.
 * @param input     An array of the `n` input sequences. Represented as
 *                  64 bit integers.
 *
 * @return          A std::vector containing all answers.
 */
std::vector<bits_t> findmotifs(unsigned int n, unsigned int l, unsigned int d,
                               const bits_t* input);

/**
 * @brief Explores the solution space obtained by flipping b bits in the given l bit number.
 *
 * @param n           The number of input sequences.
 * @param l           The length (in bits) of each input sequence.
 * @param d           The number of bits that are allowed to differ between
 *                    the answers and all input sequences.
 * @param input       An array of the `n` input sequences. Represented as
 *                    64 bit integers.
 * @param b           The maximum number of bits that can be flipped.
 * @param number      The candidate solution to be checked.
 * @param result      A vector which stores all the solutions.
 * @param currentidx  Current bit index in the number.
 * @param currentd    Number of bits that have been flipped in the number.
 */
void explore_solutions(const unsigned int n, const unsigned int l,
                       const unsigned int d, const bits_t* input,
                       const unsigned int b, const bits_t number,
                       std::vector<bits_t>& result,
                       unsigned int currentidx = 0, unsigned int currentd = 0);

#endif // FINDMOTIFS_H
