#include "pch.h"
#include "Define.h"

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

TreeNode* ConvertToTreeNode(vector<int>& vec, int i)
{
	TreeNode* pNode = nullptr;

	if (i >= vec.size() || vec[i] == TREE_NODE_NULL)
	{
		return pNode;
	}

	pNode = new TreeNode(vec[i]);
	pNode->left = ConvertToTreeNode(vec, 2 * i + 1);
	pNode->right = ConvertToTreeNode(vec, 2 * i + 2);

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