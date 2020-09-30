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

void TestSortedAssert()
{
	Sequence<int>* seq = new ArraySequence<int>({ 1, 2, 3, 3 });

	AssertSequenceSorted(seq);

	seq->Swap(1, 2);

	bool failed = false;

	try
	{
		AssertSequenceSorted(seq);
	}
	catch (AssertionException e)
	{
		failed = true;
	}

	TestEnvironment::Assert(failed);

	delete(seq);
}

void TestTimedTest(Timer& t)
{
	long long fact = 1L;
	int a = 0;

	t.Start();
	{
		for (int i = 1; i <= 20; ++i)
		{
			fact *= i;
		}
		for (int i = 1; i <= 1000000; ++i)
		{
			a = (int)(std::sqrt(i));
		}
		//Sleep(100);
	}
	t.Pause();

	TestEnvironment::Assert(fact == 2432902008176640000);
	TestEnvironment::Assert(a == 1000);
}

//TimedTest*


void InitializeTests(TestEnvironment& env)
{
	env.AddTest(new UnitTest(10, "Test of sequence equality assertions", TestAssert))
		.AddTest(new UnitTest(11, "Test of sequence and initializer list equality assertions", TestInitializerAssert))
		.AddTest(new UnitTest(12, "Test of sequence sorted assertions", TestSortedAssert))
		//Slow and unstable
		//.AddTest(new UnitTest(51, "Test of timer", TestTimer))
		.AddTest(new TimedTest(52, "Basic timed test", TestTimedTest))

		.AddTest(new UnitTest(101, "Test of array insertion", TestArrayInsertions))
		.AddTest(new UnitTest(102, "Test of getting subsequence from array", TestArraySubsequence))
		.AddTest(new UnitTest(103, "Test of array concatenation", TestArrayConcatenation))
		.AddTest(new UnitTest(151, "Test of array Map function", TestArrayMap))
		.AddTest(new UnitTest(152, "Test of array Where function", TestArrayWhere))
		.AddTest(new UnitTest(153, "Test of array Reduce function", TestArrayReduce))
		.AddTest(new UnitTest(163, "Test of array swaps", TestArraySwaps))

		.AddTest(new UnitTest(201, "Test of list insertion", TestListInsertions))
		.AddTest(new UnitTest(202, "Test of getting subsequence from list", TestListSubsequence))
		.AddTest(new UnitTest(203, "Test of list concatenation", TestListConcatenation))
		.AddTest(new UnitTest(251, "Test of list Map function", TestListMap))
		.AddTest(new UnitTest(252, "Test of list Where function", TestListWhere))
		.AddTest(new UnitTest(253, "Test of list Reduce function", TestListReduce))
		.AddTest(new UnitTest(263, "Test of list swaps", TestListSwaps))

		.AddTest(new UnitTest(301, "Test of constant number generator", TestConstantNumberGenerator))
		.AddTest(new UnitTest(302, "Test of consecutive number generator", TestConsecutiveNumberGenerator))
		.AddTest(new UnitTest(303, "Test of reverse number generator", TestReverseNumberGenerator))
		.AddTest(new UnitTest(304, "Test of random number generator", TestRandomNumberGenerator))

		.AddTest(new UnitTest(401, "Test of constant sequence generator", TestConstantSequence))
		.AddTest(new UnitTest(402, "Test of consecutive sequence generator", TestConsecutiveSequence))
		.AddTest(new UnitTest(403, "Test of reverse sequence generator", TestReverseSequence))
		.AddTest(new UnitTest(404, "Test of random sequence generator", TestRandomSequence))

		;

		
}
