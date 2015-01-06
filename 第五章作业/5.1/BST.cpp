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

void TraverseBST(BST F, Record stack[], int &top)
{
	if (F != NULL)
	{
		TraverseBST(F->lchild, stack, top);
		stack[++top] = F->data;
		TraverseBST(F->rchild, stack, top);
	}
}

void isBST(BST F)
{
	Record stack[200];
	int top = -1;
	int temp_score;
	TraverseBST(F, stack, top);
	int flag = 1;
	temp_score = stack[top].score;
	top--;
	while (top != -1)
	{
		if (stack[top].score <= temp_score)
		{
			temp_score = stack[top].score;
			top--;
		}
		else
		{
			flag = 0;
			cout << "²»ÊÇ¶þ²æÅÅÐòÊ÷" << endl;
			break;
		}
	}
	if (flag)
	{
		cout << "ÊÇ¶þ²æÅÅÐòÊ÷" << endl;
	}
}