#pragma once

#include "Define.h"

//¿ìËÙÅÅÐò

int partition(vector<int>& vec, int i, int j) 
{
	int xValue = vec[i], x = i;

	while (i < j)
	{
		while (i < j && vec[j] > xValue)
			j--;

		if (vec[j] <= xValue)
		{
			vec[x] = vec[j];
			x = j;
		}

		while (i < j && vec[i] <= xValue)
			i++;

		if (vec[i] > xValue)
		{
			vec[x] = vec[i];
			x = i;
		}
	}

	vec[x] = xValue;

	return x;
}

void _QuickSort(vector<int>& vec, int i, int j)
{
	if (i >= j)
	{
		return;
	}

	int x = partition(vec, i, j);

	_QuickSort(vec, i, x - 1);
	_QuickSort(vec, x + 1, j);
}

//µÝ¹é
void QuickSort2(vector<int>& vec)
{
	_QuickSort(vec, 0, vec.size() - 1);
}

//µü´ú
void QuickSort(vector<int>& vec)
{
	stack<vector<int>> sta;
	sta.push({ 0, int(vec.size() - 1) });

	while (sta.size() > 0)
	{
		vector<int> v = sta.top();
		sta.pop();

		if (v[0] < v[1])
		{
			int x = partition(vec, v[0], v[1]);
			sta.push({v[0], x - 1});
			sta.push({x + 1, v[1]});
		}
	}
}

void test_QuickSort()
{
	//std::vector<int> vec = { 2,3,1,5,4};
	std::vector<int> vec = { 2,3,1,5,4,2,3,64,2,64,16,4,6,64,6,4,42,64,6,46,345,4,3,43,4,6,6,34,46,4,6,46,4,36,6,6,346,34,6,346,3,4,346,34,6,4,6,34,634,6,3};
	QuickSort(vec);
}