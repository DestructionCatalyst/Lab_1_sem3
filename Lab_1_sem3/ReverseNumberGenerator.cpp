#include "ReverseNumberGenerator.h"

ReverseNumberGenerator::ReverseNumberGenerator(int startNumber) :
	INumberGenerator(), numberToReturn(startNumber)
{}

int ReverseNumberGenerator::NextInt()
{
	return numberToReturn--;
}