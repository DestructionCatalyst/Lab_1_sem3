#pragma once

template<class T>
int defaultCompare(T item1, T item2)
{
	if (item1 < item2)
		return 1;
	else if (item1 == item2)
		return 0;
	else
		return -1;
}

template<class T>
int inverseCompare(T item1, T item2)
{
	if (item1 > item2)
		return 1;
	else if (item1 == item2)
		return 0;
	else
		return -1;
}
