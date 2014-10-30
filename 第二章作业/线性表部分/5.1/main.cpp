#include "List.h"

#ifndef MAXSIZE_OF_LIST
#define MAXSIZE_OF_LIST 100
#endif
using namespace std;

void PrintChoiceTable()
{
	cout << "================" << endl;
	cout << "1.Insert an element." << endl;
	cout << "2.Delete an element." << endl;
	cout << "3.Find an element in list." << endl;
	cout << "4.Retrieve an element in list." << endl;
	cout << "5.Get the previous location of an element." << endl;
	cout << "6.Get the next location of an element." << endl;
	cout << "7.Get the location of the first element." << endl;
	cout << "8.Get the location of the last element." << endl;
	cout << "9.Output the list." << endl;
	cout << "0.Exit." << endl;
	cout << "================" << endl;
}



int main(int argc, char const *argv[])
{
	int choice;
	int size;
	int element;
	int position;
	int temp;
	cout << "Please input the size of the list:";
	cin >> size;
	List <int> list(size);
	cout << "The system has created an int list for you. The size is " << size << " ." << endl;

	while(1)
	{
		PrintChoiceTable();
		cout << "Please choice function:";
		cin >> choice;
		switch(choice)
		{
			case(1) :
				cout << "Please input the element you want to insert:";
				cin >> element;
				cout << "Please input the location you want to insert:";
				cin >> position;
				list.Insert(element, position);
				break;
			case(2) :
				cout << "Please input the position of the element you want to delete:";
				cin >> position;
				list.Delete(position);
				break;
			case(3) :
				cout << "Please input the element you want to find:";
				cin >> element;
				position = list.Locate(element);
				cout << "The position of " << element << " is " << position << "." << endl;
				break;
			case(4) :
				cout << "Please input the position of the element you want to retrieve:";
				cin >> position;
				element = list.Retrieve(position);
				cout << "The element you retrieve is " << element << "." << endl;
				break;
			case(5) :
				cout << "Please input the position of element you want to get previous:";
				cin >> position;
				temp = list.Previous(position);
				cout << "The previous of " << position << " is " << temp << endl;
				break;
			case(6) :
				cout << "Please input the position of element you want to get next:";
				cin >> position;
				temp = list.Next(position);
				cout << "The previous of " << position << " is " << temp << endl;
				break;
			case(7) :
				if (list.First() != -1)
				{
					cout << "The location of the first element is " << list.First() << "." << endl;
				}
				break;
			case(8) :
				if (list.End() != -1)
				{
					cout << "The location of the last element is " << list.End() << "." << endl;
				}
				break;
			case(9) :
				cout << list;
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