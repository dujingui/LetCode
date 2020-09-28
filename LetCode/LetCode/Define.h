#pragma once

#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <iostream>
#include <queue>

#define TREE_NODE_NULL INT32_MAX
#define TREE_LH 1	//左高
#define TREE_EH 0	//等高
#define TREE_RH -1	//右高
#define TREE_LC 0	//在左子树插入
#define TREE_RC 1	//在右子树插入

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
	int val;
	int bf;	//平衡因子
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(int x) : val(x), bf(0), left(nullptr), right(nullptr),parent(nullptr) {}
};

ListNode* ConvertToListNode(vector<int>& vec);

TreeNode* ConvertToBinarySearchTreeNode(vector<int>& vec);
TreeNode* ConvertToTreeNode(vector<int>& vec, int i);

void PrintVector(vector<int>& vec);
