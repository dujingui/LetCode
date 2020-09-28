#include "pch.h"
#include "AVLTree.h"


AVLTree::AVLTree()
{
}


AVLTree::~AVLTree()
{
}

bool AVLTree::Insert(int nValue, bool bRecursion)
{
	_Insert(&m_pRootNode, nValue, nullptr);

	return true;
}

bool AVLTree::Delete(int nValue)
{
	return true;
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

bool AVLTree::_Insert(TreeNode** pNode, int nValue, TreeNode* pParentNode)
{
	if (!(TreeNode*)(*pNode))
	{
		(*pNode) = new TreeNode(nValue);
		(*pNode)->parent = pParentNode;
		return true;
	}

	if ((*pNode)->val == nValue)
	{
		return false;
	}

	if ((*pNode)->val > nValue)
	{
		if (_Insert(&((*pNode)->left), nValue, *pNode))
		{
			//������������
			switch ((*pNode)->bf)
			{
				//ԭ�������ߣ�������ƽ�⴦��
			case TREE_LH:
			{
				(*pNode)->bf += 1;
				LeftBalance(*pNode);
				return false;
			}
			//ԭ�������ߣ����µ�ǰ�ڵ�ƽ������Ϊ�Ǹ�
			case TREE_RH:
			{
				(*pNode)->bf = TREE_EH;
				return false;
			}
			//ԭ�ȸ�,���µ�ǰ�ڵ�ƽ������Ϊ���
			case TREE_EH:
			{
				(*pNode)->bf = TREE_LH;
				return true;
			}
			//����˵��Ӧ���ߵ�����
			default:
				return false;
			}
		}
	}

	if ((*pNode)->val < nValue)
	{
		if (_Insert(&((*pNode)->right), nValue, *pNode))
		{
			//������������
			switch ((*pNode)->bf)
			{
				//ԭ�������ߣ����µ�ǰ�ڵ�ƽ������Ϊ�Ǹ�
			case TREE_LH:
			{
				(*pNode)->bf = TREE_EH;

				return false;
			}
			//ԭ�������ߣ�������ƽ�⴦��
			case TREE_RH:
			{
				(*pNode)->bf -= 1;
				RightBalance(*pNode);
				return false;
			}
			//ԭ�ȸ�,���µ�ǰ�ڵ�ƽ������Ϊ�Ҹ�
			case TREE_EH:
			{
				(*pNode)->bf = TREE_RH;
				return true;
			}
			//����˵��Ӧ���ߵ�����
			default:
				return false;
			}
		}
	}
}