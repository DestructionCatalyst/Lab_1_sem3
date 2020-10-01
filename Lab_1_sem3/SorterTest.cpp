#include "SorterTest.h"
#include <iostream>
#define ECHO_FOR_GRAPH

SorterTest::SorterTest(int id, string name, ISorter<int>* sorter) :
	TimedTest(id, name, nullptr), sorter(sorter)
{
	testCase = new TimedTestCase(
		[&](Timer& t) -> void
		{
			t.Start();
			this->sorter->Sort();
			t.Pause();

			AssertSequenceSorted(this->sorter->GetSequence());
		}
	);
}

string SorterTest::GenerateResultString(TestResult result) 
{
	if (result == TEST_FAILURE)
		return "Failed! ";
	else if (result == TEST_CRASH)
		return "Crashed! ";

	return (std::stringstream() << "(" << sorter->GetSequenceLength() << ";" << GetTestTime() << ") ").str();
}

void SorterTest::PrintResult(TestResult result)
{
	std::cout << GenerateResultString(result);
}

/*
void SorterTest::Run(Timer& t)
{
	t.Start();
	
	if (sorter == nullptr)
		throw AssertionException();
	Sequence<int>* sorted = sorter->Sort();

	t.Pause();

#ifdef ECHO_FOR_GRAPH
	std::cout << "(" << sorter->GetSequenceLength() << ";" << t.GetMS() << ") ";
#endif // ECHO_FOR_GRAPH

	AssertSequenceSorted(sorted);
}
*/

void SorterTest::PerformanceTest(int step, int iterations, std::function<ISorter<int>* (int)> sorterGenerator)
{

	TestEnvironment performanceTest{};

	for (int i = 1; i < iterations; i++)
	{
		int a = step * i;

		ISorter<int>* sorter = sorterGenerator(a);

		SorterTest(1000 + i, "Sorting performance test", sorter).Run();

		delete(sorter);
	}
}
