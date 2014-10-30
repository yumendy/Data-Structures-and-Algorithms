#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "MyStack.h"

#define MAXSIZE_OF_EQUATION 100

using namespace std;

void PrintChoiceTable()
{
	cout << "================" << endl;
	cout << "1.Input the equation." << endl;
	cout << "2.Output the rpn of the equation." << endl;
	cout << "3.Caculate the result." << endl;
	cout << "4.Exit." << endl;
	cout << "================" << endl;
}

void ReadEquation(char *origin)
{
	cout << "Please input the equation:";
	cin >> origin;
	cout << "The Equation you input is: " << origin << endl;
}

bool isFloat(char *origin)
{
	for (int i = 0; i < strlen(origin); i++)
	{
		if (origin[i] == '.')
		{
			return true;
		}
	}
	return false;
}

void Caculate(char *rpn)
{
	bool is_float = isFloat(rpn);
	MyStack <int> int_stake(MAXSIZE_OF_EQUATION);
	int position = 0, i = 0;
	char temp[10];
	if (is_float)
	{
		MyStack <float> float_stake(MAXSIZE_OF_EQUATION);
		float num_temp, num_temp1, num_temp2;
		while (i < strlen(rpn))
		{
			if (rpn[i] >= '0' && rpn[i] <= '9')
			{
				position = i;
				while (rpn[i++] != ' ');
				memset(temp, 0, 10);
				memcpy(temp, rpn + position, i - position + 1);
				float_stake.push(atof(temp));
				i++;
			}
			else if (rpn[i] == ' ')
			{
				i++;
			}
			else
			{
				float_stake.pop(num_temp2);
				float_stake.pop(num_temp1);
				if (rpn[i] == '+')
				{
					num_temp = num_temp1 + num_temp2;
				}
				else if (rpn[i] == '-')
				{
					num_temp = num_temp1 - num_temp2;
				}
				else if (rpn[i] == '*')
				{
					num_temp = num_temp1 * num_temp2;
				}
				else if (rpn[i] == '/')
				{
					num_temp = num_temp1 / num_temp2;
				}
				float_stake.push(num_temp);
				i++;
			}
			float_stake.show();
		}
		cout << "The result of the equation is:" << float_stake.get_top_element() << endl;
	}
	else
	{
		MyStack <int> int_stake(MAXSIZE_OF_EQUATION);
		int num_temp, num_temp1, num_temp2;
		while (i < strlen(rpn))
		{
			if (rpn[i] >= '0' && rpn[i] <= '9')
			{
				position = i;
				while (rpn[i] != ' ')
					i++;
				memset(temp, 0, 10);
				memcpy(temp, rpn + position, i - position + 1);
				int_stake.push(atoi(temp));
				i++;
			}
			else if (rpn[i] == ' ')
			{
				i++;
			}
			else
			{
				int_stake.pop(num_temp2);
				int_stake.pop(num_temp1);
				if (rpn[i] == '+')
				{
					num_temp = num_temp1 + num_temp2;
				}
				else if (rpn[i] == '-')
				{
					num_temp = num_temp1 - num_temp2;
				}
				else if (rpn[i] == '*')
				{
					num_temp = num_temp1 * num_temp2;
				}
				else if (rpn[i] == '/')
				{
					num_temp = num_temp1 / num_temp2;
				}
				int_stake.push(num_temp);
				i++;
			}
			int_stake.show();
		}
		cout << "The result of the equation is:" << int_stake.get_top_element() << endl;
	}
}

int get_sign_priority(const char sign)
{
	if (sign == '+' || sign == '-')
	{
		return 1;
	}
	else if (sign == '*' || sign == '/')
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

void OutputRPN(char *origin,char *rpn)
{
	int position = 0;
	int top_priority = 0;
	char temp_sign;
	memset(rpn, 0, MAXSIZE_OF_EQUATION);
	MyStack <char> sign_stack(MAXSIZE_OF_EQUATION);
	for (int i = 0; i < strlen(origin); i++)
	{
		if ((origin[i] >= '0' && origin[i] <= '9') || origin[i] == '.')
		{
			rpn[position++] = origin[i];
		}
		else
		{
			if (origin[i] == '(')
			{
				sign_stack.push(origin[i]);
				top_priority = 0;
			}
			else if (origin[i] == ')')
			{
				rpn[position++] = ' ';
				sign_stack.pop(temp_sign);
				while (temp_sign != '(')
				{
					rpn[position++] = temp_sign;
					sign_stack.pop(temp_sign);
				}
				if (!sign_stack.stack_num())
				{
					top_priority = 0;
				}
				else
				{
					top_priority = get_sign_priority(sign_stack.get_top_element());
				}
			}
			else
			{
				if (rpn[position - 1] >= '0' && rpn[position - 1] <= '9')
				{
					rpn[position++] = ' ';
				}
				if (get_sign_priority(origin[i]) >= top_priority)
				{
					sign_stack.push(origin[i]);
					top_priority = get_sign_priority(origin[i]);
				}
				else
				{
					while (sign_stack.stack_num())
					{
						if (get_sign_priority(sign_stack.get_top_element()) >= get_sign_priority(origin[i]))
						{
							sign_stack.pop(temp_sign);
							rpn[position++] = temp_sign;
						}
						else
						{
							break;
						}
					}
					sign_stack.push(origin[i]);
					if (!sign_stack.stack_num())
					{
						top_priority = 0;
					}
					else
					{
						top_priority = get_sign_priority(sign_stack.get_top_element());
					}
				}
			}
			sign_stack.show();
		}
	}
	rpn[position++] = ' ';
	while (sign_stack.stack_num())
	{
		sign_stack.pop(rpn[position++]);
		sign_stack.show();
	}
	cout << "The rpn of the equation is: " << rpn << endl;
}

int main()
{
	char origin[MAXSIZE_OF_EQUATION];
	char rpn[MAXSIZE_OF_EQUATION];

	int choice;

	while (1)
	{
		PrintChoiceTable();
		cout << "Please choice function:";
		cin >> choice;
		switch (choice)
		{
			case(1) :
				ReadEquation(origin);
				break;
			case(2) :
				OutputRPN(origin, rpn);
				break;
			case(3) :
				Caculate(rpn);
				break;
			case(4) :
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