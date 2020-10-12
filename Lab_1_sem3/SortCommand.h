#pragma once

#include <vector>
#include <iostream>

#include "Command.h"
#include "Sequence.h"
#include "ParseFunctions.h"

#include "SorterArgument.h"

using std::vector;
using sequences::Sequence;

namespace ui
{
	class SortCommand: public Command
	{
	private:
		vector<Sequence<int>*>* sequencesVector;

	public:
		static constexpr char name[5] = "sort";

	public:
		SortCommand(vector<Sequence<int>*>* vec) :
			sequencesVector(vec)
		{}

		void Execute(string args) override;
	};

}