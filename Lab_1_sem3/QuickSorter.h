#pragma once

#include "ISorter.h"
#include "Average.h"

template<class T>
class QuickSorter : public ISorter<T>
{
private:
	Sequence<T>* seq;
	ISorter<T>::comparator_t _compare;
public:
	QuickSorter(Sequence<T>* toSort, ISorter<T>::comparator_t compare = defaultCompare<T>) :
		seq(toSort), _compare(compare)
	{}

	Sequence<T>* Sort() override
	{
		SortSubsequence(0, seq->GetLength() - 1);

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
		int pivot = findPivot(start, end);

		int left = start;
		int right = end;

		while (left <= right)
		{
			//Find item before the pivot and more than it
			while (seq->Get(left) < pivot)
				++left;

			//Find item after the pivot and less than it
			while (seq->Get(right) > pivot)
				--right;

			//Swap them
			if (left <= right)
			{
				seq->Swap(left, right);

				++left;
				--right;
			}
		}

		//seq->Print();

		//Sort parts recursively
		if ((start < right))
			SortSubsequence(start, right);
		if (end > left)
			SortSubsequence(right + 1, end);
	}

	

protected:
	virtual int findPivot(int start, int end)
	{
		//return seq->Get(average(0, seq->GetLength()));
		return median3(seq->Get(start), seq->Get(end), seq->Get(average(start, end)));
	}

};