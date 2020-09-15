#include "UnitTest.h"

UnitTest::UnitTest(int id, string name, test_function_t testFunction):
	id(id), name(name), testFunction(new TestCase(testFunction))
{}

UnitTest::UnitTest(string name, test_function_t testFunction) :
	name(name), testFunction(new TestCase(testFunction))
{
	id = rand();
}

string UnitTest::ConvertResult(TestResult result)
{
	switch (result) {
	case TEST_SUCCESS:
		return "passed!";
	case TEST_FAILURE:
		return "not passed!";
	case TEST_CRASH:
		return "caused an exception!";
	}
	return "";
}

bool UnitTest::Run()
{
	try
	{
		testFunction->Execute();
		PrintResult(TEST_SUCCESS);
		return true;
	}
	catch (AssertionException e)
	{
		PrintResult(TEST_FAILURE);
	}
	catch (...)
	{
		PrintResult(TEST_CRASH);
	}
	return false;

}

void UnitTest::PrintResult(TestResult result)
{
	std::cout << "Test " << id << " (" << name << ") " << ConvertResult(result) << std::endl;
}