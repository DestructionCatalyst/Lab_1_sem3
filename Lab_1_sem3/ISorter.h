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
	virtual int GetSequenceLength() = 0;

	virtual ~ISorter() {};
};