#pragma once
#include <map>
#include <string>
#include <utility>

#include "Command.h"

#include "ExitCommand.h"

using std::map;
using std::string;

namespace ui {

	class CommandParser
	{
	private:

		map<string, Command*> commands{};

	public:

		CommandParser();

		void parse(string command);

	private:

		virtual void CommandNotFound(string command);
	};

}