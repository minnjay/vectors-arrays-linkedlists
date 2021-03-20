////////////////////////////////////////////////////////
// Minn-Jay Chok
//File Name: test_dense_vector.cpp
//Description: This is a test file for dense vector
//Date: 3/17/2021
///////////////////////////////////////////////
#include "catch.hpp"
#include "dense_vector.hpp"

TEST_CASE("Testing DenseVector Creation", "[regular functions]")
{
	DenseVector<int> b;
	REQUIRE(b.isEmpty() == true);
	REQUIRE(b.length() == 0);
	REQUIRE_THROWS_AS(b(-1), std::invalid_argument);
	REQUIRE_THROWS_AS(b(0), std::invalid_argument);
	REQUIRE_THROWS_AS(b(9), std::invalid_argument);
}

TEST_CASE("Testing DenseVector Adding", "[regular functions]")
{
	DenseVector<int> b;
	SECTION("Exception throwing and false addition")
	{
		REQUIRE(b.add(1, 2) == false);
		REQUIRE(b.add(1, 1) == true);
		REQUIRE(b.isEmpty() == false);
		REQUIRE(b.length() == 1);
		REQUIRE_THROWS_AS(b(-1), std::invalid_argument);
		REQUIRE_THROWS_AS(b(0), std::invalid_argument);
		REQUIRE_THROWS_AS(b(2), std::invalid_argument);
		REQUIRE(b(1) == 1);
		REQUIRE(b.add(1, 0) == false);
		REQUIRE(b.add(1, -2) == false);
		REQUIRE(b.add(1, 3) == false);
	}

	SECTION("Array Expansion and adding to the back")
	{
		REQUIRE(b.add(1, 1) == true);
		REQUIRE(b.add(6, 2) == true);
		REQUIRE(b.add(7, 3) == true);
		REQUIRE(b.add(8, 4) == true);
		REQUIRE(b.add(9, 5) == true);
		REQUIRE(b.add(10, 6) == true);
		REQUIRE(b.add(11, 7) == true);
		REQUIRE(b.add(12, 8) == true);
		REQUIRE(b.add(13, 9) == true);
		REQUIRE(b.add(15, 10) == true);
		REQUIRE(b.add(16, 11) == true);
		REQUIRE(b.add(2, 12) == true);
		REQUIRE(b.add(4, 13) == true);
		REQUIRE(b.add(6, 14) == true); // test dynamic array expansion

		REQUIRE(b(1) == 1);
		REQUIRE(b(2) == 6);
		REQUIRE(b(3) == 7);
		REQUIRE(b(4) == 8);
		REQUIRE(b(5) == 9);
		REQUIRE(b(6) == 10);
		REQUIRE(b(7) == 11);
		REQUIRE(b(8) == 12);
		REQUIRE(b(9) == 13);
		REQUIRE(b(10) == 15);
		REQUIRE(b(11) == 16);
		REQUIRE(b(12) == 2);
		REQUIRE(b(13) == 4);
		REQUIRE(b(14) == 6);  // test reading element
	}

	SECTION("Array Expansion and adding randomly")
	{

		REQUIRE(b.add(2, 1) == true);
		REQUIRE(b.add(1, 2) == true);
		REQUIRE(b.add(0, 3) == true);
		REQUIRE(b.add(5, 1) == true);
		REQUIRE(b.add(6, 2) == true);
		REQUIRE(b.add(7, 3) == true);

		REQUIRE(b(1) == 5);
		REQUIRE(b(2) == 6);
		REQUIRE(b(3) == 7);
		REQUIRE(b(4) == 2);
		REQUIRE(b(5) == 1);
		REQUIRE(b(6) == 0);		//  test add (insertion)
		REQUIRE(b.length() == 6);

		REQUIRE(b.add(100, 1) == true);
		REQUIRE(b(1) == 100);
	}

	SECTION("add_back  add_front")
	{
		b.clear();
		REQUIRE(b.isEmpty() == true);

		REQUIRE(b.add_front(100) == true);
		REQUIRE(b(1) == 100);

		REQUIRE(b.add_back(2) == true);
		REQUIRE(b.add_back(4) == true);
		REQUIRE(b.add_back(5) == true);
		REQUIRE(b.add_back(7) == true);
		REQUIRE(b(5) == 7);
	}

}

TEST_CASE("Testing DenseVector Replacing", "[regular functions]")
{
	DenseVector<int> b;

	b.add_front(1);
	b.add_front(2);
	b.add_front(3);
	b.add_front(4);
	REQUIRE(b.replace(1, 0) == false);
	REQUIRE(b.replace(1, -2) == false);
	REQUIRE(b.replace(1, 5) == false);

	REQUIRE(b(1) == 4);
	REQUIRE(b(2) == 3);
	REQUIRE(b(3) == 2);
	REQUIRE(b(4) == 1);

	REQUIRE(b.replace(1, 1) == true);
	REQUIRE(b.replace(2, 2) == true);
	REQUIRE(b.replace(3, 3) == true);
	REQUIRE(b.replace(4, 4) == true);

	REQUIRE(b(1) == 1);
	REQUIRE(b(2) == 2);
	REQUIRE(b(3) == 3);
	REQUIRE(b(4) == 4);

}

TEST_CASE("Testing DenseVector Removing", "[regular functions]")
{
	DenseVector<int> b;
	b.add_front(1);
	b.add_front(2);
	b.add_front(3);
	b.add_front(4);
	b.add_front(5);
	SECTION("remove_back()")
	{
		REQUIRE(b.remove_back() == true);
		REQUIRE(b(4) == 2);
		REQUIRE(b.remove_back() == true);
		REQUIRE(b(3) == 3);
		REQUIRE(b.remove_back() == true);
		REQUIRE(b(2) == 4);
		REQUIRE(b.remove_back() == true);
		REQUIRE(b(1) == 5);
		REQUIRE(b.length() == 1);
		REQUIRE(b.remove_back() == true);
		REQUIRE(b.remove_back() == false);
		REQUIRE(b.remove_back() == false);
	}

	SECTION("remove_front()")
	{
		REQUIRE(b.remove_front() == true);
		REQUIRE(b(1) == 4);
		REQUIRE(b.remove_front() == true);
		REQUIRE(b(1) == 3);
		REQUIRE(b.remove_front() == true);
		REQUIRE(b(1) == 2);
		REQUIRE(b.remove_front() == true);
		REQUIRE(b(1) == 1);
		REQUIRE(b.length() == 1);
		REQUIRE(b.remove_front() == true);
		REQUIRE(b.remove_front() == false);
		REQUIRE(b.remove_front() == false);
	}

	SECTION("remove randomly")
	{
		REQUIRE(b.remove(2) == true);
		REQUIRE(b(1) == 5);
		REQUIRE(b(2) == 3);
		REQUIRE(b.length() == 4);

		REQUIRE(b.remove(3) == true);
		REQUIRE(b(1) == 5);
		REQUIRE(b(2) == 3);
		REQUIRE(b(3) == 1);
		REQUIRE(b.length() == 3);
	}

}

TEST_CASE("Testing DenseVector operator= **deepcopy** ", "[regular functions]")
{
	DenseVector<int> a;
	REQUIRE(a.add_back(1) == true);
	REQUIRE(a.add_back(3) == true);
	REQUIRE(a.add_back(5) == true);
	REQUIRE(a.add_back(6) == true);
	REQUIRE(a.length() == 4);

	DenseVector<int> b;
	b = a;
	REQUIRE(b.length() == 4);
	REQUIRE(b(1) == 1);
	REQUIRE(b(2) == 3);
	REQUIRE(b(3) == 5);
	REQUIRE(b(4) == 6);

}