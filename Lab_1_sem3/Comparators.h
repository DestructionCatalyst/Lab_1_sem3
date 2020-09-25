#pragma once

template<class T>
int DefaultCompare(T item1, T item2)
{
	if (item1 < item2)
		return 1;
	else if (item1 = item2)
		return 0;
	else
		return -1;
}

template<class T>
int InverseCompare(T item1, T item2)
{
	if (item1 > item2)
		return 1;
	else if (item1 = item2)
		return 0;
	else
		return -1;
}
