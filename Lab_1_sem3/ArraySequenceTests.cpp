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
	Sequence<int>* subArr = arr->GetSubsequence(1, 3);

	AssertSequenceEquals({ 3, 5, 7 }, subArr);

	delete(arr);
	delete(subArr);
}