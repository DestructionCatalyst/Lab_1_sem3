#pragma once

#include <vector>
#include <iostream>

#include "Command.h"
#include "Sequence.h"

#include "ParseFunctions.h"

using std::vector;
using sequences::Sequence;

namespace ui
{
	class PrintCommand :
		public Command
	{
	private:

		vector<Sequence<int>*>* sequencesVector;

	public:
		static constexpr char name[6] = "print";

	public:
		PrintCommand(vector<Sequence<int>*>* vec) :
			sequencesVector(vec)
		{}

		void Execute(string args) override;
	private:
		void PrintSequence(int index);
	};
}
