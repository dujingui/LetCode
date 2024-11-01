#pragma once

#include "Define.h"

//938. 二叉搜索树的范围和
//
//给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。
//
//二叉搜索树保证具有唯一的值。
//
//
//
//示例 1：
//
//输入：root = [10, 5, 15, 3, 7, null, 18], L = 7, R = 15
//输出：32
//示例 2：
//
//输入：root = [10, 5, 15, 3, 7, 13, 18, 1, null, 6], L = 6, R = 10
//输出：23
//
//
//提示：
//
//树中的结点数量最多为 10000 个。
//最终的答案保证小于 2 ^ 31。

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