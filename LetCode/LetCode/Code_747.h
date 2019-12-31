#pragma once

#include "Define.h"

//747. �������������������������

//��һ������������nums�У����Ǵ���һ�����Ԫ�� ��
//
//���������е����Ԫ���Ƿ�������������ÿ���������ֵ�������
//
//����ǣ��򷵻����Ԫ�ص����������򷵻� - 1��
//
//ʾ�� 1:
//
//����: nums = [3, 6, 1, 0]
//	��� : 1
//	���� : 6����������, ���������е���������,
//	6��������������Ԫ�ص�������6��������1, �������Ƿ���1.
//
//
//	ʾ�� 2 :
//
//	���� : nums = [1, 2, 3, 4]
//	��� : -1
//	���� : 4û�г���3��������, �������Ƿ��� - 1.
//
//
//	��ʾ :
//
//	nums �ĳ��ȷ�Χ��[1, 50].
//	ÿ�� nums[i] ��������Χ��[0, 100].

int dominantIndex2(vector<int>& nums) {
	int maxnum = 0, index = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > maxnum)
		{
			maxnum = nums[i];
			index = i;
		}
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (i == index)
			continue;

		if (nums[i] * 2 > maxnum)
			return -1;
	}

	return index;
}

int dominantIndex(vector<int>& nums) {
	if (nums.size() < 2)
	{
		return 0;
	}

	int maxnum = 0, index = 0, minnum = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > maxnum)
		{
			minnum = nums[index];

			maxnum = nums[i];
			index = i;
		}
		else if (maxnum == minnum)
		{
			minnum = nums[i];
		}
		else if(nums[i] < maxnum && nums[i] > minnum)
		{
			minnum = nums[i];
		}
	}

	return minnum * 2 <= maxnum ? index : -1;
}