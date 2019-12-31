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

void PrintVector(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << endl;
}