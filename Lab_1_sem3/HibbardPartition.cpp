#include "HibbardPartition.h"

int HibbardPartition::SetStartValue(int sequenceLength)
{
	int i = 0;
	int a = 1;

	while (a < sequenceLength)
	{
		a = (a + 1) * base - 1;
	}

	stepSize = (a + 1) / 2 - 1;

	return stepSize;
}

int HibbardPartition::NextStepLength()
{
	stepSize = (stepSize + 1) / 2 - 1;

	return stepSize;
}


