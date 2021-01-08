#pragma once

#include "Define.h"

//插入排序
//应用于少量元素的排序，插入排序的工作方式像许多人排序一手扑克牌。开始时，我们的左手为空并且
//桌子上的牌面朝下，然后每次从桌子上拿走一张牌并将它插入到左手中正确的位置。为了找到一张牌的
//正确位置，我们从右到左（因为要向后移动元素，所以从右到左方便一点）将它与已在手中的每一张牌进行比较。

//升序
//空间复杂度：O(N)
//时间复杂度：O(N^2 + N)
void InsertSort1(vector<int>& p)
{
	//手中的牌
	vector<int> h;
	//手中牌的数量
	int hs = 0;
	h.resize(p.size());

	//外层循环相当于桌子上的牌
	for (int i = 0; i < p.size(); i++)
	{
		//从桌子上拿起一张牌
		int value = p[i];

		//手中没有牌直接插入
		if (hs <= 0)
		{
			h[0] = value;
			hs++;
			continue;
		}

		int j = hs - 1;

		//从右到左与手中的牌(0，i)进行比较
		for (; j >= 0; j --)
		{
			if (value > h[j])
			{
				break;
			}
			else
			{
				//当前元素不满足排序条件 向后移一步
				h[j + 1] = h[j];
			}
		}

		h[j + 1] = value;
		hs++;
	}

	for (int i = 0; i < hs; i++)
	{
		p[i] = h[i];
	}
}

//升序
//空间复杂度：O(1)
//时间复杂度：O(N^2)
void InsertSort2(vector<int>& p)
{
	//外层循环相当于桌子上的牌(默认先拿起一张牌，因为不用比较)
	for (int i = 1; i < p.size(); i++)
	{
		//从桌子上拿起一张牌
		int value = p[i];

		//指向手中的最右边的牌
		int j = i - 1;

		//从右到左与手中的牌(i - 1，0)进行比较
		for (; j >= 0; j--)
		{
			if (value > p[j])
			{
				//找到位置了 退出去插入
				break;
			}
			else
			{
				//当前元素不满足排序条件 向后移一步
				p[j + 1] = p[j];
			}
		}

		p[j + 1] = value;
	}
}

//降序
void InsertSort(vector<int>& p)
{
	for (int i = 1; i < p.size(); i++)
	{
		int value = p[i];

		int j = i - 1;

		for (; j >= 0; j--)
		{
			if (value < p[j])
				break;
			else
				p[j + 1] = p[j];
		}
		p[j + 1] = value;
	}
}

void test_InsertSort()
{
	vector<int> vec = { 10,5,15,3,7,18 };
	InsertSort(vec);
}