#include "ArraySequenceTests.h"

void TestArrayInsertions()
{
	Sequence<int>* arr = new ArraySequence<int>();

	arr->Append(5);
	arr->Append(10);
	arr->Prepend(1);
	arr->InsertAt(2, 2);
	arr->InsertAt(100, 1);

	AssertSequenceEquals({ 1, 100, 5, 2, 10 }, arr);

	delete(arr);
}

void TestArraySubsequence()
{
	Sequence<int>* arr = new ArraySequence<int>({ 1, 3, 5, 7, 9 });
	Sequence<int>* subArray = arr->GetSubsequence(1, 3);
	Sequence<int>* startSubArray = arr->GetSubsequence(0, 2);
	Sequence<int>* endSubArray = arr->GetSubsequence(2, 4);

	AssertSequenceEquals({ 3, 5, 7 }, subArray);
	AssertSequenceEquals({ 1, 3, 5 }, startSubArray);
	AssertSequenceEquals({ 5, 7, 9 }, endSubArray);

	delete(arr);
	delete(subArray);
	delete(startSubArray);
	delete(endSubArray);
}

void TestArrayConcatenation()
{
	Sequence<int>* arr = new ArraySequence<int>({ 1, 100, 5, 2, 10 });
	Sequence<int>* arr1 = new ArraySequence<int>({ 3, 5, 7 });
	Sequence<int>* bigArr = arr->Concat(arr1);

	AssertSequenceEquals({ 1, 100, 5, 2, 10, 3, 5, 7 }, bigArr);

	delete(arr);
	delete(arr1);
	delete(bigArr);
}

void TestArrayMap()
{
	Sequence<int>* arr = new ArraySequence<int>({ 1, 100, 5, 2, 10, 3, 5, 7 });

	Sequence<int>* newArr = arr->Map(
		[](int a) -> int
		{
			return a / 2;
		}
	);

	AssertSequenceEquals({ 0, 50, 2, 1, 5, 1, 2, 3 }, newArr);

	delete(arr);
	delete(newArr);
}

void TestArrayWhere()
{
	Sequence<int>* arr = new ArraySequence<int>({ 1, 100, 5, 2, 10, 3, 5, 7 });

	Sequence<int>* newArr = arr->Where(
		[](int a) -> bool
		{
			return a % 2 != 0;
		}
	);

	AssertSequenceEquals({ 1, 5, 3, 5, 7 }, newArr);

	delete(arr);
	delete(newArr);
}

void TestArrayReduce()
{
	Sequence<int>* arr = new ArraySequence<int>({ 1, 5, 3, 5, 7 });

	int prod = arr->Reduce(
		[](int a1, int a2) -> int
		{
			return a1 * a2;
		}
		, 1
			);

	TestEnvironment::Assert(prod == 525);

	delete(arr);
}
