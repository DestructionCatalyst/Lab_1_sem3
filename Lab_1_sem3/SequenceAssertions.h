#pragma once

#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "SequenceIterator.h"

#include "TestEnvironment.h"

using namespace sequences;
using namespace sequences::iterators;

template<class T>
void AssertSequenceEquals(Sequence<T>* expected, Sequence<T>* actual)
{
	if (expected == actual)
		return;

	TestEnvironment::Assert((expected->GetLength()) == (actual->GetLength()));

	SequenceIterator<T>* expectedIter = expected->begin();
	SequenceIterator<T>* actualIter = actual->begin();

	for (; (*expectedIter != *expected->end()) && (*actualIter != *actual->end());
		++(*expectedIter), ++(*actualIter)) {
		TestEnvironment::Assert((**expectedIter) == (**actualIter));
	}

}

template<class T>
void AssertSequenceEquals(std::initializer_list<T> expected, Sequence<T>* actual)
{
	TestEnvironment::Assert((expected.size()) == (actual->GetLength()));

	auto expectedIter = expected.begin();
	SequenceIterator<T>* actualIter = actual->begin();

	for (; (expectedIter != expected.end()) && (*actualIter != *actual->end());
		++(expectedIter), ++(*actualIter)) {
		TestEnvironment::Assert((*expectedIter) == (**actualIter));
	}
}