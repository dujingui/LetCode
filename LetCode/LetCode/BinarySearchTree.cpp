#include "pch.h"
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
}

BinarySearchTree::~BinarySearchTree()
{
}

bool BinarySearchTree::Insert(int nValue, bool bRecursion)
{
	TreeNode* pNode = new TreeNode(nValue);

	if (!m_pRootNode)
	{
		m_pRootNode = pNode;
		return true;
	}

	if (bRecursion)
		return _RecursionInsert(&m_pRootNode, pNode);

	if (nValue < m_pRootNode->val)
	{
		TreeNode** pTemp = &(m_pRootNode->left);

		while (*pTemp)
		{
			if (nValue < (*pTemp)->val)
			{
				pTemp = &((*pTemp)->left);
			}
			else
			{
				pTemp = &((*pTemp)->right);
			}
		}

		(*pTemp) = pNode;

		return true;
	}
	else
	{
		TreeNode** pTemp = &(m_pRootNode->right);

		while (*pTemp)
		{
			if (nValue < (*pTemp)->val)
			{
				pTemp = &((*pTemp)->left);
			}
			else
			{
				pTemp = &((*pTemp)->right);
			}
		}

		(*pTemp) = pNode;

		return true;
	}
}

bool BinarySearchTree::Delete(int nValue)
{
	return true;
}

TreeNode* BinarySearchTree::Search(int nValue, bool bRecursion = true)
{
	if (bRecursion)
		return _RecursionSearch(m_pRootNode, nValue);

	TreeNode* pRet = nullptr;

	TreeNode* pNode = m_pRootNode;
	while (pNode)
	{
		if (nValue == pNode->val)
			pRet = pNode;

		if (nValue < pNode->val)
			pNode = pNode->left;
		else
			pNode = pNode->right;
	}

	return pRet;
}

bool BinarySearchTree::_RecursionInsert(TreeNode** ppNode, TreeNode* pNode)
{
	if (*ppNode == nullptr)
	{
		*ppNode = pNode;
		return true;
	}

	if (pNode->val < (*ppNode)->val)
	{
		return _RecursionInsert(&(*ppNode)->left, pNode);
	}
	else
	{
		return _RecursionInsert(&(*ppNode)->right, pNode);
	}

	return false;
}

TreeNode* BinarySearchTree::_RecursionSearch(TreeNode* pNode, int nValue)
{
	if (!pNode)
	{
		return nullptr;

	}

	if (pNode->val == nValue)
		return pNode;
	else if (pNode->val > nValue)
		return _RecursionSearch(pNode->left, nValue);
	else 
		return _RecursionSearch(pNode->right, nValue);
}