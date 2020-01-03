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

ListNode* ConvertToListNode(vector<int>& vec);

TreeNode* ConvertToTreeNode(vector<int>& vec, int i);

void PrintVector(vector<int>& vec);
