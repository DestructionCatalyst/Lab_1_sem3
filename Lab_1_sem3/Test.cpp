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
	env.AddTest(new UnitTest(10, "Test of sequence equality assertions", TestAssert))
		.AddTest(new UnitTest(11, "Test of sequence and initializer list equality assertions", TestInitializerAssert))

		.AddTest(new UnitTest(101, "Test if array insertion", TestArrayInsertions))
		.AddTest(new UnitTest(102, "Test of getting subsequence from array", TestArraySubsequence))
		.AddTest(new UnitTest(103, "Test of array concatenation", TestArrayConcatenation))
		.AddTest(new UnitTest(151, "Test of array Map function", TestArrayMap))
		.AddTest(new UnitTest(152, "Test of array Where function", TestArrayWhere))
		.AddTest(new UnitTest(153, "Test of array Reduce function", TestArrayReduce))

		.AddTest(new UnitTest(101, "Test if list insertion", TestListInsertions))
		.AddTest(new UnitTest(102, "Test of getting subsequence from list", TestListSubsequence))
		.AddTest(new UnitTest(103, "Test of list concatenation", TestListConcatenation))
		.AddTest(new UnitTest(151, "Test of list Map function", TestListMap))
		.AddTest(new UnitTest(152, "Test of list Where function", TestListWhere))
		.AddTest(new UnitTest(153, "Test of list Reduce function", TestListReduce))
		;
}
