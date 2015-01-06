#include <iostream>
#include "BTREE.h"

#define MAXNUM 40

using namespace std;

int main(int argc, char const *argv[])
{
	//测试用树：ABCDEFGHI
	char T[MAXNUM];
	int n;
	cout << "请输入树的节点数： ";
	cin >> n;
	CreateBT(T, n);
	cout << "递归先序遍历并打印二叉树的节点：" << endl;
	PreOrder(T, n, 1);
	cout << endl;
	return 0;
}