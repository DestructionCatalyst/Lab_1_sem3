#include "ExitCommand.h"

#include <iostream>

namespace ui {
	void ExitCommand::Execute(string args)
	{
		std::cout << args << std::endl;
		exit(0);
	}
}