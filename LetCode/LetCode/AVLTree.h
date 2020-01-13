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


	//����ָ��pRootNode��ָ���Ϊ���Ķ���������ƽ����ת����
	void				LeftBalance(TreeNode* pRootNode);
	//����ָ��pRootNode��ָ���Ϊ���Ķ���������ƽ����ת����
	void				RightBalance(TreeNode* pRootNode);
private:
	//����pRootNodeΪ���Ķ�������������������
	//����֮��pRootNode�ĸ��ڵ�ָ��pRootNode����ڵ�
	//��������(˳ʱ����ת) ��ӦLL��
	//����תԭ����ȡʧȥƽ�����Լ����㣬Ϊ����lchild��Ϊ���ڵ㣬��lchild��rchild�ҽӵ�֮ǰ�����ϣ�Ȼ���ڹҽӵ�s->rchild.
	void				R_Rotate(TreeNode* pRootNode);

	//����pRootNodeΪ���Ķ�������������������
	//����֮��pRootNode�ĸ��ڵ�ָ��pRootNode���ҽڵ�
	//��������(��ʱ����ת) ��ӦRR��
	void				L_Rotate(TreeNode* pRootNode);	
};

