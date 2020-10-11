#pragma once
#include "Command.h"

#include <cstdlib>
#include <vector>
#include <stdexcept>

#include "ParseFunctions.h"
#include "GeneratorArgument.h"
#include "Sequence.h"

using std::vector;
using sequences::Sequence;

namespace ui {

	class CreateCommand :
		public Command
	{
	private:
		
		vector<Sequence<int>*>* sequences;

	public:
		static constexpr char name[7] = "create";
		static constexpr char alias[9] = "generate";

	public:
		CreateCommand(vector<Sequence<int>*>* vec):
			sequences(vec)
		{}

		void Execute(string args) override;
	};

}