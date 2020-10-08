#include "CommandParser.h"

#include <iostream>

namespace ui {

	CommandParser::CommandParser()
	{

		//commands[ExitCommand::name] = new ExitCommand();
		//commands[ExitCommand::alias] = new ExitCommand();
	}

	void CommandParser::AddCommand(Command* cmd, std::initializer_list<std::string> names)
	{
		auto iter = names.begin();

		for (; iter != names.end(); ++iter)
		{
			commands[*iter] = cmd;
		}
	}

	void CommandParser::Parse(string command)
	{
		auto firstSpace = command.find_first_of(" ");
		
		string cmd = command.substr(0, firstSpace);

		string args = "";

		//std::cout << command << " " << firstSpace << " " << args << std::endl;


		if (firstSpace != string::npos)
			args = command.substr(firstSpace + 1);

		if (commands.find(cmd) != commands.end())
			commands[cmd]->Execute(args);
		else
			CommandNotFound(cmd);

	}

	void CommandParser::CommandNotFound(string str)
	{
		std::cout << "Command " << str << " not found! To see the list of commands, type help" << std::endl;
	}
}