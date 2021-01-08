#pragma once

#include "Define.h"

//938. �����������ķ�Χ��
//
//���������������ĸ���� root������ L �� R������֮������н���ֵ�ĺ͡�
//
//������������֤����Ψһ��ֵ��
//
//
//
//ʾ�� 1��
//
//���룺root = [10, 5, 15, 3, 7, null, 18], L = 7, R = 15
//�����32
//ʾ�� 2��
//
//���룺root = [10, 5, 15, 3, 7, 13, 18, 1, null, 6], L = 6, R = 10
//�����23
//
//
//��ʾ��
//
//���еĽ���������Ϊ 10000 ����
//���յĴ𰸱�֤С�� 2 ^ 31��

int rangeSumBST(TreeNode* root, int L, int R) {
	int nRet = 0;
	
	stack<TreeNode*> stack;

	while (stack.size() || root)
	{
		while (root)
		{
			stack.push(root);
			if (root->val < L)break;
			root = root->left;
		}

		if (stack.size() > 0)
		{
			root = stack.top();
			stack.pop();

			if (root->val < L)
				;
			else if (root->val > R)
				break;
			else 
				nRet += root->val;

			root = root->right;
		}
	}

	return nRet;
}

void test_938()
{
	cout << rangeSumBST(ConvertToBinarySearchTreeNode(vec), 7, 15);
}