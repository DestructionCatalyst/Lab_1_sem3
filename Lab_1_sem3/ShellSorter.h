#pragma once

#include <functional>

#include "ISorter.h"
#include "Comparators.h"
#include "Average.h"

template<class T>
class ShellSorter : public ISorter<T>
{
private:
	typedef std::function<int(int)> next_step_t;

	Sequence<T>* seq;
	ISorter<T>::comparator_t compare;
	next_step_t nextStep;
	
public:
	ShellSorter(Sequence<T>* toSort,
		next_step_t nextStepSize = nextStepHalf,
		ISorter<T>::comparator_t compare = defaultCompare<T>) :
		seq(toSort), compare(compare), nextStep(nextStepSize)
	{}

	Sequence<T>* Sort() override
	{
		for(int step = nextStep(seq->GetLength()); step > 0; step = nextStep(step))//Step selection
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



