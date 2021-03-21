#include "sparse_vector.hpp"

/////////////////////////
// Node Class
////////////////////////
template<typename T>
Node<T>::Node()
{
	index = 0;
	value = 0;
	prev = nullptr;
	next = nullptr;
}

template<typename T>
Node<T>::~Node()
{
	index = 0;
	value = 0;
	prev = nullptr;
	next = nullptr;	
}

template<typename T>
void Node<T>::setValue(T val)
{
	value = val;
}

template<typename T>
void Node<T>::setIndex(size_t ind)
{
	index = ind;
}

template<typename T>
void Node<T>::setNextPtr(Node<T> *ptr)
{
	next = ptr;
}

template<typename T>
void Node<T>::setPrevPtr(Node<T> *ptr)
{
	prev = ptr;
}

template<typename T>
T Node<T>::getValue() const
{
	return value;
}

template<typename T>
size_t Node<T>::getIndex() const
{
	return index;
}

template<typename T>
Node<T>* Node<T>::getNextPtr() const
{
	return next;
}

template<typename T>
Node<T>* Node<T>::getPrevPtr() const
{
	return prev;
}

template<typename T>
void Node<T>::operator=(const T& val)
{
	setValue(val);
}


////////////////////////
//Sparse Vector Class
//////////////////////////
template<typename ItemType>
SparseVector<ItemType>::SparseVector(size_t size)
{
	maxSize = size;
	numNode = 0;
	headptr = nullptr;
	tailptr = nullptr;
}

template<typename ItemType>
SparseVector<ItemType>::~SparseVector()
{
	clear();
}

template<typename ItemType>
size_t SparseVector<ItemType>::length() const noexcept
{
	return maxSize;
}

template<typename ItemType>
size_t SparseVector<ItemType>::nodeLen() const noexcept
{
	return numNode;
}

template<typename ItemType>
bool SparseVector<ItemType>::isEmpty() const
{
	return (maxSize == 0);
}

template<typename ItemType>
void SparseVector<ItemType>::clear()
{
	maxSize = 0;
	numNode = 0;
	Node<ItemType> *first = headptr;
	Node<ItemType> *second;
	while(first != nullptr)
	{
		second = first->getNextPtr();
		delete first;
		first = second;
	}
	headptr = nullptr;
	tailptr = nullptr;
}

template<typename ItemType>
const ItemType& SparseVector<ItemType>::operator()(size_t index) const
{
	if (index<1 || index>maxSize )
	{
		throw std::invalid_argument("Invalid Index");
	}
	else
	{
		Node<ItemType>* temp;
		temp = getPointerToFromHead(index);
		if( temp == nullptr)
		{
			const ItemType& a = 0;
			return a;
		}
		else
		{
			const ItemType& b = temp->value;
			return b;
		}
		
		
	}
}

template<typename ItemType>
ItemType& SparseVector<ItemType>::operator()(size_t index)
{
	if (index<1 || index>maxSize )
	{
		throw std::invalid_argument("Invalid Index");
	}
	else
	{
		if(headptr == nullptr)
		{
			Node<ItemType>* temp = new Node<ItemType>;
			temp->setIndex(index);
			headptr = temp;
			tailptr = temp;
			temp = nullptr;
			numNode ++;	

			ItemType& ab = headptr->value;
			return ab;
		}
		else
		{
			Node<ItemType>* temp;
			temp = getPointerToFromHead(index);
			if(temp == nullptr)
			{
				numNode ++;
				Node<ItemType>* newBlock = new Node<ItemType>;
				newBlock->setIndex(index);
				tailptr->setNextPtr(newBlock);
				newBlock->setPrevPtr(tailptr);
				tailptr = newBlock;
				newBlock = nullptr;

				ItemType& ab = tailptr->value;
				return ab;
			}
			else
			{
				ItemType& ab = temp->value;
				return ab;
			}
		}
	}
}

template<typename ItemType>
Node<ItemType>* SparseVector<ItemType>::getPointerToFromHead(const size_t ind) const
{
	Node<ItemType>* temp = nullptr;
	if(ind <= 0 || ind > maxSize)
	{
		return temp;
	}
	else
	{
		temp = headptr;
		while(temp != nullptr)
		{
			if(temp->getIndex() == ind)
			{
				return temp;
			}
			else
			{
				temp = temp->getNextPtr();
			}
		}
		return temp;
	}
}

template<typename ItemType>
Node<ItemType>* SparseVector<ItemType>::getPointerToFromTail(const size_t ind) const
{
	Node<ItemType>* temp = nullptr;
	if(ind <= 0 || ind > maxSize)
	{
		return temp;
	}
	else
	{
		temp = tailptr;
		while(temp != nullptr)
		{
			if(temp->getIndex() == ind)
			{
				return temp;
			}
			else
			{
				temp = temp->getPrevPtr();
			}
		}
		return temp;
	}
}
