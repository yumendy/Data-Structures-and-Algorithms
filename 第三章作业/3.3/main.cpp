#include <iostream>
#include "BTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//����������ABDH##I##E##CF##G##
	BTREE T = NULL;
	BTREE find = NULL;
	char keyword;
	cout << "���������뽨���Ķ�������" << endl;
	CreateBT(T);
	cout << "�����������ѯ˫�׽ڵ�Ľڵ�Ԫ�أ�" << endl;
	cin >> keyword;
	find = Parent(keyword,T);
	if (!find)
	{
		cout << "û���ҵ�" << keyword << "Ԫ�ء�" << endl;
	}
	else
	{
		cout << keyword << "��˫�׽ڵ��ǣ�" << find->data << endl;
	}
	return 0;
}