#include "ChainList.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void PrintChoiceTable()
{
	cout << "================" << endl;
	cout << "1.Insert an element to the end." << endl;
	cout << "2.Insert an element to the first." << endl;
	cout << "3.Find an element in list." << endl;
	cout << "4.Insert an element after an element." << endl;
	cout << "5.Delete an element." << endl;
	cout << "6.Output the length of the list." << endl;
	cout << "7.Output the list." << endl;
	cout << "0.Exit." << endl;
	cout << "================" << endl;
}

int main(int argc, char const *argv[])
{
	int choice;
	int element;
	int position;
	int key;
	List *L = new List;
	L->first = NULL;
	cout << "The system has created an int list for you." << endl;
	while (1)
	{
		PrintChoiceTable();
		cout << "Please choice function:";
		cin >> choice;
		switch (choice)
		{
			case(1) :
				cout << "Please input an int you want to insert:";
				cin >> element;
				AddEnd(L, element);
				break;
			case(2) :
				cout << "Please input an int you want to insert:";
				cin >> element;
				AddFirst(L, element);
				break;
			case(3) :
				cout << "Please input the int you want to find:";
				cin >> element;
				if (Find(L, element, position) != NULL)
				{
					cout << "The element is No." << position << "element in the list." << endl;
				}
				else
				{
					cout << "Not found the node." << endl;
				}
				break;
			case(4) :
				cout << "Please input an int you want to insert:";
				cin >> element;
				cout << "Which element do you want to insert after:";
				cin >> key;
				Insert(L, key, element);
				break;
			case(5) :
				cout << "Please input an int you want to delete:";
				cin >> key;
				Delete(L, key);
				break;
			case(6) :
				cout << "The length of the list is " << Length(L) << endl;
				break;
			case(7) :
				Output(L);
				break;
			case(0) :
				goto STOP;
				break;
			default:
				cout << "Invalid choice!" << endl;
				break;
		}
	}
STOP:
	return 0;
}