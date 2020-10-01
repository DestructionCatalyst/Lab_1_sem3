#include "Average.h"

int average(int a, int b)
{
	return (a + b) / 2;
}

int median3(int a, int b, int c)
{
	if (a > b)
		std::swap(a, b);
	if (b > c)
		std::swap(b, c);
	if (a > b)
		std::swap(a, b);

	return b;
}