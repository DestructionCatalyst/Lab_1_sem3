#pragma once
#include <string>
#include <stdexcept>

#include "ISorter.h"
#include "Sequence.h"
#include "MergeSorter.h"
#include "QuickSorter.h"

#include "CommandArgument.h"

using std::string;
using sequences::Sequence;

namespace ui {
	class SorterArgument :
		public CommandArgument
	{
	private:
		ISorter<int>* iSorter;
	public:
		SorterArgument(Sequence<int>* toSort, string sorter);

		void Sort();
		ISorter<int>* GetSorter();
	};
}

