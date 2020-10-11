#include "GeneratorArgument.h"

namespace ui {

	GeneratorArgument::GeneratorArgument(string type, int length, bool isList):
		length(length), isList(isList)
	{
		if (type == "constant")
			numGen = new ConstantNumberGenerator(length / 2);
		else if (type == "consecutive")
			numGen = new ConsecutiveNumberGenerator(1);
		else if (type == "reverse")
			numGen = new ReverseNumberGenerator(length);
		else if (type == "random")
			numGen = new RandomNumberGenerator();
		else
			throw std::invalid_argument(type + " is not a valid creation argument!");
	}

	Sequence<int>* GeneratorArgument::GenerateSequence()
	{
		Sequence<int>* seq;

		if (isList)
			seq = new sequences::ListSequence<int>(numGen, length);
		else
			seq = new sequences::ArraySequence<int>(numGen, length);

		return seq;
	}
}