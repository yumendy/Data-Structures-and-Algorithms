#include <iostream>
#include "CSTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//����������ABC#DEF#GH##I#####
	CSTREE T = NULL;
	CSTREE temp = NULL;
	char ch;
	CreateCST(T);
	cout << "������Ҫ���ҵ������Ĺؼ��֣�";
	cin >> ch;
	temp = Find(ch, T);
	if (temp != NULL)
	{
		int n;
		cout << "������Ҫ��ѯ�ĺ��ӽڵ����ţ�";
		cin >> n;
		FindChild(temp, n);
	}
	else
	{
		cout << "û���ҵ������ѯ��������" << endl;
	}
	return 0;
}