#include "Test.h"

using namespace sequences;
using namespace sequences::iterators;

template<class T>
void AssertSequenceEquals(Sequence<T>* expected, Sequence<T>* actual) 
{
	if (expected == actual)
		return;

	assert((expected->GetLength()) == (actual->GetLength()));
	
	SequenceIterator<T>* expectedIter = expected->begin();
	SequenceIterator<T>* actualIter = actual->begin();

	for (; (*expectedIter != *expected->end()) && (*actualIter != *actual->end());
			++(*expectedIter), ++(*actualIter)) {
		assert((**expectedIter) == (**actualIter));
	}
		
}

template<class T>
void AssertSequenceEquals(std::initializer_list<T> expected, Sequence<T>* actual)
{
	assert((expected.size()) == (actual->GetLength()));

	auto expectedIter = expected.begin();
	SequenceIterator<T>* actualIter = actual->begin();

	for (; (expectedIter != expected.end()) && (*actualIter != *actual->end());
		++(expectedIter), ++(*actualIter)) {
		assert((*expectedIter) == (**actualIter));
	}
}

void PrintTestResults(std::string testName)
{
	std::cout << testName << " passed!" << std::endl;
}

void RunAllTests()
{
	TestAssert();
	TestInitializerAssert();
}

void TestAssert()
{
	int a[] = { 1, 2, 3 };

	Sequence<int>* seq = new ArraySequence<int>(a, 3);
	Sequence<int>* seq1 = new ListSequence<int>(a, 3);

	AssertSequenceEquals(seq, seq1);

	PrintTestResults("Test of sequence equality assertions");
}

void TestInitializerAssert()
{
	Sequence<int>* seq = new ArraySequence<int>({ 1, 2, 3, 4 });

	AssertSequenceEquals({1, 2, 3, 4}, seq);

	PrintTestResults("Test of sequence and initializer list equality assertions");
}