#pragma once

//34. �����������в���Ԫ�صĵ�һ�������һ��λ��
//����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
//
//��������в�����Ŀ��ֵ target������[-1, -1]��
//
//���ף�
//
//�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨�����������
//
//
//ʾ�� 1��
//
//���룺nums = [5, 7, 7, 8, 8, 10], target = 8
//�����[3, 4]
//ʾ�� 2��
//
//���룺nums = [5, 7, 7, 8, 8, 10], target = 6
//�����[-1, -1]
//ʾ�� 3��
//
//���룺nums = [], target = 0
//�����[-1, -1]
//
//
//��ʾ��
//
//0 <= nums.length <= 105
//- 109 <= nums[i] <= 109
//nums ��һ���ǵݼ�����
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
	//���ҵ���һ�����ڵ���Ŀ�������������Ϊ��ʼλ��
	int l = binarySearch(nums, target, true);
	//���ҵ���һ������Ŀ�������������ǰһ��������Ϊ����λ��
	int r = binarySearch(nums, target, false) - 1;

	//û���ҵ����ڵ���Ŀ��������������������-1
	if (l == nums.size())
	{
		return { -1, -1 };
	}

	//�ҵ�����������Ŀ����������-1
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