#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, char const *argv[])
{
	BST F, result;
	cout << "���ڴ��ļ���ȡ����������������..." << endl;
	F = CreateBST();
	cout << "��ȡ���..." << endl << "�������ļ��������ǰ30%�ļ�¼" << endl;
	OutBST(F);
	cout << "�Ѿ�����������д���ļ���" << endl;
	PrintResult();
	cout << "����ɼ���ѯ����(���븺��������ѯ)��" << endl;
	int key;
	cin >> key;
	while (key > -1)
	{
		result = SearchBST(key, F);
		if (result != NULL)
		{
			cout << result->data.name << endl;
		}
		else
		{
			cout << "δ�ҵ�����Ϊ" << key << "�ļ�¼��" << endl;
		}
		cout << "����ɼ���ѯ����(���븺��������ѯ)��" << endl;
		cin >> key;
	}
}