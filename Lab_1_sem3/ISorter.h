#pragma once

#include <functional>

#include "Sequence.h"

using namespace sequences;

template <class T>
class ISorter
{
public:
	typedef std::function<int(T, T)> comparator_t;

	virtual Sequence<T>* Sort(/*comparator_t compare = defaultCompare<T>*/) = 0;

	virtual int GetSequenceLength() const = 0;
	virtual Sequence<T>* GetSequence() = 0;

	virtual ~ISorter() {};
};