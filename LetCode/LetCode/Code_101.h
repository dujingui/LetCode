#pragma once

#include "Define.h"

//对称二叉树

//给定一个二叉树，检查它是否是镜像对称的。
//
//例如，二叉树 [1, 2, 2, 3, 4, 4, 3] 是对称的。
//
//   1
//  / \
// 2   2
/// \ / \
//3  4 4  3
//但是下面这个 [1, 2, 2, null, 3, null, 3] 则不是镜像对称的:
//
//  1
// / \
//2   2
//\   \
//3    3
//说明:
//
//如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/symmetric-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

bool _isSymmetry2(TreeNode* left, TreeNode* right) {
	if (left && right && left->val == right->val)
	{
		return _isSymmetry2(left->left, right->right) && _isSymmetry2(left->right, right->left);
	}

	if (left || right)
	{
		return false;
	}

	return true;
}

//递归法
bool isSymmetric2(TreeNode* root) {
	if (!root)
	{
		return true;
	}

	return _isSymmetry2(root->left, root->right);
}

//迭代法
bool isSymmetric(TreeNode* root) {
	if (!root)
	{
		return true;
	}

	stack<vector<TreeNode*>> sta;
	sta.push({ root->left, root->right });

	while (sta.size() > 0)
	{
		vector<TreeNode*> v = sta.top();
		sta.pop();

		if (v[0] && v[1] && v[0]->val == v[1]->val)
		{
			sta.push({ v[0]->left, v[1]->right });
			sta.push({ v[0]->right, v[1]->left });
			
		}
		else if(v[0] || v[1])
		{
			return false;
		}
	}
	return true;
}