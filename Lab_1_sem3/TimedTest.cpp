#include "TimedTest.h"

#include <iostream>

TimedTest::TimedTest(int id, string name, function<void(Timer&)> testFunction) :
	UnitTest(id, name, new TimedTestCase(testFunction))
{}

TimedTest::TimedTest(string name, function<void(Timer&)> testFunction) :
	UnitTest(rand(), name, new TimedTestCase(testFunction))
{}

string TimedTest::GenerateResultString(TestResult result)
{
	return (std::stringstream() 
		<< UnitTest::GenerateResultString(result)
		<< " Time: " << GetTestTime() / 1000. << " seconds" ).str(); 
}

void TimedTest::PrintResult(TestResult result)
{
	std::cout << GenerateResultString(result) << std::endl;
}

int TimedTest::GetTestTime()
{

	//std::cout << dynamic_cast<TimedTestCase*>(testCase)->GetTestTime() << std::endl;
	return dynamic_cast<TimedTestCase*>(testCase)->GetTestTime();
}