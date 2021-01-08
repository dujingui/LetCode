#pragma once

#include "Define.h"
#include "QuickSort.h"

//1046. 最后一块石头的重量
//
//有一堆石头，每块石头的重量都是正整数。
//
//每一回合，从中选出两块最重的石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
//
//如果 x == y，那么两块石头都会被完全粉碎；
//如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y - x。
//最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。
//
//
//
//提示：
//
//1 <= stones.length <= 30
//1 <= stones[i] <= 1000

int lastStoneWeight(vector<int>& stones) {

	while (stones.size() > 1)
	{
		int x = 0, y = 0;
		if (stones[0] > stones[1])
		{
			x = 0;
			y = 1;
		}
		else
		{
			x = 1;
			y = 0;
		}

		for (int i = 2; i < stones.size(); i++)
		{
			if (stones[i] > stones[x])
			{
				y = x;
				x = i;
			}
			else if (stones[i] > stones[y])
			{
				y = i;
			}
		}

		if (stones[x] == stones[y])
		{
			if (x > y)
			{
				stones.erase(stones.begin() + x, stones.begin() + x + 1);
				stones.erase(stones.begin() + y, stones.begin() + y + 1);
			}
			else
			{
				stones.erase(stones.begin() + y, stones.begin() + y + 1);
				stones.erase(stones.begin() + x, stones.begin() + x + 1);
			}
		}
		else if (stones[x] > stones[y])
		{
			stones[x] = stones[x] - stones[y];
			stones.erase(stones.begin() + y, stones.begin() + y + 1);
		}
	}

	return stones.size() > 0 ? stones[0] : 0;
}

void test_1046()
{
	vector<int > vec = {2, 7, 4, 1, 8, 1};
	lastStoneWeight(vec);
}