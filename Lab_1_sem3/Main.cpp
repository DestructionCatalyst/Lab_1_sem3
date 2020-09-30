#include <iostream>
#include <cstdlib>
#include <ctime>

#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "Test.h"
#include "TestEnvironment.h"

#include "ISorter.h"
#include "SorterTest.h"

using namespace std;
using namespace sequences;



void TestMergeSort()
{
	SorterTest::PerformanceTest(1000, 100,
		[](int length) -> ISorter<int>*
		{
			return new MergeSorter<int>(new ArraySequence<int>(new RandomNumberGenerator(length), length));
		}
	);
}

void TestMergeSortOnInverse()
{
	SorterTest::PerformanceTest(1000, 100,
		[](int length) -> ISorter<int>*
		{
			return new MergeSorter<int>(new ArraySequence<int>(new ReverseNumberGenerator(length), length));
		}
	);
}

int main() {

	TestEnvironment env{};

	InitializeTests(env);

	TestMergeSort();

	//TestMergeSortOnInverse();
	
	//env.RunAll();

	//srand(420);

	//for (int i = 0; i < 10; i++)
		//cout << rand() << ", ";

	//cout << endl;

	//cout << rand() << " " << rand() << " " << rand() << endl;
	
	//testArraySequence();
	//testListSequence();
}

