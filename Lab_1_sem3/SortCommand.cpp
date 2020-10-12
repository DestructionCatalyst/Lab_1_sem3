#include "SortCommand.h"

namespace ui
{
	void SortCommand::Execute(string args)
	{
		string sorterArg = getFirstWord(args);

		string indexStr = getFirstWord(args);
		int index = atoi(indexStr.c_str());

		if ((index <= 0) || (index > sequencesVector->size()))
			std::cout << "No sequence with such index!" << std::endl;
		else
		{
			SorterArgument(sequencesVector->at(index - 1), sorterArg).Sort();
			std::cout << "Sorted sequence " << index << std::endl;
		}
	}
}