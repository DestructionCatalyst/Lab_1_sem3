#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

#include "Command.h"
#include "Sequence.h"
#include "ParseFunctions.h"

#include "SorterArgument.h"
#include "GeneratorArgument.h"

#include "TestEnvironment.h"
#include "Test.h"
#include "SorterTest.h"

using std::vector;
using sequences::Sequence;

namespace ui {
	class TestCommand :
		public Command
	{
	private:
		vector<Sequence<int>*>* sequencesVector;

	public:
		static constexpr char name[5] = "test";

	public:
		TestCommand(vector<Sequence<int>*>* vec) :
			sequencesVector(vec)
		{}

		void Execute(string args) override;
	};
}
