#include "Test.h"

using namespace sequences;
using namespace sequences::iterators;

void TestAssert()
{
	int a[] = { 1, 2, 3 };

	Sequence<int>* seq = new ArraySequence<int>(a, 3);
	Sequence<int>* seq1 = new ListSequence<int>(a, 3);

	AssertSequenceEquals(seq, seq1);

	delete(seq);
}

void TestInitializerAssert()
{
	Sequence<int>* seq = new ArraySequence<int>({ 1, 2, 3, 4 });

	AssertSequenceEquals({1, 2, 3, 4}, seq);

	delete(seq);
}


void InitializeTests(TestEnvironment& env)
{
	env.AddTest(UnitTest(10, "Test of sequence equality assertions", TestAssert))
		.AddTest(UnitTest(11, "Test of sequence and initializer list equality assertions", TestInitializerAssert))
		.AddTest(UnitTest(101, "Test if array insertion", TestArrayInsertions))
		.AddTest(UnitTest(102, "Test of getting subsequence from array", TestArraySubsequence))
		;
}
