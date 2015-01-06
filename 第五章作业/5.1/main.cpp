#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, char const *argv[])
{
	BST F, result;
	cout << "正在从文件读取并创建二叉搜索树..." << endl;
	F = CreateBST();
	isBST(F);
	return 0;
}