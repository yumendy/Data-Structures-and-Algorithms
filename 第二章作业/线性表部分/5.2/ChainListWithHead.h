#ifndef DS_HOMEWORK02_CHAINLISTWITHHEAD

#define DS_HOMEWORK02_CHAINLISTWITHHEAD

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//defintition
template<typename T>
class NodeItem
{
public:
	NodeItem(arguments);
	~NodeItem();

	/* data */
};

template<typename T>
class ChainList
{
public:
	ChainList(T element);
	// Purpose : Class constructor.

	~ChainList();
	// Purpose :Class destructor.

	void Insert(T element, int position);

	
};

#endif