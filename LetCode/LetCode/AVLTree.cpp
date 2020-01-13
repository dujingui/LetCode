#include "pch.h"
#include "AVLTree.h"


AVLTree::AVLTree()
{
}


AVLTree::~AVLTree()
{
}

bool AVLTree::Insert(int nValue, bool bRecursion = true)
{

}

bool AVLTree::Delete(int nValue)
{

}

void AVLTree::LeftBalance(TreeNode* pRootNode)
{
	TreeNode* pLeftNode = pRootNode->left;
	TreeNode* pLeftRightNode = nullptr;

	/* ���pRootNode����������ƽ��ȣ�������Ӧƽ�⴦�� */
	switch (pLeftNode->bf)
	{
		//�½�������T�����ӵ��������ϣ�Ҫ������������
		case TREE_LH:
		{
			pRootNode->bf = pLeftNode->bf = TREE_EH;
			R_Rotate(pRootNode);
			break;
		}
		//�½�������T�����ӵ��������ϣ�Ҫ��˫������
		case TREE_RH:
		{
			pLeftRightNode = pLeftNode->right;
			switch (pLeftRightNode->bf)
			{
				case TREE_LH:
				{
					pRootNode->bf = TREE_RH;
					pLeftNode->bf = TREE_EH;
					break;
				}
				case TREE_EH:
				{
					pRootNode->bf = TREE_EH;
					pLeftNode->bf = TREE_EH;
					break;
				}
				case TREE_RH:
				{
					pRootNode->bf = TREE_EH;
					pLeftNode->bf = TREE_LH;
					break;
				}
			}
			pLeftRightNode->bf = TREE_EH;
			//��T��������������ƽ�⴦��
			L_Rotate(pRootNode->left);
			//��T������ƽ�⴦��
			R_Rotate(pRootNode);
			break;
		}
		//�������4,������������ʱ�����ܳ��֣�ֻ���Ƴ�ʱ���ܳ��֣���ת֮���������߲���
		case TREE_EH:
		{
			pRootNode->bf = TREE_LH;
			pLeftNode->bf = TREE_RH;
			R_Rotate(pRootNode);
			break;
		}
	}
}

void AVLTree::RightBalance(TreeNode* pRootNode)
{
	if (!pRootNode)
	{
		return;
	}

	TreeNode* pRightNode = pRootNode->right;
	if (!pRightNode)
	{
		return;
	}

	switch (pRightNode->bf)
	{
		//�½ڵ������ڵ���ҽڵ����������,��RR��,����������
		case TREE_RH:
		{
			pRootNode->bf	= TREE_EH;
			pRightNode->bf	= TREE_EH;

			L_Rotate(pRootNode);

			break;
		}
		//�½ڵ������ڵ���ҽڵ����������,��RL�ͣ�����ƽ�⴦��(������������)
		case TREE_LH:
		{
			TreeNode* pRightLeftNode = pRightNode->left;
			switch (pRightLeftNode->bf)
			{
				case TREE_LH:
				{
					pRootNode->bf			= TREE_EH;
					pRightNode->bf			= TREE_EH;
					pRightLeftNode->bf		= TREE_LH;
					break;
				}
				case TREE_RH:
				{
					pRootNode->bf			= TREE_EH;
					pRightNode->bf			= TREE_RH;
					pRightLeftNode->bf		= TREE_EH;
					break;
				}
				case TREE_EH:
				{
					pRootNode->bf			= TREE_EH;
					pRightNode->bf			= TREE_EH;
					pRightLeftNode->bf		= TREE_EH;
					break;
				}
				default:
					break;
			}

			R_Rotate(pRightNode);
			L_Rotate(pRootNode);

			break;
		}
		//����ڵ㲻������������� ֻ��ɾ���ڵ������������
		case TREE_EH:
		{
			pRootNode->bf = TREE_RH;
			pRightNode->bf = TREE_LH;

			L_Rotate(pRootNode);
			break;
		}
		default:
			break;
	}
}

void AVLTree::R_Rotate(TreeNode* pRootNode)
{
	if (!pRootNode)
		return;

	TreeNode* pLeftNode		= pRootNode->left;
	TreeNode* pParentNode	= BinarySearchTree::GetParentNode(m_pRootNode, pRootNode);

	//�����ڵ����ڵ�ָ����ڵ���ڵ���ҽڵ�
	pRootNode->left			= pLeftNode->right;
	if (pLeftNode->right)
		pLeftNode->right->parent = pRootNode;


	pLeftNode->right	= pRootNode;
	pLeftNode->parent	= pParentNode;
	pRootNode->parent	= pLeftNode;

	if (!pParentNode)
		//˵��pRootNode�����ĸ��ڵ�
		m_pRootNode = pRootNode;
	else if (pParentNode->left == pRootNode)
		pParentNode->left = pLeftNode;
	else
		pParentNode->right = pLeftNode;
}

void AVLTree::L_Rotate(TreeNode* pRootNode)
{
	if (!pRootNode)
		return;

	TreeNode* pRightNode	= pRootNode->right;
	TreeNode* pParentNode	= BinarySearchTree::GetParentNode(m_pRootNode, pRootNode);

	pRootNode->right = pRightNode->left;
	if (pRightNode->left)
		pRightNode->left->parent = pRootNode;

	pRightNode->left = pRootNode;
	pRightNode->parent = pParentNode;
	pRootNode->parent = pRightNode;

	if (!pParentNode)
		m_pRootNode = pRightNode;
	else if (pParentNode->left == pRootNode)
		pParentNode->left = pRightNode;
	else
		pParentNode->right = pRightNode;
}