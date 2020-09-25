#include "NumberGeneratorTests.h"

void TestConstantNumberGenerator()
{
	INumberGenerator* gen = new ConstantNumberGenerator(5);

	TestEnvironment::Assert(gen->NextItem() == 5);

	delete(gen);
}
void TestConsecutiveNumberGenerator()
{
	INumberGenerator* gen = new ConsecutiveNumberGenerator(5);

	TestEnvironment::Assert(gen->NextItem() == 5);
	TestEnvironment::Assert(gen->NextItem() == 6);
	TestEnvironment::Assert(gen->NextItem() == 7);
	gen->NextItem();
	gen->NextItem();
	TestEnvironment::Assert(gen->NextItem() == 10);

	delete(gen);
}
void TestReverseNumberGenerator()
{
	INumberGenerator* gen = new ReverseNumberGenerator(100);

	TestEnvironment::Assert(gen->NextItem() == 100);
	TestEnvironment::Assert(gen->NextItem() == 99);
	TestEnvironment::Assert(gen->NextItem() == 98);
	gen->NextItem();
	gen->NextItem();
	TestEnvironment::Assert(gen->NextItem() == 95);

	delete(gen);
}
void TestRandomNumberGenerator()
{//8682 28463 263
	INumberGenerator* gen = new RandomNumberGenerator(69);

	TestEnvironment::Assert(gen->NextItem() == 263);
	TestEnvironment::Assert(gen->NextItem() == 28463);
	TestEnvironment::Assert(gen->NextItem() == 8682);

	delete(gen);
}
