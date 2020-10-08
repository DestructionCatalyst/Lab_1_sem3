#pragma once
#include "Command.h"

namespace ui{

	class ExitCommand : public Command
	{
	
	public:
		static constexpr char name[5] = "exit" ;
		static constexpr char alias[5] = "quit";
		
		ExitCommand()
		{}

		void Execute(string args) override;
	};
}