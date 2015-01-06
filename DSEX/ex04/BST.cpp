#include "BST.h"
#include <iostream>
#include <fstream>

using namespace std;

void InsertBST(Record R, BST &F)
{
	if (F == NULL)
	{
		F = new BSTNode;
		F->data = R;
		F->lchild = NULL;
		F->rchild = NULL;
	}
	else if (R.score < F->data.score)
	{
		InsertBST(R, F->lchild);
	}
	else if (R.score > F->data.score)
	{
		InsertBST(R, F->rchild);
	}
}

BST CreateBST()
{
	BST F = NULL;
	Record R;
	int n;
	ifstream data("data.txt");
	data >> n;
	for (int i = 0; i < n; i++)
	{
		data >> R.name >> R.score;
		InsertBST(R, F);
	}
	data.close();
	return F;
}

BSTNode* SearchBST(int key, BST F)
{
	BSTNode *p = F;
	if (p == NULL || key == p->data.score)
	{
		return p;
	}
	else if (key < p->data.score)
	{
		return SearchBST(key, p->lchild);
	}
	else
	{
		return SearchBST(key, p->rchild);
	}
}

void OutBST(BST F)
{
	int num;
	ifstream data("data.txt");
	data >> num;
	data.close();
	num = (num * 0.3);
	Record stack[200];
	int top = -1;
	int count = 0;
	TraverseBST(F, stack, top);
	ofstream result("result.txt");
	int order = 1;
	while (num-- > 0)
	{
		result << order++ << " " << stack[top].name << " " << stack[top].score << endl;
		top--;
	}
	result.close();
}

void TraverseBST(BST F, Record stack[], int &top)
{
	if (F != NULL)
	{
		TraverseBST(F->lchild, stack, top);
		stack[++top] = F->data;
		TraverseBST(F->rchild, stack, top);
	}
}

void PrintResult()
{
	ifstream data("result.txt");
	int num, score;
	char name[20];
	while (data >> num && num != EOF)
	{
		data >> name >> score;
		cout << num << " " << name << " " << score << endl;
	}
	data.close();
}

Record deletemin(BST &F)
{
	Record temp; BST p;
	if (F->lchild == NULL)
	{
		p = F;
		temp = F->data;
		F = F->rchild;
		delete p;
		return temp;
	}
	else
	{
		return deletemin(F->lchild);
	}
}

void DeleteB(int key, BST &F)
{
	if (F != NULL)
	{
		if (key < F->data.score)
		{
			DeleteB(key, F->lchild);
		}
		else if (key > F->data.score)
		{
			DeleteB(key, F->rchild);
		}
		else
		{
			if (F->rchild == NULL)
			{
				F = F->lchild;
			}
			else if (F->lchild == NULL)
			{
				F = F->rchild;
			}
			else
			{
				F->data = deletemin(F->rchild);
			}
		}
	}
}