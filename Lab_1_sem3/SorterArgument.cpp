#include "SorterArgument.h"

namespace ui {
	SorterArgument::SorterArgument(Sequence<int>* toSort, string sorter)
	{
		if (sorter == "merge")
			iSorter = new MergeSorter<int>(toSort);
		else if (sorter == "quick")
			iSorter = new QuickSorter<int>(toSort);
		else {
			string shouldBeShell = getFirstWord(sorter, "_");

			IPartition* step;

			if (sorter == "hibbard")
				step = new HibbardPartition();
			else
				step = new ShellPartition();

			if (shouldBeShell == "shell")
				iSorter = new ShellSorter<int>(toSort, step);
			else
				throw std::invalid_argument(sorter + " is not a valid sorter argument!");
		}
		
	}

	void SorterArgument::Sort()
	{
		iSorter->Sort();
	}
	
ISorter<int>* SorterArgument::GetSorter()
	{
		return iSorter;
	}
}