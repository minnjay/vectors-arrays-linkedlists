cmake_minimum_required(VERSION 3.9...3.19)
project(Project4 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# build test driver executable
add_executable(unit_tests catch.hpp unit_tests.cpp
  abstract_vector.hpp
  test_dense_vector.cpp dense_vector.hpp dense_vector.tpp
  test_sparse_vector.cpp sparse_vector.hpp sparse_vector.tpp
  linalg.hpp linalg.tpp test_linalg.cpp)


# enable testing
enable_testing()

# register Catch tests with cmake
include(Catch)
catch_discover_tests(unit_tests)
