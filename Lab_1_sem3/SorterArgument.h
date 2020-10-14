#pragma once
#include <string>
#include <stdexcept>

#include "ISorter.h"
#include "Sequence.h"
#include "MergeSorter.h"
#include "QuickSorter.h"

#include "ShellSorter.h"
#include "ShellPartition.h"
#include "HibbardPartition.h"

#include "CommandArgument.h"
#include "ParseFunctions.h"

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

