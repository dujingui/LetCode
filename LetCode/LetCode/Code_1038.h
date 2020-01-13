#pragma once

#include "Define.h"

//1038. 从二叉搜索树到更大和树
//
//给出二叉搜索树的根节点，该二叉树的节点值各不相同，修改二叉树，使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
//
//提醒一下，二叉搜索树满足下列约束条件：
//
//节点的左子树仅包含键小于节点键的节点。
//节点的右子树仅包含键大于节点键的节点。
//左右子树也必须是二叉搜索树。
//
//
//示例：
//
//
//输入：[4, 1, 6, 0, 2, 5, 7, null, null, null, 3, null, null, null, 8]
//输出：[30, 36, 21, 36, 35, 26, 15, null, null, null, 33, null, null, null, 8]
//
//
//提示：
//
//树中的节点数介于 1 和 100 之间。
//每个节点的值介于 0 和 100 之间。
//给定的树为二叉搜索树。

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