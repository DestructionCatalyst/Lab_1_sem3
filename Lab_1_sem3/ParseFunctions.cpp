#include "ParseFunctions.h"

string getFirstWord(string& str)
{
	auto firstSpace = str.find_first_of(" ");

	string cmd = str.substr(0, firstSpace);

	if (firstSpace != string::npos)
		str = str.substr(firstSpace + 1);
	else
		str = "";

	return cmd;
}
