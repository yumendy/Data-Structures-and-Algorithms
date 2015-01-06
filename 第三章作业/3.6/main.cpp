#include <iostream>
#include "CSTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//测试用树：ABC#DEF#GH##I#####
	CSTREE T = NULL;
	CSTREE temp = NULL;
	char ch;
	CreateCST(T);
	cout << "请输入要查找的子树的关键字：";
	cin >> ch;
	temp = Find(ch, T);
	if (temp != NULL)
	{
		int n;
		cout << "请输入要查询的孩子节点的序号：";
		cin >> n;
		FindChild(temp, n);
	}
	else
	{
		cout << "没有找到所需查询的子树。" << endl;
	}
	return 0;
}