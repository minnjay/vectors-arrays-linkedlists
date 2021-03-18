#ifndef LINALG_HPP
#define LINALG_HPP

#include "abstract_vector.hpp"
#include "dense_vector.hpp"
#include "sparse_vector.hpp"

// compute the dot (inner) product of two vectors x . y
// throws std::invalid_argument of length(x) != length(y)
template<typename T>
T dot(const AbstractVector<T> & x, const AbstractVector<T> & y);

// compute the 1-norm (max absolute element) of a vector
template<typename T>
T norm1(const AbstractVector<T> & x);

// compute the 2-norm (square root of the sum of elements squared) of a vector
template<typename T>
double norm2(const AbstractVector<T> & x);

#include "linalg.tpp"

#endif
