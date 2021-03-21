////////////////////////////////////////////////////////
// Minn-Jay Chok
//File Name: dense_vector.hpp
//Description: This is a hpp file for dense vector
//Date: 3/17/2021
///////////////////////////////////////////////

#ifndef DENSE_VECTOR_HPP
#define DENSE_VECTOR_HPP

#include "abstract_vector.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

// TODO
template<typename ItemType>
class DenseVector : public AbstractVector<ItemType>
{
private:
	size_t maxSize;
	size_t itemCount;
	ItemType *arrptr;

public:
	DenseVector(); // constructor
	bool add_back(const ItemType object);
	bool add_front(const ItemType object);
	bool remove_front();
	bool remove_back();
	bool add(const ItemType object, const size_t position);
	bool remove(const size_t position);
	bool replace(const ItemType object, const size_t position);

	size_t length() const noexcept;
	bool isEmpty() const;
	void clear();
	const ItemType& operator()(size_t index) const;
	ItemType& operator()(size_t index);

	DenseVector<ItemType>& operator=(const DenseVector<ItemType>& first);
	~DenseVector(); //  destructor

};

#include "dense_vector.tpp"

#endif


