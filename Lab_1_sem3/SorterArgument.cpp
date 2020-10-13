#include "SorterArgument.h"

namespace ui {
	SorterArgument::SorterArgument(Sequence<int>* toSort, string sorter)
	{
		if (sorter == "merge")
			iSorter = new MergeSorter<int>(toSort);
		else if (sorter == "quick")
			iSorter = new QuickSorter<int>(toSort);
		else if (sorter == "shell")
			iSorter = new ShellSorter<int>(toSort);
		else
			throw std::invalid_argument(sorter + " is not a valid sorter argument!");
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