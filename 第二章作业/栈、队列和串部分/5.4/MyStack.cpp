#include <iostream>
#include "MyStack.h"

using namespace std;

template <typename T>
MyStack <T>::MyStack(int n)
{
	size = n;
	top = -1;
	data = new T[n];
}

template <typename T>
MyStack <T>::~MyStack()
{
	delete data;
}

template <typename T>
bool MyStack <T>::push(const T &item)
{
	if (top < size - 1)
	{
		data[++top] = item;
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
bool MyStack <T>::pop(T &item)
{
	if (top > -1)
	{
		item = data[top--];
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
int MyStack <T>::stack_size() const
{
	return size;
}

template <typename T>
int MyStack <T>::stack_num() const
{
	return top + 1;
}

template <typename T>
void MyStack <T>::show() const
{
	if (top < 0)
	{
		cout << "***************" << endl;
		cout << "Stack is empty!" << endl;
		cout << "***************" << endl;
	}
	else
	{
		int temp = top;
		cout << "***************" << endl;
		while (temp >= 0)
		{
			cout << data[temp--] << endl;
		}
		cout << "***************" << endl;
	}
}

template <typename T>
T MyStack <T>::get_top_element() const
{
	return data[top];
}

template class MyStack < int > ;
template class MyStack < float > ;
template class MyStack < char >;
template class MyStack < double >;