////////////////////////////////////////////////////////
// Minn-Jay Chok
//File Name: sparse_vector.hpp
//Description: This is a hpp file for sparse vector
//Date: 3/17/2021
///////////////////////////////////////////////

#ifndef SPARSE_VECTOR_HPP
#define SPARSE_VECTOR_HPP

#include "abstract_vector.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

template <typename T>
class Node
{
private:
	size_t index;
	Node<T> *prev;
	Node<T> *next;
public:
	T value;

	Node();
	~Node();
	void setValue(T val);
	void setIndex(size_t ind);
	void setNextPtr(Node<T> *ptr);
	void setPrevPtr(Node<T> *ptr);

	T getValue() const;
	size_t getIndex() const;
	Node<T>* getNextPtr() const;
	Node<T>* getPrevPtr() const;

	void operator=(const T& val);
};

template<typename ItemType>
class SparseVector : public AbstractVector<ItemType>
{
private:
	size_t numNode;
	size_t maxSize;
	Node<ItemType> *headptr;
	Node<ItemType> *tailptr;

public:
	SparseVector(size_t size);
	~SparseVector();

	size_t length() const noexcept;
	size_t nodeLen() const noexcept;
	bool isEmpty() const;
	void clear();

	const ItemType& operator()(size_t index) const;
	ItemType& operator()(size_t index);
	Node<ItemType>* getPointerToFromHead(const size_t ind) const;
	Node<ItemType>* getPointerToFromTail(const size_t ind) const;

};

#include "sparse_vector.tpp"

#endif
