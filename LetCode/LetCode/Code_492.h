#pragma once

#include "Define.h"

//492. 构造矩形
//
//作为一位web开发者， 懂得怎样去规划一个页面的尺寸是很重要的。 现给定一个具体的矩形页面面积，你的任务是设计一个长度为 L 和宽度为 W 且满足以下要求的矩形的页面。要求：
//
//1. 你设计的矩形页面必须等于给定的目标面积。
//
//2. 宽度 W 不应大于长度 L，换言之，要求 L >= W 。
//
//3. 长度 L 和宽度 W 之间的差距应当尽可能小。
//你需要按顺序输出你设计的页面的长度 L 和宽度 W。
//
//示例：
//
//输入 : 4
//	输出 : [2, 2]
//	解释 : 目标面积是 4， 所有可能的构造方案有[1, 4], [2, 2], [4, 1]。
//	但是根据要求2，[1, 4] 不符合要求; 根据要求3，[2, 2] 比[4, 1] 更能符合要求.所以输出长度 L 为 2， 宽度 W 为 2。
//	说明 :
//
//给定的面积不大于 10, 000, 000 且为正整数。
//你设计的页面的长度和宽度必须都是正整数。

vector<int> constructRectangle2(int area) {

	int index = 0;
	vector< vector<int> > vec;

	for (int i = area; i >= 1; i--)
	{
		int temp = area / i;

		if (temp > i && vec.size() > 0)
		{
			break;
		}

		if (area % i == 0)
		{
			vector<int> v = { i, temp };
			vec.push_back(v);
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[index][0] - vec[index][1] > vec[i][0] - vec[i][1])
		{
			index = i;
		}
	}

	return vec[index];
}

vector<int> constructRectangle(int area) {

	int w = sqrt(area);

	while (area % w != 0)
		w--;

	return { area / w, w };
}