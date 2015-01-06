#include "Graph.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	MTGraph *MT = NULL;
	MT = new MTGraph();
	CreateMTGraph(MT);
	Prim(MT->edge, MT->n);
	return 0;
}