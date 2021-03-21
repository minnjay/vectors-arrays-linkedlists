#include "linalg.hpp"

// compute the dot (inner) product of two vectors x . y
// throws std::invalid_argument of length(x) != length(y)
template<typename T>
T dot(const AbstractVector<T> & x, const AbstractVector<T> & y)
{
	T sum = 0;
	if(x.length() != y.length())
	{
		throw std::invalid_argument("Invalid Index");
	}
	else
	{
		size_t len = x.length();
		for(size_t i = 1; i<=len ; ++i)
		{
			sum += x(i)*y(i) ;
		}
		return sum;
	}
}

// compute the 1-norm (max absolute element) of a vector
template<typename T>
T norm1(const AbstractVector<T> & x)
{
	T sum = 0;
	for(size_t i = 1; i<= x.length(); ++i)
	{
		sum += abs(x(i));
	}
	return sum;
}

// compute the 2-norm (square root of the sum of elements squared) of a vector
template<typename T>
double norm2(const AbstractVector<T> & x)
{
	T sum = 0;
	double final;
	for(size_t i = 1; i<= x.length(); ++i)
	{
		sum += x(i)*x(i);
	}
	final = sqrt(sum);
	return final;

}

