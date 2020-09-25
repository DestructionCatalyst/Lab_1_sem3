#include "SequenceGeneratorTest.h"



void TestConstantSequence()
{
	Sequence<int>* arr = new ArraySequence<int>(new ConstantNumberGenerator(1000), 5);
	Sequence<int>* list = new ListSequence<int>(new ConstantNumberGenerator(1357), 3);

	AssertSequenceEquals({ 1000, 1000, 1000, 1000, 1000 }, arr);
	AssertSequenceEquals({ 1357, 1357, 1357 }, list);

	delete(arr);
	delete(list);
}

void TestConsecutiveSequence()
{
	Sequence<int>* arr = new ArraySequence<int>(new ConsecutiveNumberGenerator(0), 10);
	Sequence<int>* list = new ListSequence<int>(new ConsecutiveNumberGenerator(50), 7);

	AssertSequenceEquals({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, arr);
	//std::cout << list->GetFirst() << " " << list->GetLast() << std::endl;
	AssertSequenceEquals({ 50, 51, 52, 53, 54, 55, 56 }, list);

	delete(arr);
	delete(list);
}

void TestReverseSequence()
{
	Sequence<int>* arr = new ArraySequence<int>(new ReverseNumberGenerator(200), 7);
	Sequence<int>* list = new ListSequence<int>(new ReverseNumberGenerator(10), 10);

	AssertSequenceEquals({ 200, 199, 198, 197, 196, 195, 194 }, arr);
	AssertSequenceEquals({ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, list);

	delete(arr);
	delete(list);
}

void TestRandomSequence()
{//1410 66 20318 16484 15600 22623 4875 15246 31270 4328

	Sequence<int>* arr = new ArraySequence<int>(new RandomNumberGenerator(420), 10);

	AssertSequenceEquals({ 1410, 66, 20318, 16484, 15600, 22623, 4875, 15246, 31270, 4328 }, arr);

	delete(arr);
}
