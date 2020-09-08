#include <iostream>

#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "ListSequence.h"

using namespace std;
using namespace sequences;

void testArray() {

	int a[] = { 1, 3, 5, 79, 0 };

	DynamicArray<int> arr(a, 5);

	cout << arr.Get(0) << " " << arr.Get(1) << " " << arr.Get(2) << " " << arr.Get(3) << " " << arr.Get(4) << endl;

	cout << arr.Get(3) << " ";
	cout << arr.GetCapacity() << endl;

	arr.Set(66, 2);

	arr.Resize(7);

	cout << arr.Get(2) << " " << arr.GetCapacity() << endl;

}

void testList() {

	int a[] = { 1, 3, 5, 79, 0 };

	LinkedList<int> list(a, 5);

	cout << list.Get(0) << " " << list.Get(1) << " " << list.Get(2) << " " << list.Get(3) << " " << list.Get(4) << endl;

	list.Append(100);
	list.InsertAt(2, 1);

	cout << list.Get(0) << " " << list.Get(1) << " " << list.Get(2) << " " << list.Get(3) << " " << list.Get(4)
		<< " " << list.Get(5) << " " << list.Get(6) << endl;
}

void testArraySequence() {
	int a[5] = { 1, 3, 5, 7, 9 };
	ArraySequence<int>* list = new ArraySequence<int>();

	list->Append(5);
	list->Append(10);
	list->Prepend(1);
	list->InsertAt(2, 2);
	list->InsertAt(100, 1);

	ArraySequence<int>* list2 = new ArraySequence<int>(a, 5);
	ArraySequence<int>* subList = dynamic_cast<ArraySequence<int>*>(list2->GetSubsequence(1, 3));
	ArraySequence<int>* list1 = new ArraySequence<int>(*subList);
	ArraySequence<int>* list3 = dynamic_cast<ArraySequence<int>*>(list->Concat(subList));
	ArraySequence<int>* list4 = dynamic_cast<ArraySequence<int>*>(list3->Map(
		[](int a) -> int
		{
			return a / 2;
		}
	));
	ArraySequence<int>* list5 = dynamic_cast<ArraySequence<int>*>(list3->Where(
		[](int a) -> bool
		{
			return a % 2 != 0;
		}
	));
	int prod = list5->Reduce(
		[](int a1, int a2) -> int
		{
			return a1 * a2;
		}
		, 1
			);
	list5->Append(0);
	list5->Append(0);
	list5->Append(0);

	cout << "Array operations test:" << endl;
	cout << "Expected output:" << endl;
	cout << "1 100 5 2 10 3 5 7" << endl;
	cout << "Program output:" << endl;
	cout << list3->GetFirst() << " " << list3->Get(1) << " " << list3->Get(2) << " " << list3->Get(3)
		<< " " << list3->Get(4) << " " << list3->Get(5) << " " << list3->Get(6) << " " << list3->GetLast() << endl;
	cout << endl;

	cout << "Map function test:" << endl;
	cout << "Expected output:" << endl;
	cout << "0 50 2 1 5 1 2 3" << endl;
	cout << "Program output:" << endl;
	cout << list4->GetFirst() << " " << list4->Get(1) << " " << list4->Get(2) << " " << list4->Get(3)
		<< " " << list4->Get(4) << " " << list4->Get(5) << " " << list4->Get(6) << " " << list4->GetLast() << endl;
	cout << endl;

	cout << "Where function test:" << endl;
	cout << "Expected output:" << endl;
	cout << "1 5 3 5 7" << endl;
	cout << "Program output:" << endl;
	cout << list5->GetFirst() << " " << list5->Get(1) << " " << list5->Get(2) << " " << list5->Get(3)
		<< " " << list5->Get(4) << endl;
	cout << endl;

	cout << "Reduce function test:" << endl;
	cout << "Expected output:" << endl;
	cout << 525 << endl;
	cout << "Program output:" << endl;
	cout << prod << endl;
	cout << endl;
}

void testListSequence() {
	int a[5] = { 1, 3, 5, 7, 9 };
	ListSequence<int>* list = new ListSequence<int>();

	list->Append(5);
	list->Append(10);
	list->Prepend(1);
	list->InsertAt(2, 2);
	list->InsertAt(100, 1);

	//cout << list->GetFirst() << " " << list->Get(1) << " " << list->Get(2) << " " << list->Get(3) << " " << list->GetLast() << endl;
	ListSequence<int>* list2 = new ListSequence<int>(a, 5);
	ListSequence<int>* subList = dynamic_cast<ListSequence<int>*>(list2->GetSubsequence(1, 3));
	ListSequence<int>* list1 = new ListSequence<int>(*subList);
	ListSequence<int>* list3 = dynamic_cast<ListSequence<int>*>(list->Concat(subList));
	ListSequence<int>* list4 = dynamic_cast<ListSequence<int>*>(list3->Map(
		[](int a) -> int
		{
			return a / 2;
		}
	));
	ListSequence<int>* list5 = dynamic_cast<ListSequence<int>*>(list3->Where(
		[](int a) -> bool
		{
			return a % 2 == 0;
		}
	));
	int prod = list5->Reduce(
		[](int a1, int a2) -> int
		{
			return a1 * a2;
		}
		, 1
			);


	cout << "List operations test:" << endl;
	cout << "Expected output:" << endl;
	cout << "1 100 5 2 10 3 5 7" << endl;
	cout << "Program output:" << endl;
	cout << list3->GetFirst() << " " << list3->Get(1) << " " << list3->Get(2) << " " << list3->Get(3)
		<< " " << list3->Get(4) << " " << list3->Get(5) << " " << list3->Get(6) << " " << list3->GetLast() << endl;
	cout << endl;

	cout << "Map function test:" << endl;
	cout << "Expected output:" << endl;
	cout << "0 50 2 1 5 1 2 3" << endl;
	cout << "Program output:" << endl;
	cout << list4->GetFirst() << " " << list4->Get(1) << " " << list4->Get(2) << " " << list4->Get(3)
		<< " " << list4->Get(4) << " " << list4->Get(5) << " " << list4->Get(6) << " " << list4->GetLast() << endl;
	cout << endl;

	cout << "Where function test:" << endl;
	cout << "Expected output:" << endl;
	cout << "100 2 10" << endl;
	cout << "Program output:" << endl;
	cout << list5->GetFirst() << " " << list5->Get(1) << " " << list5->Get(2) << endl;
	cout << endl;

	cout << "Reduce function test:" << endl;
	cout << "Expected output:" << endl;
	cout << 2000 << endl;
	cout << "Program output:" << endl;
	cout << prod << endl;
	cout << endl;
}

int main() {

	testArray();
	testList();
	testArraySequence();
	testListSequence();
}

