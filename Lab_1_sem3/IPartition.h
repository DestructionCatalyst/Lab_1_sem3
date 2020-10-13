#pragma once

class IPartition
{
public:
	virtual int SetStartValue(int sequenceLength) = 0;
	virtual int NextStepLength() = 0;
};