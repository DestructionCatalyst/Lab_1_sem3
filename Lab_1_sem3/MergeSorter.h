#pragma once

#include <functional>

#include "ISorter.h"
#include "Comparators.h"
#include "Average.h"

template<class T>
class MergeSorter: public ISorter<T>
{
private:
	Sequence<T>* seq;
	ISorter<T>::comparator_t _compare;

	Sequence<T>* merged;
public:
	MergeSorter(Sequence<T>* toSort, ISorter<T>::comparator_t compare = defaultCompare<T>):
		seq(toSort), _compare(compare)
	{
		merged = new ArraySequence<T>(toSort->GetLength());
	}

	Sequence<T>* Sort() override
	{
		//seq->Print();
		SortSubsequence(0, seq->GetLength() - 1);
		//seq->Print();
		return seq;
	}

	int GetSequenceLength() const override
	{
		return seq->GetLength();
	}
	Sequence<T>* GetSequence() override
	{
		return seq;
	}
private:

	void SortSubsequence(int start, int end)
	{
		if (start < end)
		{


			SortSubsequence(start, average(start, end));
			SortSubsequence(average(start, end) + 1, end);

			Merge(start, end);
		}
	}

	void Merge(int start, int end)
	{

		int middle = average(start, end);
		int firstIndex = start;
		int secondIndex = middle + 1;

		auto takeFrom{
			[=](int& index) -> void
			{
				merged->Append(seq->Get(index));
				++index;
			}
		};

		for (int i = start; i <= end; i++)
		{

			if (firstIndex > middle)
				takeFrom(secondIndex);
			else if (secondIndex > end)
				takeFrom(firstIndex);
			else if (_compare(seq->Get(firstIndex), seq->Get(secondIndex)) >= 0)
				takeFrom(firstIndex);
			else
				takeFrom(secondIndex);
			
		}

		for (int i = start; i <= end; i++)
		{
			seq->Set(merged->Get(i - start), i);
		}
			
		dynamic_cast<ArraySequence<T>*>(merged)->Clear();
	}

	~MergeSorter() override
	{
		delete(seq);
	}
	
};

