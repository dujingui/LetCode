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

	/* 检查pRootNode的左子树的平衡度，并作相应平衡处理 */
	switch (pLeftNode->bf)
	{
		//新结点插入在T的左孩子的左子树上，要作单右旋处理
		case TREE_LH:
		{
			pRootNode->bf = pLeftNode->bf = TREE_EH;
			R_Rotate(pRootNode);
			break;
		}
		//新结点插入在T的左孩子的右子树上，要作双旋处理
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
			//对T的左子树作左旋平衡处理
			L_Rotate(pRootNode->left);
			//对T作右旋平衡处理
			R_Rotate(pRootNode);
			break;
		}
		//特殊情况4,这种情况在添加时不可能出现，只在移除时可能出现，旋转之后整体树高不变
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
		//新节点插入根节点的右节点的右子树上,成RR型,做左旋处理
		case TREE_RH:
		{
			pRootNode->bf	= TREE_EH;
			pRightNode->bf	= TREE_EH;

			L_Rotate(pRootNode);

			break;
		}
		//新节点插入根节点的右节点的左子树上,成RL型，做右平衡处理(先右旋在左旋)
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
		//插入节点不会遇到这种情况 只有删除节点会出现这种情况
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

	//将根节点的左节点指向根节点左节点的右节点
	pRootNode->left			= pLeftNode->right;
	if (pLeftNode->right)
		pLeftNode->right->parent = pRootNode;


	pLeftNode->right	= pRootNode;
	pLeftNode->parent	= pParentNode;
	pRootNode->parent	= pLeftNode;

	if (!pParentNode)
		//说明pRootNode是树的根节点
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
			//左子树长高了
			switch ((*pNode)->bf)
			{
				//原左子树高，需做左平衡处理
			case TREE_LH:
			{
				(*pNode)->bf += 1;
				LeftBalance(*pNode);
				return false;
			}
			//原右子树高，更新当前节点平衡因子为登高
			case TREE_RH:
			{
				(*pNode)->bf = TREE_EH;
				return false;
			}
			//原等高,更新当前节点平衡因子为左高
			case TREE_EH:
			{
				(*pNode)->bf = TREE_LH;
				return true;
			}
			//按理说不应该走到这里
			default:
				return false;
			}
		}
	}

	if ((*pNode)->val < nValue)
	{
		if (_Insert(&((*pNode)->right), nValue, *pNode))
		{
			//右子树长高了
			switch ((*pNode)->bf)
			{
				//原左子树高，更新当前节点平衡因子为登高
			case TREE_LH:
			{
				(*pNode)->bf = TREE_EH;

				return false;
			}
			//原右子树高，需做右平衡处理
			case TREE_RH:
			{
				(*pNode)->bf -= 1;
				RightBalance(*pNode);
				return false;
			}
			//原等高,更新当前节点平衡因子为右高
			case TREE_EH:
			{
				(*pNode)->bf = TREE_RH;
				return true;
			}
			//按理说不应该走到这里
			default:
				return false;
			}
		}
	}
}