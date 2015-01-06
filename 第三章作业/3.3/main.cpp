#include <iostream>
#include "BTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//测试用树：ABDH##I##E##CF##G##
	BTREE T = NULL;
	BTREE find = NULL;
	char keyword;
	cout << "请输入你想建立的二叉树：" << endl;
	CreateBT(T);
	cout << "请输入你想查询双亲节点的节点元素：" << endl;
	cin >> keyword;
	find = Parent(keyword,T);
	if (!find)
	{
		cout << "没有找到" << keyword << "元素。" << endl;
	}
	else
	{
		cout << keyword << "的双亲节点是：" << find->data << endl;
	}
	return 0;
}