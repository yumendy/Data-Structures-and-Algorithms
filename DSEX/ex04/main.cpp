#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, char const *argv[])
{
	BST F, result;
	cout << "正在从文件读取并创建二叉搜索树..." << endl;
	F = CreateBST();
	cout << "读取完毕..." << endl << "正在向文件输出排名前30%的记录" << endl;
	OutBST(F);
	cout << "已经将如下数据写入文件：" << endl;
	PrintResult();
	cout << "输入成绩查询姓名(输入负数结束查询)：" << endl;
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
			cout << "未找到分数为" << key << "的记录。" << endl;
		}
		cout << "输入成绩查询姓名(输入负数结束查询)：" << endl;
		cin >> key;
	}
}