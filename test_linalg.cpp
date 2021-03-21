#include "catch.hpp"
#include "linalg.hpp"

// TODO

TEST_CASE("Testing dot product", "[regular functions]")
{
	DenseVector<int> a;
	SparseVector<int> b(4);
	SparseVector<int> c(7);
	a.add_back(1);
	a.add_back(0);
	a.add_back(0);
	a.add_back(-4);

	b(1) = 7;
	b(4) = -2;

	REQUIRE_THROWS_AS(dot<int>(a, c), std::invalid_argument);

	int sum;
	sum = dot<int>(a,b);
	REQUIRE(sum == 15);

}

TEST_CASE("Testing L1/L2 norm DenseVector", "[regular functions]")
{
	DenseVector<int> a;
	a.add_back(1);
	a.add_back(4);
	a.add_back(3);
	a.add_back(-4);
	int sum;
	sum = norm1(a);
	REQUIRE(sum == 12);
	a(4) = 0;
	sum = norm1(a);
	REQUIRE(sum == 8);
	a.remove_front();

	sum = norm1<int>(a);
	REQUIRE(sum == 7);

	double suml2;
	suml2 = norm2<int>(a);
	REQUIRE(suml2 == 5);

	DenseVector<int> empty;
	REQUIRE(norm2<int>(empty) == 0);
	REQUIRE(norm1<int>(empty) == 0);
}

TEST_CASE("Testing L1/L2 norm SparseVector", "[regular functions]")
{
	SparseVector<int> b(8);
	SparseVector<int> empty(0);
	b(2) = -3;
	
	b(7) = 4;

	int sum;
	double sum2;
	sum = norm1<int>(b);
	REQUIRE(sum == 7);
	sum2 = norm2<int>(b);
	REQUIRE(sum2 == 5);

	b(2) = 4;
	sum = norm1<int>(b);
	sum2 = norm2<int>(b);
	REQUIRE(sum == 8);


	REQUIRE_THROWS_AS(empty(-1), std::invalid_argument);
	REQUIRE_THROWS_AS(empty(0), std::invalid_argument);
	REQUIRE_THROWS_AS(empty(1), std::invalid_argument);
	REQUIRE_THROWS_AS(empty(2), std::invalid_argument);

	REQUIRE(norm2<int>(empty) == 0);
	REQUIRE(norm1<int>(empty) == 0);
}





