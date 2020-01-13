#pragma once

#include "Define.h"

//1038. �Ӷ������������������
//
//���������������ĸ��ڵ㣬�ö������Ľڵ�ֵ������ͬ���޸Ķ�������ʹÿ���ڵ� node ����ֵ����ԭ���д��ڻ���� node.val ��ֵ֮�͡�
//
//����һ�£�������������������Լ��������
//
//�ڵ����������������С�ڽڵ���Ľڵ㡣
//�ڵ�������������������ڽڵ���Ľڵ㡣
//��������Ҳ�����Ƕ�����������
//
//
//ʾ����
//
//
//���룺[4, 1, 6, 0, 2, 5, 7, null, null, null, 3, null, null, null, 8]
//�����[30, 36, 21, 36, 35, 26, 15, null, null, null, 33, null, null, null, 8]
//
//
//��ʾ��
//
//���еĽڵ������� 1 �� 100 ֮�䡣
//ÿ���ڵ��ֵ���� 0 �� 100 ֮�䡣
//��������Ϊ������������

TreeNode* bstToGst2(TreeNode* root) {

	vector<int> vec;
	stack<TreeNode*> stack;

	TreeNode* pTemp = root;
	while (pTemp || stack.size() > 0)
	{
		while (pTemp)
		{
			stack.push(pTemp);
			pTemp = pTemp->left;
		}

		if (stack.size() > 0)
		{
			pTemp = stack.top();
			stack.pop();

			vec.push_back(pTemp->val);

			pTemp = pTemp->right;
		}
	}

	pTemp = root;
	while (pTemp || stack.size() > 0)
	{
		while (pTemp)
		{
			stack.push(pTemp);
			pTemp = pTemp->left;
		}

		if (stack.size() > 0)
		{
			pTemp = stack.top();
			stack.pop();

			int sum = 0;
			for (int i = vec.size() - 1; i >= 0; i--)
			{
				if (vec[i] < pTemp->val)
					break;

				sum += vec[i];
			}
			pTemp->val = sum;

			pTemp = pTemp->right;
		}
	}
	return root;
}

int _bstToGst(TreeNode* root,int val) {
	if (!root)
	{
		return val;
	}

	root->val += _bstToGst(root->right, val);

	return _bstToGst(root->left, root->val);
}

TreeNode* bstToGst(TreeNode* root) {
	_bstToGst(root, 0);
	return root;
}