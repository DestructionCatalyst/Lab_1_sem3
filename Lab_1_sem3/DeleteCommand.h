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
	class DeleteCommand :
		public Command
	{
	private:
		vector<Sequence<int>*>* sequencesVector;

	public:
		static constexpr char name[7] = "delete";
		static constexpr char alias[6] = "erase";

	public:
		DeleteCommand(vector<Sequence<int>*>* vec) :
			sequencesVector(vec)
		{}

		void Execute(string args) override;
	};
}
