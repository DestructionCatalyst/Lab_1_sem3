#pragma once

#include "Sequence.h"
#include "SequenceAssertions.h"
#include "Timer.h"
#include "TimedTest.h"
#include "ISorter.h"

using namespace sequences;
class SorterTest: public TimedTest
{
private:
	ISorter<int>* sorter;
	//Sequence<int>* seq;
public:
	SorterTest(int id, string name, ISorter<int>* sorter);

	virtual string GenerateResultString(TestResult result) override;
	virtual void PrintResult(TestResult result) override;

	static void PerformanceTest(int step, int iterations, std::function<ISorter<int>* (int)> sorterGenerator);
	
};

