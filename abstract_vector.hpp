#ifndef ABSTRACT_VECTOR_HPP
#define ABSTRACT_VECTOR_HPP

// for std::size_t
#include <cstddef>

template<typename T>
class AbstractVector{
public:

  // return the length of the vector
  virtual std::size_t length() const noexcept = 0;

  // return a constant reference to the value at the given index
  // uses 1-based indexing
  // throws std::invalid_argument for invalid index 
  virtual const T& operator()(std::size_t index) const = 0;

  // return a reference to the value at the given index
  // uses 1-based indexing
  // throws std::invalid_argument for invalid index 
  virtual T& operator()(std::size_t index) = 0;
};

#endif
