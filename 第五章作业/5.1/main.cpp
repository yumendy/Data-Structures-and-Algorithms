#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, char const *argv[])
{
	BST F, result;
	cout << "���ڴ��ļ���ȡ����������������..." << endl;
	F = CreateBST();
	isBST(F);
	return 0;
}