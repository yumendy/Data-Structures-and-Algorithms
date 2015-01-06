#include <iostream>
#include "BTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//测试用树：ABDH##I##E##CF##G##
	BTREE T = NULL;
	char keyword;
	cout << "请输入你想建立的二叉树：" << endl;
	CreateBT(T);
	cout << "请输入你想删除的子树的关键字：" << endl;
	cin >> keyword;
	cout << "删除操作前的二叉树：" << endl;
	OutPutBTREE(T);

	if (T != NULL)
	{
		if (T->data == keyword)
		{
			FreeBT(T);
			delete T;
			T = NULL;
		}
		else
		{
			DeleteBT(keyword, T);
		}
	}
	cout << "删除操作后的二叉树：" << endl;
	OutPutBTREE(T);
	return 0;
}