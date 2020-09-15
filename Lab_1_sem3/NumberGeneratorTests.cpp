#include "NumberGeneratorTests.h"

void TestConstantNumberGenerator()
{
	INumberGenerator* gen = new ConstantNumberGenerator(5);

	TestEnvironment::Assert(gen->NextInt() == 5);

	delete(gen);
}
void TestConsecutiveNumberGenerator()
{
	INumberGenerator* gen = new ConsecutiveNumberGenerator(5);

	TestEnvironment::Assert(gen->NextInt() == 5);
	TestEnvironment::Assert(gen->NextInt() == 6);
	TestEnvironment::Assert(gen->NextInt() == 7);
	gen->NextInt();
	gen->NextInt();
	TestEnvironment::Assert(gen->NextInt() == 10);

	delete(gen);
}
void TestReverseNumberGenerator()
{
	INumberGenerator* gen = new ReverseNumberGenerator(100);

	TestEnvironment::Assert(gen->NextInt() == 100);
	TestEnvironment::Assert(gen->NextInt() == 99);
	TestEnvironment::Assert(gen->NextInt() == 98);
	gen->NextInt();
	gen->NextInt();
	TestEnvironment::Assert(gen->NextInt() == 95);

	delete(gen);
}
void TestRandomNumberGenerator()
{//8682 28463 263
	INumberGenerator* gen = new RandomNumberGenerator(69);

	TestEnvironment::Assert(gen->NextInt() == 263);
	TestEnvironment::Assert(gen->NextInt() == 28463);
	TestEnvironment::Assert(gen->NextInt() == 8682);

	delete(gen);
}
