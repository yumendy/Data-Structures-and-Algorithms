#include <iostream>
#include "MyStack.h"

int main(int argc, char const *argv[])
{
	long num;
	int base;
	int temp;
	bool not_empty;
	MyStack <int> stack(200);
	while(1)
	{
		cout << "Please input a num you want to switch(-1 to Exit):";
		cin >> num;
		if(num > -1)
		{
			cout << "Please input the base you want to switch: ";
			cin >> base;
			while(num > 0)
			{
				temp = num % base;
				stack.push(temp);
				num /= base;
			}
			cout << "The reseult is :";
			while(1)
			{
				not_empty = stack.pop(temp);
				if (not_empty)
				{
					cout << temp;
				}
				else
				{
					cout << endl;
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}