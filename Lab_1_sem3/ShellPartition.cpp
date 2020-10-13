#include "ShellPartition.h"

int ShellPartition::SetStartValue(int sequenceLength)
{
	return stepSize = sequenceLength / 2;
}

int ShellPartition::NextStepLength()
{
		stepSize /= 2;
		return stepSize;
}
