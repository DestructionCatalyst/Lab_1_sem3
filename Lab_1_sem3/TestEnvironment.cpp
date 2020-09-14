#include "TestEnvironment.h"

TestEnvironment& TestEnvironment::AddTest(UnitTest testToAdd)
{
	tests.push_back(testToAdd);
	return *this;
}

void TestEnvironment::RunAll()
{
	int passed = 0;

	for (UnitTest test : tests)
	{
		//Add 1 if test is passed
		passed += test.Run();
	}

	PrintResults(passed);
}

void TestEnvironment::PrintResults(int testsPassed)
{
	std::cout <<  "Testing finished, passed " << testsPassed << " out of " << tests.size() << std::endl;
}