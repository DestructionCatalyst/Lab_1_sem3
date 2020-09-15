#include "ConstantNumberGenerator.h"

ConstantNumberGenerator::ConstantNumberGenerator(int number):
	INumberGenerator(), numberToReturn(number)
{}

int ConstantNumberGenerator::NextInt()
{
	return numberToReturn;
}