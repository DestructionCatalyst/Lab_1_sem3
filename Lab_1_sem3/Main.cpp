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

#include "QuickSorter.h"

#include "CommandParser.h"

using namespace std;
using namespace sequences;



void TestMergeSort(INumberGenerator* gen)
{
	SorterTest::PerformanceTest(1000, 100,
		[&](int length) -> ISorter<int>*
		{
			return new MergeSorter<int>(new ArraySequence<int>(gen, length));
		}
	);
}

void TestQuickSort(INumberGenerator* gen)
{
	SorterTest::PerformanceTest(1000, 100,
		[&](int length) -> ISorter<int>*
		{
			return new QuickSorter<int>(new ArraySequence<int>(gen, length));
		}
	);
}



int main() {

	ui::CommandParser parser{};

	std::string inputString;

	TestMergeSort(new RandomNumberGenerator());

	while (1)
	{
		getline(std::cin, inputString);
		parser.parse(inputString);
	}

	//TestEnvironment env{};

	//InitializeTests(env);

	//env.RunAll();

	//

	//TestMergeSort(new ReverseNumberGenerator(100000));



	//TestQuickSort(new ReverseNumberGenerator(100000));
	
	//TestQuickSort(new RandomNumberGenerator());


}

