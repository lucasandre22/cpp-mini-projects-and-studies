#include <iostream>
#pragma once

namespace List {
	template <class T>
	class List {
		template <class T2> friend class Iterator;
	private:
		template <class T1>
		class Node {
		private:
			T1 value;
			Node<T1>* next;
			Node<T1>* previous;
		public:
			Node(T1 value) { this->value = value; this->next = nullptr; this->previous = nullptr; }
			~Node() { }
			T1 GetValue() const { return this->value; }
			Node<T1>* GetNext() const { return this->next; }
			void SetNext(Node<T>* next) { this->next = next; }
			Node<T1>* GetPrevious() const { return this->previous; }
			void SetPrevious(Node<T>* previous) { this->previous = previous; }
		};
		Node<T>* head;
		Node<T>* tail;
		int size;
	public:
		List() { this->head = nullptr; this->size = 0; this->tail = nullptr; }
		~List() { Delete(); }
		void Delete() { for (Node<T>* aux = this->head; aux != nullptr; aux = this->head) { this->head = aux->GetNext(); delete aux; } this->head = nullptr; this->tail = nullptr; }
		void Include(T value);
		void push_back(T value);
		void Remove(T value);
		int GetSize() const { return this->size; }
		Node<T>* GetHead() const { return this->head; }
		Node<T>* GetFront() const { return this->head; }
		Node<T>* GetBack() const { return this->tail; }
		//friend bool operator!=(Iterator<T>& iterator, Node<T>& node);
	};

	template <class T2>
	class Iterator {
	private:
		List<T2>::Node<T2>* iterator;
		List<T2>* list;
	public:
		Iterator(List<T2>* list = nullptr) { this->list = list; this->iterator = nullptr; }
		~Iterator() { this->iterator = nullptr; this->list = nullptr; }
		void SetIteratorHead() { this->iterator = this->list->GetHead(); }
		void SetList(List<T2>& list) { this->list = &list; }
		T2 GetValue() const { return this->iterator->GetValue(); }
		bool IteratorNull() const { return this->iterator == nullptr ? true : false; }
		void Next() { this->iterator = this->iterator->GetNext(); }

		void operator=(List<T2>& list) { this->list = &list; }
		void operator=(List<T2>::Node<T2>* node) { this->iterator = node; }
		//List::Node<T2>* operator->() const { return this->iterator; }
		void operator++() { this->iterator = this->iterator->GetNext(); } //++iterator;
		void operator++(int) { this->iterator = this->iterator->GetNext(); } //iterator++;
		void operator--() { if(this->iterator->GetPrevious() != nullptr) this->iterator = this->iterator->GetPrevious(); } //--iterator;
		void operator--(int) { if(this->iterator->GetPrevious() != nullptr) this->iterator = this->iterator->GetPrevious(); }
		bool operator==(const List::Node<T2>& node) { return (this->iterator == node); }
		bool operator!=(const List::Node<T2>& node) { return !(this->iterator == node); }
		//friend bool operator!=(Iterator<T2>& iterator, List::Node<T2>& node);

		void ForEach(void(*ptr)(T2)) { for (SetIteratorHead(); !IteratorNull(); operator++()) { ptr(GetValue()); } }
		void ForEach(void(*ptr)()) { for (SetIteratorHead(); !IteratorNull(); operator++()) { ptr(); } }
		List<T2>::Node<T2>* Begin() { return this->list->GetFront(); }
		List<T2>::Node<T2>* Back() { return this->list->GetBack(); }
	};

	template <class T>
	void List<T>::Include(T value)
	{
		Node<T>* aux = new Node<T>(value);
		aux->SetNext(this->head);
		if (this->head)
			this->head->SetPrevious(aux);
		else
			this->tail = aux;
		this->head = aux;
		this->size++;
	}

	template <class T>
	void List<T>::push_back(T value)
	{
		Node<T>* aux = new Node<T>(value);
		aux->SetPrevious(this->tail);
		if (this->head == nullptr)
			this->head = aux;
		else //tail exists
			this->tail->SetNext(aux);
		this->tail = aux;
		this->size++;
	}

	template <class T>
	void List<T>::Remove(T value)
	{
		Node<T>* aux = this->head;
		for(; aux!=nullptr && aux->GetValue() != value; aux = aux->GetNext()) {}
		if (aux == nullptr)
			return;
		if (aux == this->tail)
			this->tail = aux->GetPrevious();
		if (aux->GetNext() != nullptr)
			aux->GetNext()->SetPrevious(aux->GetPrevious());
		if (aux->GetPrevious() != nullptr)
			aux->GetPrevious()->SetNext(aux->GetNext());
		if (this->head == aux)
			this->head = aux->GetNext();
		this->size--;
		delete aux;
	}

	//template<class T>
	//bool operator!=(Iterator<T>& iterator, Node<T>& node)
	//{
		//return !(iterator != node);
	//}
}


