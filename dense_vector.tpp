#include "dense_vector.hpp"

template<class ItemType>
DenseVector<ItemType>::DenseVector()
{
	maxSize = 5;
	itemCount = 0;
	arrptr = new ItemType[maxSize];
}

template<class ItemType>
bool DenseVector<ItemType>::add_back(const ItemType object)
{
	bool a = add(object, itemCount + 1);
	return a;
}

template<class ItemType>
bool DenseVector<ItemType>::add_front(const ItemType object)
{
	bool a = add(object, 1);
	return a;
}

template<class ItemType>
bool DenseVector<ItemType>::remove_front()
{
	bool a = remove(1);
	return a;
}

template<class ItemType>
bool DenseVector<ItemType>::remove_back()
{
	bool a = remove(itemCount);
	return a;
}

template<class ItemType>
bool DenseVector<ItemType>::add(const ItemType object, const size_t position)
{
	if (position<1 || position>itemCount + 1)
	{
		return false;
	}
	else
	{
		if (itemCount == maxSize)
		{
			maxSize += 2;
			ItemType *tempptr = new ItemType[maxSize];
			for (int a = 0; a < itemCount; ++a)
			{
				tempptr[a] = arrptr[a];
			}
			delete[] arrptr;
			arrptr = tempptr;
			tempptr = nullptr;
		}

		if (position != itemCount + 1)
		{
			for (int i = itemCount; i >= position; --i)
			{
				arrptr[i] = arrptr[i - 1];
			}
		}
		arrptr[position - 1] = object;
		itemCount++;
	}
	return true;
}

template<class ItemType>
bool DenseVector<ItemType>::remove(const size_t position)
{
	if (position<1 || position>itemCount)
	{
		return false;
	}
	else
	{
		if (position != itemCount)
		{
			for (int i = position; i<itemCount; ++i)
			{
				arrptr[i - 1] = arrptr[i];
			}
		}
		itemCount--;
	}
	return true;
}

template<class ItemType>
bool DenseVector<ItemType>::replace(const ItemType object, const size_t position)
{
	if (position<1 || position>itemCount)
	{
		return false;
	}
	else
	{
		arrptr[position - 1] = object;
		return true;
	}
}

template<class ItemType>
size_t DenseVector<ItemType>::length() const noexcept
{
	return itemCount;
}

template<class ItemType>
bool DenseVector<ItemType>::isEmpty() const
{
	return (itemCount == 0);
}

template<class ItemType>
void DenseVector<ItemType>::clear()
{
	itemCount = 0;
}

template<class ItemType>
const ItemType& DenseVector<ItemType>::operator()(size_t index) const
{
	if (index<1 || index>itemCount)
	{
		throw std::invalid_argument("Invalid Index");
	}
	else
	{
		const ItemType& item = arrptr[index - 1];
		return item;
	}
}

template<class ItemType>
ItemType& DenseVector<ItemType>::operator()(size_t index)
{
	if (index<1 || index>itemCount)
	{
		throw std::invalid_argument("Invalid Index");
	}
	else
	{
		ItemType& item = arrptr[index - 1];
		return item;
	}
}


template<class ItemType>
DenseVector<ItemType>& DenseVector<ItemType>::operator=(const DenseVector<ItemType>& first)
{
	if (&first != this)
	{
		size_t firstlen = first.length();
		for (size_t i = 1; i <= firstlen; ++i)
		{
			this->add_back(first(i));
		}
	}
	return *this;

}

template<class ItemType>
DenseVector<ItemType>::~DenseVector()
{
	maxSize = 0;
	itemCount = 0;
	delete[] arrptr;
	arrptr = nullptr;
}