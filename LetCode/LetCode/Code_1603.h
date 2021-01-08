#pragma once

#include "Define.h"

class ParkingSystem {
public:
	enum CarType {
		BIG,
		MEDIUM,
		SMALL,
		MAX,
	};
public:
	ParkingSystem(int big, int medium, int small)
	{
		m_ParkingNum[CarType::BIG]		= big;
		m_ParkingNum[CarType::MEDIUM]	= medium;
		m_ParkingNum[CarType::SMALL]	= small;
	}

	bool addCar(int carType)
	{
		if (m_ParkingNum[carType - 1] > 0)
		{
			m_ParkingNum[carType] --;
			return true;
		}

		return false;
	}
private:
	int m_ParkingNum[CarType::MAX];
};