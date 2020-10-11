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
		
		string cmd = getFirstWord(command);

		if (commands.find(cmd) != commands.end())
		{
			try
			{
				commands[cmd]->Execute(command);
			}
			catch (std::invalid_argument e)
			{
				CommandError(e);
			}
			
		}	
		else
			CommandNotFound(cmd);

	}

	void CommandParser::CommandNotFound(string str)
	{
		std::cout << "Command " << str << " not found! To see the list of commands, type help" << std::endl;
	}

	void CommandParser::CommandError(std::exception ex)
	{
		std::cout << "Error executing command: " << ex.what() << std::endl;
	}

}