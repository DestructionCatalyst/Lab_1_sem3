#pragma once

#include <cmath>

#include "IPartition.h"

class HibbardPartition :
	public IPartition
{
private:
	int stepSize;
	const int base = 2;
public:

	int SetStartValue(int sequenceLength);
	int NextStepLength() override;
};

