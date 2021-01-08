#include "pch.h"
#include "BinarySearchTree.h"
#include "Define.h"

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
		return _RecursionInsert(&m_pRootNode, pNode, m_pRootNode);

	if (nValue < m_pRootNode->val)
	{
		TreeNode* pParent = nullptr;
		TreeNode** pTemp = &(m_pRootNode->left);

		while (*pTemp)
		{
			pParent = *pTemp;

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
		(*pTemp)->parent = pParent;

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
	return this->_Delete(Search(nValue));
}

bool BinarySearchTree::_Delete(TreeNode* pNode)
{
	if (!pNode)
		return false;

	//��������� ��Ҫɾ���Ľڵ�������������
	if (pNode->left && pNode->right)
	{
		TreeNode* pNextNode = NextNode(pNode);
		if (!pNextNode)
			return false;

		//������̽ڵ��뽫Ҫɾ���Ľڵ��ֵ(��Ϊ���ڵ�û�б������ڵ�,������Ҫ���������Ҹ��ڵ�,�����Ļ��Ͳ��ܴ�����ֵͬ�Ľڵ� ����Ҫ����ֵ�������Ǽ򵥸����¾Ϳ�����) Ȼ��ɾ����̽ڵ�
		int nTemp = pNode->val;
		pNode->val = pNextNode->val;
		pNextNode->val = nTemp;

		pNode = pNextNode;
	}

	//��һ����� ��Ҫɾ���Ľڵ�û���κ�����
	if (!pNode->left && !pNode->right)
	{
		TreeNode* pParent = BinarySearchTree::GetParentNode(m_pRootNode, pNode);
		if (pParent)
		{
			if (pParent->left == pNode)
			{
				pParent->left = nullptr;
			}
			else if (pParent->right == pNode)
			{
				pParent->right = nullptr;
			}
		}
		return true;
	}

	//ʣ�µ�ֻ���ǵڶ������ ��Ҫɾ���Ľڵ�������������������
	TreeNode* pParent = BinarySearchTree::GetParentNode(m_pRootNode, pNode);
	if (pParent)
	{
		TreeNode* pChild = pNode->left ? pNode->left : pNode->right;

		if (pParent->left == pNode)
		{
			pParent->left = pChild;
		}
		else if (pParent->right == pNode)
		{
			pParent->right = pChild;
		}
	}
	return true;
}

TreeNode* BinarySearchTree::Search(int nValue, bool bRecursion)
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

void BinarySearchTree::PreOrder(bool bRecursion)
{
	if (bRecursion)
		return _RecursionPreOrder(m_pRootNode);

	_PreOrder(m_pRootNode);

	cout << endl;
}

void BinarySearchTree::InfixOrder(bool bRecursion)
{
	if (bRecursion)
		return _RecursionInfixOrder(m_pRootNode);

	_InfixOrder(m_pRootNode);
	cout << endl;
}

void BinarySearchTree::PostOrder(bool bRecursion)
{
	if (bRecursion)
		return _RecursionPostOrder(m_pRootNode);

	_PostOrder(m_pRootNode);
	cout << endl;
}

void BinarySearchTree::LevelOrder()
{
	_LevelOrder(m_pRootNode);
	cout << endl;
}

void BinarySearchTree::Print()
{
	_Print(m_pRootNode);
}

bool BinarySearchTree::_RecursionInsert(TreeNode** ppNode, TreeNode* pNode, TreeNode* pParentNode)
{
	if (*ppNode == nullptr)
	{
		(*ppNode) = pNode;
		(*ppNode)->parent = pParentNode;
		return true;
	}

	if (pNode->val < (*ppNode)->val)
	{
		return _RecursionInsert(&(*ppNode)->left, pNode, *ppNode);
	}
	else
	{
		return _RecursionInsert(&(*ppNode)->right, pNode, *ppNode);
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

void BinarySearchTree::_RecursionPreOrder(TreeNode* pRootNode)
{
	if (!pRootNode)
	{
		return;
	}

	cout << pRootNode->val << " ";

	_RecursionPreOrder(pRootNode->left);
	_RecursionPreOrder(pRootNode->right);
}

void BinarySearchTree::_RecursionInfixOrder(TreeNode* pRootNode)
{
	if (!pRootNode)
	{
		return;
	}

	_RecursionInfixOrder(pRootNode->left);

	cout << pRootNode->val << " ";

	_RecursionInfixOrder(pRootNode->right);
}

void BinarySearchTree::_RecursionPostOrder(TreeNode* pRootNode)
{
	if (!pRootNode)
	{
		return;
	}

	_RecursionPostOrder(pRootNode->left);
	_RecursionPostOrder(pRootNode->right);

	cout << pRootNode->val << " ";
}

TreeNode* BinarySearchTree::NextNode(TreeNode* pNode)
{
	return BinarySearchTree::GetNextNode(m_pRootNode, pNode);
}


TreeNode* BinarySearchTree::LastNode(TreeNode* pNode)
{
	return BinarySearchTree::GetLastNode(m_pRootNode, pNode);
}

TreeNode* BinarySearchTree::MaxNode()
{
	return BinarySearchTree::GetMaxNode(m_pRootNode);
}

TreeNode* BinarySearchTree::MinNode()
{
	return BinarySearchTree::GetMinNode(m_pRootNode);
}

TreeNode* BinarySearchTree::GetMaxNode(TreeNode* pRootNode)
{
	if (!pRootNode)
	{
		return nullptr;
	}

	TreeNode* pTempNode = pRootNode;
	while (pTempNode)
		pTempNode = pTempNode->right;

	return pTempNode;
}

TreeNode* BinarySearchTree::GetMinNode(TreeNode* pRootNode)
{
	if (!pRootNode)
	{
		return nullptr;
	}

	TreeNode* pTempNode = pRootNode;
	while (pTempNode->left)
		pTempNode = pTempNode->left;

	return pTempNode;
}

TreeNode* BinarySearchTree::GetLastNode(TreeNode* pRootNode, TreeNode* pNode)
{
	if (!pRootNode || !pNode)
		return nullptr;

	//�����������, ��ǰ���ڵ�Ϊ����ڵ�Ϊ�����������������ֵ
	if (pNode->left)
		return BinarySearchTree::GetMaxNode(pNode->left);

	//�����������,��ǰ���ڵ�Ϊ���ڵ�
	TreeNode* pParent = BinarySearchTree::GetParentNode(pRootNode, pNode);
	if (pParent->right == pNode)
		return pParent;

	//���������������ǰ���ڵ�Ϊ��͸��ڵ�(��͸��ڵ�����������������а�����ǰ�ڵ�:pNode)
	TreeNode* pTemp = pParent;
	TreeNode* pCur = pNode;
	while (pTemp && pTemp->left == pCur)
	{
		pCur = pTemp;
		pTemp = BinarySearchTree::GetParentNode(pRootNode, pCur);
	}

	if (pTemp)
		return pTemp;

	return nullptr;
}

TreeNode*	BinarySearchTree::GetNextNode(TreeNode* pRootNode, TreeNode* pNode)
{
	if (!pRootNode || !pNode)
		return nullptr;

	//�����������,��̽ڵ�Ϊ���ҽڵ�Ϊ����������������Сֵ
	if (pNode->right)
		return BinarySearchTree::GetMinNode(pNode->right);

	//�����������,��̽ڵ�Ϊ���ڵ�
	TreeNode* pParent = BinarySearchTree::GetParentNode(pRootNode, pNode);
	if (pParent->left == pNode)
		return pParent;

	//�����������,��̽ڵ�Ϊ��͸��ڵ�(��͸��ڵ�����������������а�����ǰ�ڵ�:pNode)
	TreeNode* pTemp = pParent;
	TreeNode* pCur = pNode;
	while (pTemp && pTemp->right == pNode)
	{
		pCur = pTemp;
		pTemp = BinarySearchTree::GetParentNode(pRootNode, pCur);
	}

	if (pTemp)
		return pTemp;

	return nullptr;
}

TreeNode*	BinarySearchTree::GetParentNode(TreeNode* pRootNode, TreeNode* pNode)
{
	return pNode->parent;

	if (!pRootNode || !pNode)
		return nullptr;

	if (pRootNode->left && pRootNode->left->val == pNode->val)
	{
		return pRootNode;
	}
	else if(pRootNode->right && pRootNode->right->val == pNode->val)
	{
		return pRootNode;
	}

	if (pNode->val < pRootNode->val)
	{
		return BinarySearchTree::GetParentNode(pRootNode->left, pNode);
	}
	else if(pNode->val > pRootNode->val)
	{
		return BinarySearchTree::GetParentNode(pRootNode->right, pNode);
	}

	return nullptr;
}

void BinarySearchTree::_PreOrder(TreeNode* pRootNode)
{
	stack<TreeNode*> stack;
	stack.push(pRootNode);

	while (stack.size() > 0)
	{
		TreeNode* pNode = stack.top();
		stack.pop();

		cout << pNode->val << " ";

		if (pNode->right)
			stack.push(pNode->right);
		if (pNode->left)
			stack.push(pNode->left);
	}
}

void BinarySearchTree::_InfixOrder(TreeNode* pRootNode)
{
	stack<TreeNode*> stack;

	while (pRootNode || stack.size() > 0)
	{
		while (pRootNode)
		{
			stack.push(pRootNode);
			pRootNode = pRootNode->left;
		}

		if (stack.size() > 0)
		{
			pRootNode = stack.top();
			stack.pop();

			cout << pRootNode->val << " ";
			pRootNode = pRootNode->right;
		}
	}
}

void BinarySearchTree::_PostOrder(TreeNode* pRootNode)
{
	stack<TreeNode*> stack;

	int flag = 1;
	TreeNode* pPre = nullptr;

	do 
	{
		while (pRootNode)
		{
			stack.push(pRootNode);
			pRootNode = pRootNode->left;
		}

		pPre = nullptr;
		flag = 1;

		while (stack.size() && flag)
		{
			pRootNode = stack.top();

			if (pRootNode->right == pPre)
			{
				cout << pRootNode->val << " ";
				stack.pop();
				pPre = pRootNode;
			}
			else
			{
				pRootNode = pRootNode->right;
				flag = 0;
			}
		}
	} while (stack.size() > 0);
}

void BinarySearchTree::_LevelOrder(TreeNode* pRootNode)
{
	queue<TreeNode *> q;
	q.push(pRootNode);

	while (q.size() > 0)
	{
		TreeNode* pTemp = q.front();
		q.pop();

		cout << pTemp->val << " ";

		if (pTemp->left)
			q.push(pTemp->left);

		if (pTemp->right)
			q.push(pTemp->right);
	}
}

void BinarySearchTree::_Print(TreeNode* pRootNode)
{
	
}

void test_BinarySearchTree()
{
	BinarySearchTree* pTree = new BinarySearchTree();
	pTree->Insert(50);
	pTree->Insert(30);
	pTree->Insert(20);
	pTree->Insert(35);
	pTree->Insert(34);
	pTree->Insert(32);
	pTree->Insert(40);
	pTree->Insert(80);
	pTree->Insert(70);
	pTree->Insert(100);
	pTree->Insert(75);

	pTree->PostOrder(false);
	pTree->PostOrder(true);

	pTree->Delete(30);
}