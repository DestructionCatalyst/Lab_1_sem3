#include "TestCase.h"

TestCase::TestCase(function<void()> testFunction):
	testFunction(testFunction)
{}


void TestCase::Execute()
{
	testFunction();
}
