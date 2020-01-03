#pragma once

#include "Define.h"

//¶þ²æËÑË÷Ê÷
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

public:
	bool		Insert(int nValue, bool bRecursion = true);
	bool		Delete(int nValue);
	TreeNode*	Search(int nValue, bool bRecursion = true);
private:
	bool		_RecursionInsert(TreeNode** ppNode, TreeNode* pNode);
	TreeNode*	_RecursionSearch(TreeNode* pNode, int nValue);
private:
	TreeNode* m_pRootNode;
};