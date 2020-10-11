#include "CreateCommand.h"


namespace ui {

	void CreateCommand::Execute(string args)
	{
		string type = getFirstWord(args);

		string lengthStr = getFirstWord(args);
		int len = atoi(lengthStr.c_str());

		if (len <= 0)
			throw std::invalid_argument(lengthStr + " is not a valid length argument!");

		string seqTypeStr = getFirstWord(args);

		bool isList = false;

		if (seqTypeStr == "list")
			isList = true;

		sequences->push_back(GeneratorArgument(type, len, isList).GenerateSequence());

	}
}