#pragma once

#include "Define.h"
#include "QuickSort.h"

//1046. ���һ��ʯͷ������
//
//��һ��ʯͷ��ÿ��ʯͷ������������������
//
//ÿһ�غϣ�����ѡ���������ص�ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊ x �� y���� x <= y����ô����Ŀ��ܽ�����£�
//
//��� x == y����ô����ʯͷ���ᱻ��ȫ���飻
//��� x != y����ô����Ϊ x ��ʯͷ������ȫ���飬������Ϊ y ��ʯͷ������Ϊ y - x��
//������ֻ��ʣ��һ��ʯͷ�����ش�ʯͷ�����������û��ʯͷʣ�£��ͷ��� 0��
//
//
//
//��ʾ��
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