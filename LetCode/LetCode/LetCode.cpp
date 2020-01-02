// LetCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

using namespace std;

int main()
{
	//std::vector<int> vec = { 2,3,1,5,4};
	//std::vector<int> vec = { 2,3,1,5,4,2,3,64,2,64,16,4,6,64,6,4,42,64,6,46,345,4,3,43,4,6,6,34,46,4,6,46,4,36,6,6,346,34,6,346,3,4,346,34,6,4,6,34,634,6,3};
	//QuickSort(vec);

	std::vector<int> vec = { 1,2,2,NULL,3,3,NULL, NULL, NULL,4,5,5,4 };
	TreeNode* root = ConvertToTreeNode(vec, 0);
	cout << isSymmetric(root) << endl;

    //std::cout << "Hello World!\n"; 
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
