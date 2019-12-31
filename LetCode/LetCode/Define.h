#pragma once

#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

	if (i >= vec.size() || vec[i] == NULL)
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