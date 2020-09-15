#pragma once

#include <string>
#include <functional>
#include <random>
#include <iostream>

#include "AssertionException.h"
#include "ITestCase.h"
#include "TestCase.h"

using std::string; 

class UnitTest
{
public:
	typedef std::function<void()> test_function_t;

private:
	int id;
	string name;

	ITestCase* testCase;
public:
	enum TestResult {
		TEST_SUCCESS,
		TEST_FAILURE,
		TEST_CRASH
	};

public:
	UnitTest(int id, string name, test_function_t testFunction);
	UnitTest(string name, test_function_t testCase);

public:
	virtual bool Run();

	virtual ~UnitTest();

private:
	string ConvertResult(TestResult result);
	virtual void PrintResult(TestResult result);

};

