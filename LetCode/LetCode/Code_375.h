﻿#pragma once

#include "Define.h"

//猜数字大小 II	
//
//我们正在玩一个猜数游戏，游戏规则如下：
//
//我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。
//
//每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。
//
//然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。
//
//示例 :
//
//n = 10, 我选择了8.
//
//第一轮 : 你猜我选择的数字是5，我会告诉你，我的数字更大一些，然后你需要支付5块。
//	第二轮 : 你猜是7，我告诉你，我的数字更大一些，你支付7块。
//	第三轮 : 你猜是9，我告诉你，我的数字更小一些，你支付9块。
//
//	游戏结束。8 就是我选的数字。
//
//	你最终要支付 5 + 7 + 9 = 21 块钱。
//	给定 n ≥ 1，计算你至少需要拥有多少现金才能确保你能赢得这个游戏。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/guess-number-higher-or-lower-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//方法 1：暴力
//首先，我们需要意识到我们在范围(1, n)(1, n) 中猜数字的时候，需要考虑最坏情况下的代价。也就是说要算每次都猜错的情况下的总体最大开销。
//
//在暴力算法中，我们首先在(1, n)(1, n) 中任意挑选一个数字，假设它是个错误的猜测（最坏情况），我们需要用最小代价去猜到需要的数字。那么在一次尝试以后，答案要么在我们猜的数字的左边要么在右边，为了考虑最坏情况，我们需要考虑两者的较大值。因此，如果我们选择 ii 作为第一次尝试，总体最小代价是：
//
//\mathrm{ cost }(1, n) = i + \max\big(\mathrm{ cost }(1, i - 1), \mathrm{ cost }(i + 1, n)\big)
//cost(1, n) = i + max(cost(1, i−1), cost(i + 1, n))
//
//对于左右两段，我们分别考虑在段内选择一个数，并重复上面的过程来求得最小开销。
//
//使用如上方法，我们能求得从 ii 开始猜，猜到答案的最小代价。同样地，我们遍历(1, n)(1, n) 中的所有数字并分别作为第一次尝试，求出每一个的代价，并输入最小值即为答案。
//
//作者：LeetCode
//链接：https ://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/solution/cai-shu-zi-da-xiao-ii-by-leetcode/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处

//TODO:
int calc(int low, int high) {
	if (low >= high)
		return 0;

	int minres = INT32_MAX;

	for (int i = low; i <= high; i++)
	{
		int res = i + max(calc(i + 1, high), calc(low, i - 1));
		minres = min(res, minres);
	}

	return minres;
}

int getMoneyAmount(int n) {
	return calc(1, n);
}