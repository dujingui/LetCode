#pragma once

#include "Define.h"

vector<int> vec;

//判断某一个位置是否可以放置皇后
bool can_place(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (vec[i] == col || vec[i] == col + (row - i) || vec[i] == col - (row - i))
		{
			return false;
		}
	}
	return true;
}

bool back_taracking(int n, int row = 0)
{
	if (row >= n)
	{
		return true;
	}

	if (row == 0)
	{
		for (int i = 0; i < n; i++)
			vec.push_back(-1);
	}

	for (int i = 0; i < n; i++)
	{
		if ( can_place(row,i) )
		{
			vec[row] = i;

			if (back_taracking(n, row + 1))
			{
				if (row == 0)
				{
					for (int i = 0; i < vec.size(); i++)
					{
						std::cout << vec[i] << std::endl;
					}
				}
				return true;
			}
			else
			{
				vec[row] = -1;
			}
		}
		else
		{
			
		}
	}

	return false;
}