﻿// LetCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Define.h"
#include "BackTracking.h"
#include "Code_274.h"
#include "Code_62.h"
#include "Code_747.h"
#include "Code_921.h"
#include "Code_86.h"
#include "Code_492.h"
#include "Code_693.h"
#include "Code_375.h"
#include "Code_345.h"
#include "Code_101.h"
#include "QuickSort.h"
#include "Code_300.h"
#include "Code_1021.h"
#include "Code_1047.h"
#include "Code_682.h"
#include "Code_496.h"
#include "Code_232.h"
#include "Code_1046.h"
#include "Code_1038.h"
#include "BinarySearchTree.h"
#include "ByteAlign.h"
#include "Code_1221.h"
#include "Code_938.h"
#include "Sort_Insert.h"

using namespace std;

int main()
{
	vector<int> vec = { 10,5,15,3,7,18 };
	InsertSort(vec);

	cout << rangeSumBST(ConvertToBinarySearchTreeNode(vec), 7, 15);

	//cout << balancedStringSplit("RRRRRRLLRLRLRLLLLRLRRLLLLLRRRRRRLRLRLLRRLRLLLLRRRRRLRRRLLRRRLRRRRLRRLLLLLRRRRRRLLRLRRLLLLRRLLRLRRLRRLLRLRRRLLRRRRLRRRLLLRLRRLRRRRLRLRLRRLRRRLLLLLLLLLRLLRLLRRRLRRRLRRRLRRLRRRRRLLLLLRLLLRLLLLRRLRRLLLRRRRLLLLLRLRRLLRRRRLRRRLLLLRRRRLLRRLRLRRLLRLLRRLLRLRLLLRRLRRLLRLRLRRRRLLRLLRRLLLLRRRLRRLRLLRRLLLLRRLLLLLLLRLLRRRRRRRLLRLLLLLRRLLRRRRLRRRRLRRRLLLRLRLLRRLLLLRRRLLRRLLLRRLLRRRLRLLRLLRRLRRRRLRLRLRLRLRRRRRRLRRLLRRRRLRLRLRLLRLRRLRRRRRLRLLLRLRLRLRLLLRRRLLRLRLLRRLLLRLRLRLLRRLRLRLRRLLLLLLRLLRLLLRLRLRLLLRRRLRLRRRRRRRLLRRLLRRLLLLRLLRLRRLLRRRLLLLRRLRLRLLLRLRRRRLRLRRRLLLLLLLLRLLRRLRLRRRLLLLRLLRRLLLRLLRLRRLRLLRRRLLLLLRLRRLRLRLLLLRRRLLLRLRRRRRLLRRLRLLLLRLRLRRLLRLLLLRRLRRRLLLRRLRRRRRRLLRRLRLRRRLRRRLLLRRLRRLRRLLRRRRLLRRRLRLRRLRLLRLRLRRLRRRRRRRRRLLRRRLRRLLRRRRLRLLLLLLLRRRLRLLLLLRRLLLRLRLLRRLLLLLRRRRRRLLLLRLLLRLLLLLRRRRRLLRRRLLRRLLLLRRRRRLLRRLRRLRLLRLRLRRLRRLLLRLLLRLRRRLLLRRRLLRRRLRLRLLLLLLLRLRRLLRRLRLLRLLRRLLRRLRLLRLRLLRRRLLRLLLLRLLRRRRLRLLRRLLRRLRRLLRLLLRLLRRLLLLLRRLLLLRRRLLLLLLLRRRLRRRLRLLRLLLLLRLLLRRLRRRLLL");

	//std::vector<int> vec = { 2,3,1,5,4};
	//std::vector<int> vec = { 2,3,1,5,4,2,3,64,2,64,16,4,6,64,6,4,42,64,6,46,345,4,3,43,4,6,6,34,46,4,6,46,4,36,6,6,346,34,6,346,3,4,346,34,6,4,6,34,634,6,3};
	//QuickSort(vec);

	//std::vector<int> vec = { 1,2,2,NULL,3,3,NULL, NULL, NULL,4,5,5,4 };
	//TreeNode* root = ConvertToTreeNode(vec, 0);
	//cout << isSymmetric(root) << endl;
	//vector<int > vec = { 10,9,2,5,3,4 };
	//lengthOfLIS(vec);

	//std::vector<int> num1 = { 4,1,2 };
	//std::vector<int> num2 = { 1,3,4,2 };
	//std::vector<int> ret = nextGreaterElement(num1, num2);

	//MyQueue* obj = new MyQueue();
	//obj->push(1);
	//obj->push(2);
	//int param_2 = obj->pop();
	//int param_3 = obj->peek();
	//bool param_4 = obj->empty();

	//vector<int > vec = {2, 7, 4, 1, 8, 1};
	//lastStoneWeight(vec);

	//BinarySearchTree* pTree = new BinarySearchTree();
	//pTree->Insert(50);
	//pTree->Insert(30);
	//pTree->Insert(20);
	//pTree->Insert(35);
	//pTree->Insert(34);
	//pTree->Insert(32);
	//pTree->Insert(40);
	//pTree->Insert(80);
	//pTree->Insert(70);
	//pTree->Insert(100);
	//pTree->Insert(75);

	//pTree->PostOrder(false);
	//pTree->PostOrder(true);

	//pTree->Delete(30);
	
	//vector<int> vec = { 4,1,6,0,2,5,7,TREE_NODE_NULL,TREE_NODE_NULL,TREE_NODE_NULL,3,TREE_NODE_NULL,TREE_NODE_NULL,TREE_NODE_NULL,8 };
	//TreeNode* pNode = ConvertToTreeNode(vec, 0);
	//TreeNode* pNode1 = bstToGst(pNode);
    //std::cout << calPoints(vec);
	return 1;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
