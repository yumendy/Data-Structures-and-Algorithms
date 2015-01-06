#ifndef DS_HOMEWORK05_AVL

#define DS_HOMEWORK05_AVL

struct TreeNode
{
	struct TreeNode *left;
	struct TreeNode *right;
	int key;
};

bool isAVL(TreeNode *root, int depth);
//Ŀ�ģ��ж�һ�����ǲ���ƽ���������
//������ root - ָ��������ָ�롣
//		depth - ���ĸ߶ȡ�
//���أ� true - ��AVL����
//		false - ����AVL����

bool isBST(TreeNode *root);
//Ŀ�ģ��ж�һ�����ǲ���BST��
//������ root - ָ��������ָ�롣
//���أ� true - ��BST��
//		false - ����BST��

bool isBalance(TreeNode *root, int *depth);
//Ŀ�ģ��ж��Ƿ�ƽ�⡣
//������ root - ָ��������ָ�롣
//		depth - ���ĸ߶ȡ�
//���أ� true - ƽ�⡣
//		false - ��ƽ�⡣
#endif