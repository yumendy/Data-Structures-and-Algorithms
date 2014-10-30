#if !define DS_HOMEWORK02_LIST

#define DS_HOMEWORK02_LIST

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
//definition
template <typename T> class List;

template <typename T>
ostream& operator<<(ostream& os,const List<T>& list)
{
	if (list.size == -1)
	{
		os << "The list is empty!" << endl;
	}
	else
	{
		int temp;
		temp = list.size;
		os << "< ";
		for (int i = 0; i < list.last + 1; ++i)
		{
			os << list.elements[i] << " ";
		}
		os << ">\n";
	}
	return os;
}

template<typename T>
class List
{
	friend ostream&
	operator<< <T> (ostream& os, const List<T>& list);
public:
	List(int n = 50);
	// Purpose :Class constructor.
	// Parameters :Size of the list.

	~List();
	// Purpose :Class destructor.

	void Insert(T element, int position);
	// Purpose :Insert an element to the list.
	// Parameters : element - the element will be inserted.
	//				position - the position to insert the element.

	void Delete(int position);
	// Purpose :Delete an element in the list.
	// Parameters : position - the position of the element to delete.

	inline int Locate(T element) const;
	// Purpose :Find the locate of the element.
	// Parameters : element - the element to find.
	// Return : the locate of the element.
	//			if not found, return a new location.

	inline T Retrieve(int position) const;
	// Purpose :Retrieve the element.
	// Parameters : position - the position of the element to retrieve.
	// Return : the element be retrieved, if not found return the first element.

	inline int Previous(int position) const;
	// Purpose :Get the previous location of the position.
	// Parameters : position - the position you want to get the previous.
	// Return : previous location of the position, if invalid, return the location of a new element.

	inline int Next(int position) const;
	// Purpose :Get the next location of the position.
	// Parameters : position - the position you want to get the next.
	// Return : next location of the position, if invalid, return the location of a new element.
	inline int First() const;
	// Purpose :Get the location of the first element;
	// Return : the location of the first element, if the list is empty, return -1;

	inline int End() const;
	// Purpose :Get the location of the new element;
	// Return : the location of the last element, if the list is full, return -1;

private:
	T* elements;
	int last;
	int size;
};

//instantiation
template <typename T>
List <T>::List(int n)
{
	last = -1;
	size = n;
	elements = new T[n];
}

template <typename T>
List <T>::~List()
{
	delete elements;
}

template <typename T>
void List <T>::Insert(T element, int position)
{
	if (last >= size)
	{
		cout << "The List is full!" << endl;
		return;
	}
	else if (position < 0 || position > last + 1)
	{
		cout << "The position is invalid! You can insert between 0 and " << last + 1 << " ." << endl;
	}
	else
	{
		for (int i = last + 1; i > position; i--)
		{
			elements[i] = elements[i - 1];
		}
		elements[position] = element;
		last++;
	}
}

template <typename T>
void List <T>::Delete(int position)
{
	if (position < 0 || position > last)
	{
		cout << "The position is invalid!" << endl;
	}
	else
	{
		memcpy(elements + position, elements + position + 1, (last - position) * sizeof(elements[0]));
		last--;
	}
}

template <typename T>
int List <T>::Locate(T element) const
{
	for (int i = 0; i < last; ++i)
	{
		if (elements[i] == element)
		{
			return i;
		}
		return last + 1;
	}
}

template <typename T>
T List <T>::Retrieve(int position) const
{
	if (position < 0 || position > last)
	{
		cout << "The position is invalid!" << endl;
		return elements[0];
	}
	return elements[position];
}

template <typename T>
int List <T>::Previous(int position) const
{
	if (position < 1 || position > last + 1)
	{
		cout << "The position is invalid!" << endl;
		return last + 1;
	}
	return position - 1;
}

template <typename T>
int List <T>::Next(int position) const
{
	if (position < -1 || position >= last)
	{
		cout << "The next is invalid!" << endl;
		return last + 1;
	}
	return position + 1;
}

template <typename T>
int List <T>::First() const
{
	if (last == -1)
	{
		cout << "The list is empty!" << endl;
	}
	return last > -1 ? 0 : -1;
}

template <typename T>
int List <T>::End() const
{
	if (last == size - 1)
	{
		cout << "The list is full!" << endl;
	}
	return last == size - 1 ? -1 : last + 1;
}

#endif