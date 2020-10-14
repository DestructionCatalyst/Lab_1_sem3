#pragma once

#include <functional>

#include "ISorter.h"
#include "Comparators.h"
#include "Average.h"

#include "IPartition.h"
#include "ShellPartition.h"

template<class T>
class ShellSorter : public ISorter<T>
{
private:

	Sequence<T>* seq;
	ISorter<T>::comparator_t compare;

	IPartition* steps;
	
public:
	ShellSorter(Sequence<T>* toSort,
		IPartition* step = new ShellPartition(),
		ISorter<T>::comparator_t compare = defaultCompare<T>) :
		seq(toSort), compare(compare), steps(step)
	{}

	Sequence<T>* Sort() override
	{
		for(int step = steps->SetStartValue(seq->GetLength()); step > 0; step = steps->NextStepLength())//Step selection
			for (int i = step; i < seq->GetLength(); i++)
			{		
				int j = i - step;

				while ((j >= 0) && (compare(seq->Get(j), seq->Get(j + step)) < 0
					))
				{
					seq->Swap(j, j + step);
					j -= step;
				}
				
			}

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
};



