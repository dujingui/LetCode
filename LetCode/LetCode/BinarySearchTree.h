#pragma once

#include "Define.h"

//二叉搜索树
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();

public:
	TreeNode*			MaxNode();
	TreeNode*			MinNode();
	TreeNode*			NextNode(TreeNode* pNode);
	TreeNode*			LastNode(TreeNode* pNode);
public:
	virtual bool		Insert(int nValue, bool bRecursion = true);
	virtual bool		Delete(int nValue);
	virtual TreeNode*	Search(int nValue, bool bRecursion = true);

	//前序遍历
	virtual void		PreOrder(bool bRecursion = true);
	//中序遍历(即从小到大输出)
	virtual void		InfixOrder(bool bRecursion = true);
	//后序遍历
	virtual void		PostOrder(bool bRecursion = true);
	//层次遍历(广度优先)
	virtual void		LevelOrder();

	virtual void		Print();
public:
	static TreeNode*	GetMaxNode(TreeNode* pRootNode);
	static TreeNode*	GetMinNode(TreeNode* pRootNode);
	static TreeNode*	GetLastNode(TreeNode* pRootNode, TreeNode* pNode);
	static TreeNode*	GetNextNode(TreeNode* pRootNode, TreeNode* pNode);
	static TreeNode*	GetParentNode(TreeNode* pRootNode, TreeNode* pNode);
private:
	bool		_RecursionInsert(TreeNode** ppNode, TreeNode* pNode, TreeNode* pParentNode);
	TreeNode*	_RecursionSearch(TreeNode* pNode, int nValue);
	void		_RecursionPreOrder(TreeNode* pRootNode);
	void		_RecursionInfixOrder(TreeNode* pRootNode);
	void		_RecursionPostOrder(TreeNode* pRootNode);
	bool		_Delete(TreeNode* pNode);
	void		_PreOrder(TreeNode* pRootNode);
	void		_InfixOrder(TreeNode* pRootNode);
	void		_PostOrder(TreeNode* pRootNode);
	void		_LevelOrder(TreeNode* pRootNode);
	void		_Print(TreeNode* pRootNode);
protected:
	TreeNode*	m_pRootNode;
};