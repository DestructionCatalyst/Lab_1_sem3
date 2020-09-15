#pragma once

#include <stdexcept>

#include "Node.h"
#include "ListIterator.h"
#include "MutableListIterator.h"

namespace sequences {

	template<class T> class LinkedList {
	private:
		typedef sequences::iterators::ListIterator<T> const_iterator;
		typedef sequences::iterators::MutableListIterator<T> iterator;

	private:
		Node<T>* head;
		Node<T>* tail;
	
		int length;
	public:
		LinkedList():
			head(nullptr), tail(nullptr), length(0)
		{}
		LinkedList(T* items, int count):
			LinkedList()
		{
			for (int i = 0; i < count; i++) {
				Append(items[i]);
			}
		}
		
		LinkedList(const LinkedList <T>& list):
			LinkedList()
		{
			const_iterator itr = *list.begin_();
			
			for (; itr != *list.end_(); ++itr) {
				Append(T(*itr));
			}
		}
		//TODO конструктор с initializer list
	public:
		T GetFirst() const
		{
			if (length != 0)
				return head->GetContent();
			else throw std::out_of_range("List is empty!");
		}
		T GetLast() const
		{
			if (length != 0)
				return tail->GetContent();
			else throw std::out_of_range("List is empty!");
		}
		T Get(int index) const
		{
			if ((length != 0) && (index >= 0) && (index < length)) {
				
				return **itemIterator_(index);
			}
			else
				throw std::out_of_range("List index is out of bounds");
		}
		//Copies selected part of the list
		LinkedList<T>* GetSubList(int startIndex, int endIndex) const
		{
			if ((startIndex <= endIndex) && (startIndex >= 0) && (endIndex < length)) {
				LinkedList<T>* subList = new LinkedList<T>();
				const_iterator itr = *itemIterator_(startIndex);

				for (int i = startIndex; i <= endIndex; ++i, ++itr) {
					subList->Append(T(*itr));
				}

				return subList;
			}
			else
				throw std::out_of_range("List index is out of bounds");
		}
		int GetLength() const
		{
			return length;
		}
	public:
		void Append(T item)
		{
			Node<T>* last = new Node<T>(item, nullptr);

			if (length == 0) {
				tail = last;
				head = tail;
			}
			else {
				tail->SetNext(last);
				tail = last;
			}
			++length;
		}
		void Prepend(T item) 
		{
			head = new Node<T>(item, head);
			if (length == 0)
				tail = head;
			++length;
		}
		void InsertAt(T item, int index)
		{
			if (index == 0)
				Prepend(item);
			else if (index == length)
				Append(item);
			else if ((index > 0) && (index < length)) {

				iterator itr = itemIterator(index - 1);

				itr.SetNext(new Node<T>(item, itr.GetNextPointer()));

				++length;
			}
			else
				throw std::out_of_range("List index is out of bounds");
		}
		LinkedList<T>* Concat(LinkedList<T>* list) //const?
		{
			LinkedList<T>* bigList = new LinkedList(*this);

			LinkedList<T>* tailList = new LinkedList(*list);
			
			bigList->tail->SetNext(tailList->head);

			bigList->tail = tailList->tail;
			
			return bigList;
		}
	public:
		const_iterator* begin_() const
		{
			return new const_iterator(head);
		}
		const_iterator* end_() const
		{
			return new const_iterator(tail->Next());
		}
		const_iterator* itemIterator_(int index) const
		{
			const_iterator* itr = begin_();

			for (int i = 0; i < index; i++)
				++(*itr);

			return itr;
		}
	public:
		iterator begin() 
		{
			return iterator(head);
		}
		iterator end() 
		{
			return iterator(tail->Next());
		}
		iterator itemIterator(int index)
		{
			iterator itr = begin();

			for (int i = 0; i < index; i++)
				++itr;

			return itr;
		}
	public:
		~LinkedList() {
			delete(head);
		}
	
	};
}