#include <iostream>
#include "BTREE.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//����������ABDH##I##E##CF##G##
	BTREE T = NULL;
	char keyword;
	cout << "���������뽨���Ķ�������" << endl;
	CreateBT(T);
	cout << "����������ɾ���������Ĺؼ��֣�" << endl;
	cin >> keyword;
	cout << "ɾ������ǰ�Ķ�������" << endl;
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
	cout << "ɾ��������Ķ�������" << endl;
	OutPutBTREE(T);
	return 0;
}