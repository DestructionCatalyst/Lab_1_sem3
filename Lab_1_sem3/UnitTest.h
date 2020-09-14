#pragma once

#include <string>
#include <functional>
#include <random>
#include <iostream>

#include "AssertionException.h"

using std::string; 

class UnitTest
{
public:
	typedef std::function<void()> test_case;

private:
	int id;
	string name;

	test_case testFunction;
public:
	enum TestResult {
		TEST_SUCCESS,
		TEST_FAILURE,
		TEST_CRASH
	};

public:
	UnitTest(int id, string name, test_case testFunction);
	UnitTest(string name, test_case testCase);

public:
	virtual bool Run();

private:
	string ConvertResult(TestResult result);
	virtual void PrintResult(TestResult result);

};

