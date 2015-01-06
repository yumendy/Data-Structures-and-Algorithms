#include <iostream>
#include "BTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//测试用树：ABDH##I##E##CF##G##
	BTREE T = NULL;
	cout << "请输入你想建立的二叉树：" << endl;
	CreateBT(T);
	cout << "递归先序遍历并打印二叉树的叶子节点：" << endl;
	PreOrder(T);
	cout << endl;
	return 0;
}