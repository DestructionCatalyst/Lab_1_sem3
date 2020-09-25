#include "ListSequenceTests.h"

void TestListInsertions()
{
	Sequence<int>* list = new ListSequence<int>();

	list->Append(5);
	list->Append(10);
	list->Prepend(1);
	list->InsertAt(2, 2);
	list->InsertAt(100, 1);

	AssertSequenceEquals({ 1, 100, 5, 2, 10 }, list);

	delete(list);
}

void TestListSubsequence()
{
	Sequence<int>* list = new ListSequence<int>({ 1, 3, 5, 7, 9 });
	Sequence<int>* subList = list->GetSubsequence(1, 3);
	Sequence<int>* startSubList = list->GetSubsequence(0, 2);
	Sequence<int>* endSubList = list->GetSubsequence(2, 4);

	AssertSequenceEquals({ 3, 5, 7 }, subList);
	AssertSequenceEquals({ 1, 3, 5 }, startSubList);
	AssertSequenceEquals({ 5, 7, 9 }, endSubList);

	delete(list);
	delete(subList);
	delete(startSubList);
	delete(endSubList);
}

void TestListConcatenation()
{
	Sequence<int>* list = new ListSequence<int>({ 1, 100, 5, 2, 10 });
	Sequence<int>* list1 = new ListSequence<int>({ 3, 5, 7 });
	Sequence<int>* bigList = list->Concat(list1);

	AssertSequenceEquals({ 1, 100, 5, 2, 10, 3, 5, 7 }, bigList);

	delete(list);
	delete(list1);
	delete(bigList);
}

void TestListMap()
{
	Sequence<int>* list = new ListSequence<int>({ 1, 100, 5, 2, 10, 3, 5, 7 });

	Sequence<int>* newList = list->Map(
		[](int a) -> int
		{
			return a / 2;
		}
	);

	AssertSequenceEquals({ 0, 50, 2, 1, 5, 1, 2, 3 }, newList);

	delete(list);
	delete(newList);
}

void TestListWhere()
{
	Sequence<int>* list = new ListSequence<int>({ 1, 100, 5, 2, 10, 3, 5, 7 });

	Sequence<int>* newList = list->Where(
		[](int a) -> bool
		{
			return a % 2 == 0;
		}
	);

	AssertSequenceEquals({ 100, 2, 10 }, newList);

	delete(list);
	delete(newList);
}

void TestListReduce()
{
	Sequence<int>* list = new ListSequence<int>({ 100, 2, 10 });

	int prod = list->Reduce(
		[](int a1, int a2) -> int
		{
			return a1 * a2;
		}
		, 1
			);

	TestEnvironment::Assert(prod == 2000);

	delete(list);
}

void TestListSwaps()
{
	Sequence<int>* list = new ListSequence<int>({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });

	list->Swap(2, 6);
	list->Swap(0, 8);
	list->Swap(9, 4);
	list->Swap(6, 4);

	AssertSequenceEquals({ 9, 2, 7, 4, 3, 6, 10, 8, 1, 5 }, list);
	TestEnvironment::Assert(list->GetLast() == 5);

	delete(list);

}