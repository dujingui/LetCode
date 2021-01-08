#pragma once

//34. 在排序数组中查找元素的第一个和最后一个位置
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//如果数组中不存在目标值 target，返回[-1, -1]。
//
//进阶：
//
//你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
//
//
//示例 1：
//
//输入：nums = [5, 7, 7, 8, 8, 10], target = 8
//输出：[3, 4]
//示例 2：
//
//输入：nums = [5, 7, 7, 8, 8, 10], target = 6
//输出：[-1, -1]
//示例 3：
//
//输入：nums = [], target = 0
//输出：[-1, -1]
//
//
//提示：
//
//0 <= nums.length <= 105
//- 109 <= nums[i] <= 109
//nums 是一个非递减数组
//- 109 <= target <= 109

#include "Define.h"

//test
//std::vector<int> vec = { 5,7,7,8,8,10 };
//vec = searchRange(vec, 6);
//std::cout << vec[0] << " " << vec[1] << std::endl;

int binarySearch(vector<int>& nums, int target, bool lower)
{
	int l = 0;
	int r = nums.size() - 1;
	int m = -1;
	int ret = nums.size();

	while (l <= r)
	{
		m = (l + r) / 2;
		if(nums[m] > target || (lower && nums[m] >= target) )
		{
			r = m - 1;
			ret = m;
		}
		else
		{
			l = m + 1;
		}
	}

	return ret;
}

vector<int> searchRange(vector<int>& nums, int target) 
{
	//先找到第一个大于等于目标的数的索引作为开始位置
	int l = binarySearch(nums, target, true);
	//再找到第一个大于目标的数的索引的前一个索引作为结束位置
	int r = binarySearch(nums, target, false) - 1;

	//没有找到大于等于目标数的数的索引，返回-1
	if (l == nums.size())
	{
		return { -1, -1 };
	}

	//找到的数不等于目标数，返回-1
	if (nums[l] != target)
	{
		return { -1, -1 };
	}

	return {l, r};
}

void test_32()
{
	std::vector<int> vec = { 5,7,7,8,8,10 };
	vec = searchRange(vec, 6);
}