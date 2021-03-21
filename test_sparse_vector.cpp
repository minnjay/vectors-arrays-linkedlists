////////////////////////////////////////////////////////
// Minn-Jay Chok
//File Name: test_sparse_vector.cpp
//Description: This is a test file for sparse vector
//Date: 3/17/2021
///////////////////////////////////////////////
#include "catch.hpp"
#include "sparse_vector.hpp"

TEST_CASE("Testing Node class before everything else", "[regular functions]")
{
	Node<int> n, left, right;
	n.setValue(6);
	n.setIndex(1);
	left.setValue(2);
	left.setIndex(2);
	right.setValue(7);
	right.setIndex(7);

	n.setNextPtr(&right);
	n.setPrevPtr(&left);

	REQUIRE(n.getIndex() == 1);
	REQUIRE(n.getValue() == 6);

	REQUIRE(n.getNextPtr()->getIndex() == 7);
	REQUIRE(n.getNextPtr()->getValue() == 7);

	REQUIRE(n.getPrevPtr()->getIndex() == 2);
	REQUIRE(n.getPrevPtr()->getValue() == 2);

	Node<int> test;

	test = 100;
	REQUIRE(test.getValue() == 100);
}


TEST_CASE("Testing SparseVector Creation", "[regular functions]")
{
	SparseVector<int> a(1000);
	REQUIRE(a.length() == 1000);
	REQUIRE(a.isEmpty() == false);
	REQUIRE(a.getPointerToFromHead(-3) == nullptr);
	REQUIRE(a.getPointerToFromHead(0) == nullptr);
	REQUIRE(a.getPointerToFromHead(56) == nullptr);
	REQUIRE(a.getPointerToFromHead(1003) == nullptr);

	REQUIRE(a.getPointerToFromTail(-3) == nullptr);
	REQUIRE(a.getPointerToFromTail(0) == nullptr);
	REQUIRE(a.getPointerToFromTail(56) == nullptr);
	REQUIRE(a.getPointerToFromTail(1003) == nullptr);
	a.clear();
	REQUIRE(a.length() == 0);
	REQUIRE(a.isEmpty() == true);

}

TEST_CASE("Testing SparseVector get pointer To after adding nodes", "[regular functions]")
{
	SparseVector<int> a(1000);
	REQUIRE_THROWS_AS(a(0), std::invalid_argument);
	REQUIRE_THROWS_AS(a(-3), std::invalid_argument);
	REQUIRE_THROWS_AS(a(1001), std::invalid_argument);
	REQUIRE(a.length() == 1000);
	REQUIRE(a.isEmpty() == false);
	REQUIRE(a.nodeLen() == 0);
	a(20) = 23;
	REQUIRE(a(20) == 23);
	REQUIRE(a.nodeLen() == 1);
	a(20) = 40;
	REQUIRE(a(20) == 40);
	REQUIRE(a.nodeLen() == 1);
	a(20) = 56;
	REQUIRE(a(20) == 56);
	REQUIRE(a.nodeLen() == 1);
	a(45) = 24;
	REQUIRE(a(45) == 24);
	REQUIRE(a.nodeLen() == 2);
	a(45) = 27;
	REQUIRE(a(45) == 27);
	REQUIRE(a.nodeLen() == 2);
	REQUIRE(a(20) == 56);
	a(46) = 46;
	a(42) = 42;
	a(49) = 49;
	a(37) = 37;
	REQUIRE(a(49) == 49);
	REQUIRE(a.nodeLen() == 6);
	a(49) = 0;
	REQUIRE(a(46) == 46);
	REQUIRE(a(42) == 42);
	REQUIRE(a(37) == 37);
	REQUIRE(a(49) == 0);
	a(42) = 90;
	a(46) = 91;
	REQUIRE(a(42) == 90);
	REQUIRE(a(46) == 91);
	REQUIRE(a(765) == 0);
}
