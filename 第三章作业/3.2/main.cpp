#include <iostream>
#include "BTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//测试用树：ABDH##I##E##CF##G##
	BTREE T = NULL;
	cout << "请输入你想建立的二叉树：" << endl;
	CreateBT(T);
	cout << "后序非递归遍历二叉树并逆序输出：" << endl;
	PostOrder(T);
	cout << endl;
	return 0;
}