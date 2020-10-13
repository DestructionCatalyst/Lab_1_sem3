#pragma once

#include "IPartition.h"

class ShellPartition :
	public IPartition
{
private:
	int stepSize;
public:

	int SetStartValue(int sequenceLength);
	int NextStepLength() override;
};

