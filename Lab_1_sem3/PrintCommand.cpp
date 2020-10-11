#include "PrintCommand.h"

namespace ui
{
	void PrintCommand::Execute(string args)
	{

		string lengthStr = getFirstWord(args);
		int index = atoi(lengthStr.c_str());

		if (index <= 0)
			for (int i = 0; i < sequencesVector->size(); i++) {

				std::cout << i + 1 << ") ";
				PrintSequence(i);
			}
		else
			PrintSequence(index - 1);
	}

	void PrintCommand::PrintSequence(int index)
	{
		if (index <= sequencesVector->size())
			(*sequencesVector)[index]->Print();
		else
			std::cout << "No sequence with such index!" << std::endl;
	}
}