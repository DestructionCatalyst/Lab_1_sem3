#include "ParseFunctions.h"

string getFirstWord(string& str, string separators)
{
	auto firstSpace = str.find_first_of(separators);

	string cmd = str.substr(0, firstSpace);

	if (firstSpace != string::npos)
		str = str.substr(firstSpace + 1);
	else
		str = "";

	return cmd;
}
