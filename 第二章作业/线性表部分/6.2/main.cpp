#include "ChainList.h"

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void ADB_ShowAll(List *L)
{
	node *p = L->first;
	DATA temp;
	while(p != NULL)
	{
		temp = p->data;
		cout << "++++++++++++" << endl;
		cout << "name: " << temp.name << endl;
		cout << "address: " << temp.addr << endl;
		cout << "phone: " << temp.phone << endl;
		cout << "++++++++++++" << endl;
		p = p->next;
	}
}

List* ADB_Insert(List *L)
{
	DATA temp;
	cout << "Please input the info of the poeple." << endl;
	cout << "name: ";
	cin >> temp.name;
	cout << "address: ";
	cin >> temp.addr;
	cout << "phone: ";
	cin >> temp.phone;
	L->first = AddFirst(L, temp);
	return L;
}

void ADB_Find(List *L)
{
	node *h;
	DATA temp;
	char name[15];
	cout << "Please input the name: ";
	cin >> name;
	h = Find(L, name);
	if (h != NULL)
	{
		temp = h->data;
		cout << "name: " << temp.name << endl;
		cout << "address: " << temp.addr << endl;
		cout << "phone: " << temp.phone << endl;
	}
	else
	{
		cout << "Not found!";
	}
}

void ADB_Delete(List *L)
{
	char name[15];
	cout << "Please input the name you want to delete:";
	cin >> name;
	Delete(L, name);
}

void PrintChoiceTable()
{
	cout << "============" << endl;
	cout << "1.Add an item." << endl;
	cout << "2.Find an item" << endl;
	cout << "3.Delete an item" << endl;
	cout << "4.Show all the item" << endl;
	cout << "0.Exit" << endl;
	cout << "============" << endl;
}

int main(int argc, char const *argv[])
{
	List *L = new List;
	L->first = NULL;
	L->size = 0;
	int select;
	while (1)
	{
		PrintChoiceTable();
		cin >> select;
		switch (select)
		{
			case(1) :
				cout << "Add Item" << endl;
				L = ADB_Insert(L);
				break;
			case(2) :
				cout << "Find Item" << endl;
				ADB_Find(L);
				break;
			case(3) :
				cout << "Delete Item" << endl;
				ADB_Delete(L);
				break;
			case(4) :
				cout << "Show All Item" << endl;
				ADB_ShowAll(L);
				break;
			case(0) :
				return 0;
			default:
				cout << "Invalid choice!" << endl;
				break;
		}
	}
	return 0;
}