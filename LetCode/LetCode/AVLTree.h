#pragma once
#include "BinarySearchTree.h"

class AVLTree :
	public BinarySearchTree
{
public:
	AVLTree();
	~AVLTree();
public:
	virtual bool		Insert(int nValue, bool bRecursion = true);
	virtual bool		Delete(int nValue);
public:


	//对以指针pRootNode所指结点为根的二叉树作左平衡旋转处理
	void				LeftBalance(TreeNode* pRootNode);
	//对以指针pRootNode所指结点为根的二叉树作右平衡旋转处理
	void				RightBalance(TreeNode* pRootNode);
private:
	//对以pRootNode为根的二叉排序树做右旋处理
	//处理之后pRootNode的父节点指向pRootNode的左节点
	//右旋操作(顺时针旋转) 对应LL型
	//右旋转原理：获取失去平衡结点以及左结点，为了让lchild作为根节点，将lchild的rchild挂接到之前左结点上，然后在挂接到s->rchild.
	void				R_Rotate(TreeNode* pRootNode);

	//对以pRootNode为根的二叉排序树做左旋处理
	//处理之后pRootNode的父节点指向pRootNode的右节点
	//左旋操作(逆时针旋转) 对应RR型
	void				L_Rotate(TreeNode* pRootNode);	
};

