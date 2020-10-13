#include "TestCommand.h"

namespace ui {
	void TestCommand::Execute(string args)
	{
		string testArg = getFirstWord(args);

		string generatorArg = getFirstWord(args);

		int iterations = atoi(getFirstWord(args).c_str());
		int step = atoi(getFirstWord(args).c_str());

		if (iterations <= 0)
			throw std::invalid_argument("Invalid iterations number");
		if (step <= 0)
			throw std::invalid_argument("Invalid step number");

		if (testArg == "sequence")
		{
			TestEnvironment env{};

			InitializeTests(env);

			env.RunAll();
		}
		else
		{
			SorterTest::PerformanceTest(step, iterations + 1,
				[&](int length) -> ISorter<int>*
				{
					return SorterArgument(
						GeneratorArgument(generatorArg, length, false).GenerateSequence(),
						testArg
						).GetSorter();
				}
			);
			
			std::cout << std::endl;
		}
	}
}