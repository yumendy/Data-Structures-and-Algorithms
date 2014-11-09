#include <iostream>

#define MAX 200

using namespace std;

//definition

struct List
{
	int type[MAX];
	double rates[MAX];
	int tail;
};

bool Check(int years, List *L, int &mark);

void Change(int years, List *L);

void Insert(List *L);

void PrintRatesList(List *L);

void Caculate(List *L);


void PrintChoiceTable()
{
	cout << "=============" << endl;
	cout << "1.Inseat an item" << endl;
	cout << "2.Change an item" << endl;
	cout << "3.Print the rate table" << endl;
	cout << "4.Caculate the sum" << endl;
	cout << "0.Exit" << endl;
	cout << "=============" << endl;
}

bool Check(int years, List *L, int &mark)
{
	mark = -1;
	for (int i = 0; i < L->tail; i++)
	{
		if (L->type[i] == years)
		{
			mark = i;
			return false;
		}
	}
	return true;
}

void Change(int years, List *L)
{
	int mark;
	if (!Check(years,L,mark))
	{
		cout << "Please input the rates of " << years << "years: ";
		cin >> L->rates[mark];
	}
	else
	{
		cout << "The item is not exist, do you want to add it?(Y/N): ";
		char choice;
		cin >> choice;
		if (choice == 'Y')
		{
			Insert(L);
		}
	}
}

void Insert(List *L)
{
	int years, mark;
	double rates;
	cout << "Please input the year of the item(0 for demand deposit):";
	cin >> years;
	if (!Check(years,L,mark))
	{
		cout << "The rates is already exist, do you want to change it?(Y/N): ";
		char choice;
		cin >> choice;
		if (choice == 'Y')
		{
			Change(years, L);
		}
	}
	else
	{
		cout << "Please input the rates of the item: ";
		cin >> rates;
		L->type[L->tail] = years;
		L->rates[L->tail] = rates;
		L->tail++;
	}
}

void PrintRatesList(List *L)
{
	cout << "\tYEARS\t\tRATES" << endl;
	for (int i = 0; i < L->tail; i++)
	{
		cout << "\t" << L->type[i] << "\t\t" << L->rates[i] << endl;
	}
}

void Caculate(List *L)
{
	int years, mark;
	double time, money;
	cout << "Please input the type of your deposit(0 for current):";
	cin >> years;
	if (!years)
	{
		if (Check(0,L,mark))
		{
			cout << "has no rates of current!" << endl;
			return;
		}
		else
		{
			cout << "Please input the money: ";
			cin >> money;
			cout << "Please input the time: ";
			cin >> time;
			cout << "Interest: " << time * L->rates[mark] * money << endl;
			cout << "Total: " << money + time * L->rates[mark] * money << endl;
		}
	}
	else
	{
		if (Check(years,L,mark))
		{
			cout << "Don't have this type!" << endl;
			return;
		}
		else
		{
			cout << "Please input the money: ";
			cin >> money;
			cout << "Interest: " << years * L->rates[mark] * money << endl;
			cout << "Total: " << money + years * L->rates[mark] * money << endl;
		}

	}
}

int main()
{
	int choice;
	List *L = new List;
	L->tail = 0;
	while (1)
	{
		PrintChoiceTable();
		cout << "Please select function: ";
		cin >> choice;
		switch (choice)
		{
			case(1) :
				Insert(L);
				break;
			case(2) :
				cout << "Please input the year you want to change: ";
				int years;
				cin >> years;
				Change(years, L);
				break;
			case(3) :
				PrintRatesList(L);
				break;
			case(4) :
				Caculate(L);
				break;
			default:
				cout << "Invalid choice!" << endl;
				break;
		}
	}
}