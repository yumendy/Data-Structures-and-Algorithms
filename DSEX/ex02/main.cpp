#include "BTREE.h"

void PrintTable()
{
	cout << "==============" << endl;
	cout << "1.Show the general list of the tree." << endl;
	cout << "2.Pre order to travel a tree(recurrence method)." << endl;
	cout << "3.Pre order to travel a tree(not recurrence method)." << endl;
	cout << "4.In order to travel a tree(recurrence method)." << endl;
	cout << "5.In order to travel a tree(not recurrence method)." << endl;
	cout << "6.Post order to travel a tree(recurrence method)." << endl;
	cout << "7.Post order to travel a tree(not recurrence method)." << endl;
	cout << "8.Lever order to travel a tree." << endl;
	cout << "9.In order to threading a tree." << endl;
	cout << "10. Pre order next element to some element." << endl;
	cout << "11. In order next element to some element." << endl;
	cout << "12. Post order next element to some element." << endl;
	cout << "13. In order travel the threading tree." << endl;
	cout << "0.Exit." << endl;
	cout << "==============" << endl;

}

int main(int argc, char const *argv[])
{
	BTREE T = NULL;
	BTREE InHEAD = NULL;
	BTREE TT = NULL;
	struct node *pre = NULL;
	char element;
	BTREE temp = NULL;

	int choice;
START:
	cout << "==============" << endl;
	cout << "1.Create a BTREE with pre order." << endl;
	cout << "2.Create a BTREE with level order." << endl;
	cout << "==============" << endl;
	cout << "Please input your choice: ";
	cin >> choice;
	getchar();
	if (choice == 1)
	{
		cout << "Please input the BTREE you want to build: " << endl;
		CreateBT1(T);
	}
	else if (choice == 2)
	{
		cout << "Please input the BTREE you want to build: " << endl;
		struct node* s[100];
		T = CreateBT2(s);
	}
	else
	{
		cout << "Invalid choice!" << endl;
		goto START;
	}
	TT = CopyBTREE(T);
	InOrderThreading(InHEAD, TT, pre);
	while(1)
	{
		PrintTable();
		cout << "Please input your choice: ";
		cin >> choice;
		switch(choice)
		{
			case(1) :
				cout << "The general list of the tree is :" << endl;
				OutPutBTREE(T);
				break;
			case(2) :
				cout << "Pre order to travel the tree(recurrence method): " << endl;
				PreOrder1(T);
				cout << endl;
				break;
			case(3) :
				cout << "Pre order to travel the tree(not recurrence method): " << endl;
				PreOrder2(T);
				cout << endl;
				break;
			case(4) :
				cout << "In order to travel the tree(recurrence method): " << endl;
				InOrder1(T);
				cout << endl;
				break;
			case(5) :
				cout << "Pre order to travel the tree(not recurrence method): " << endl;
				InOrder2(T);
				cout << endl;
				break;
			case(6) :
				cout << "Post order to travel the tree(recurrence method): " << endl;
				PostOrder1(T);
				cout << endl;
				break;
			case(7) :
				cout << "Post order to travel the tree(not recurrence method): " << endl;
				PostOrder2(T);
				cout << endl;
				break;
			case(8) :
				cout << "Lever order to travel the tree: " << endl;
				LeverOrder(T);
				cout << endl;
				break;
			case(9) :
				cout << "In order to threading a tree:" << endl;
				cout << '(';
				OutPutBTREE2(InHEAD->lchild, InHEAD->lTag);
				cout << ')' << endl;
				break;
			case(10) :
				cout << "Please input the element you want to get the next: ";
				cin >> element;
				temp = PreOrderNext(Location(element,InHEAD));
				if (temp->data != 0)
				{
					cout << "The pre order next element is :" << temp->data << "." << endl;
				}
				else
				{
					cout << "The pre order next element is header node." << endl;
				}
				break;
			case(11) :
				cout << "Please input the element you want to get the next: ";
				cin >> element;
				temp = InOrderNext(Location(element,InHEAD));
				if (temp->data != 0)
				{
					cout << "The in order next element is :" << temp->data << "." << endl;
				}
				else
				{
					cout << "The in order next element is header node." << endl;
				}
				break;
			case(12) :
				cout << "Please input the element you want to get the next: ";
				cin >> element;
				temp = PostOrderNext(Location(element,InHEAD),InHEAD);
				if (temp->data != 0)
				{
					cout << "The in order next element is :" << temp->data << "." << endl;
				}
				else
				{
					cout << "The in order next element is header node." << endl;
				}
				break;
			case(13) :
				cout <<"In order travel the threading tree" << endl;
				ThInOrder(InHEAD);
				cout << endl;
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