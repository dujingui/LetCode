#include "pch.h"
#include "Define.h"
#include "BinarySearchTree.h"

ListNode* ConvertToListNode(vector<int>& vec)
{
	ListNode* pHead = new ListNode(0);
	ListNode* pTemp = pHead;

	for (int i = 0; i < vec.size(); i++)
	{
		pTemp->next = new ListNode(vec[i]);
		pTemp = pTemp->next;
	}

	pTemp = pHead->next;

	delete pHead;

	return pTemp;
}

TreeNode* ConvertToBinarySearchTreeNode(vector<int>& vec)
{
	if (vec.size() <= 0)return nullptr;

	BinarySearchTree* pTree = new BinarySearchTree();
	for (int i = 0; i < vec.size(); i++)
	{
		pTree->Insert(vec[i]);
	}

	return pTree->GetRootNode();
}

TreeNode* ConvertToTreeNode(vector<int>& vec, int i)
{
	TreeNode* pNode = nullptr;

	//if (i >= vec.size() || vec[i] == TREE_NODE_NULL)
	//{
	//	return pNode;
	//}

	//pNode = new TreeNode(vec[i]);
	//pNode->left = ConvertToTreeNode(vec, 2 * i + 1);
	//pNode->right = ConvertToTreeNode(vec, 2 * i + 2);

	return pNode;
}

void PrintVector(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << endl;
}

void PrintVector(vector<vector<char>>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			std::cout << vec[i][j] << " ";
		}
		std::cout << endl;
	}
	std::cout << endl;
}