#include "DeleteCommand.h"

namespace ui
{
	void DeleteCommand::Execute(string args)
	{
		string lengthStr = getFirstWord(args);
		int index = atoi(lengthStr.c_str());

		if ((index <= 0) || (index > sequencesVector->size()))
			std::cout << "No sequence with such index!" << std::endl;
		else
		{
			sequencesVector->erase(sequencesVector->begin() + (index - 1));
			std::cout << "Deleted sequence " << index << std::endl;
		}
	}
}