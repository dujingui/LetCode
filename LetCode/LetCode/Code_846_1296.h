#pragma once

//爱丽丝有一手（hand）由整数数组给定的牌。 
//
//现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。
//
//如果她可以完成分组就返回 true，否则返回 false。
//
//
//
//注意：此题目与 1296 重复：https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
//
//
//
//示例 1：
//
//输入：hand = [1, 2, 3, 6, 2, 3, 4, 7, 8], W = 3
//输出：true
//解释：爱丽丝的手牌可以被重新排列为[1, 2, 3]，[2, 3, 4]，[6, 7, 8]。
//示例 2：
//
//输入：hand = [1, 2, 3, 4, 5], W = 4
//输出：false
//解释：爱丽丝的手牌无法被重新排列成几个大小为 4 的组。
//
//
//提示：
//
//1 <= hand.length <= 10000
//0 <= hand[i] <= 10 ^ 9
//1 <= W <= hand.length
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/hand-of-straights
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include "Define.h"


//第一版超时了
void sort_8461(vector<int>& hand){
	for (int i = 0; i < hand.size() - 1; i++)
	{
		for (int j = i + 1; j < hand.size(); j++)
		{
			if (hand[j] > hand[i])
			{
				int temp = hand[i];
				hand[i] = hand[j];
				hand[j] = temp;
			}
		}
	}
}
bool isNStraightHand(vector<int>& hand, int W) {
	if (hand.size() % W != 0)return false;

	if (hand.size() == 0 || W == 0) return false;

	if (W == 1) return true;

	//使用系统函数就可以通过
	sort(hand.begin(), hand.end(), greater<int>());

	int i = hand.size() - 1, count = 1, s = hand[i];

	for (; i > 0; )
	{
		int t = hand[i - 1] - s;
		
		if (t == 1)
		{
			count++;

			s = hand[i - 1];

			hand.erase(hand.begin() + i);

			if (count == W)
			{
				count = 1;
				hand.erase(hand.begin() + i - 1);

				if (hand.size() <= 0)
				{
					break;
				}

				i = hand.size() - 1;
				s = hand[i];
				continue;
			}
		}
		else if (t > 1)
		{
			return false;
		}

		i--;
	}

	return hand.size() == 0;
}

bool isNStraightHand1(vector<int>& hand, int W) {

	map<int, int> m;
	for (int i = 0; i < hand.size(); i++)
	{
		if (m.find(hand[i]) == m.end())
		{
			m[hand[i]] = 1;
		}
		else
		{
			m[hand[i]] ++;
		}
	}

	while (m.size() > 0)
	{
		int f = (*(m.begin())).first;

		for (int i = f; i < f + W; i++)
		{
			auto iter = m.find(i);

			if (iter == m.end())
			{
				return false;
			}
			
			if ((*iter).second > 1)
			{
				(*iter).second--;
			}
			else 
			{
				m.erase(iter);
			}
		}
	}

	return true;
}