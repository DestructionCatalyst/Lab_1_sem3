#pragma once
#include "CommandArgument.h"

#include <string>
#include <stdexcept>

#include "INumberGenerator.h"
#include "ConstantNumberGenerator.h"
#include "ConsecutiveNumberGenerator.h"
#include "ReverseNumberGenerator.h"
#include "RandomNumberGenerator.h"

#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"

using std::string;
using sequences::Sequence;

namespace ui {

	class GeneratorArgument :
		public CommandArgument
	{
	private:
		INumberGenerator* numGen;

		int length;
		bool isList;
	public:
		GeneratorArgument(string type, int length, bool isList = false);

		Sequence<int>* GenerateSequence();
	};

}