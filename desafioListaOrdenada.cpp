#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
namespace List {

	template <class T>
	class List {
	private:
		class Node {
		public:
			T key;
			Node* next;
			Node* previous;
			Node(T value) { this->key = value; this->next = nullptr; this->previous = nullptr; }
			~Node() {}
			T GetKey() { return this->key; }
		};
		Node* head;
		Node* current;
		int size;
	public:
		List() { this->head = nullptr; this->size = 0; this->current = nullptr; }
		~List() { DeleteList(this); }
		void Include(T value) {
			Node* aux = new Node(value); 
			if (this->head == nullptr)
			{
				this->head = aux;
				current = aux;
				return;
			}
			aux->previous = current; 
			current->next = aux;
			current = aux;
			this->size++;
		}
		void Print() { for (Node* aux = this->head; aux != nullptr; aux = aux->next) { std::cout << aux->GetKey() << ' '; } std::cout << std::endl; }
		void DeleteList(List* a) { for (Node* aux = a->head; aux != nullptr; aux = this->head) { this->head = this->head->next; delete aux; } this->head = nullptr; }
		int GetSize() { return this->size; }
		Node* GetHead() { return this->head; }
		/*List* Merge(List* a, List* b) {
			List* auxA, auxB;
			int size = a->GetSize() > b->GetSize ? a->GetSize() : b->GetSize();
			auxA = a->head;
			auxB = b->head;
			if (auxA == nullptr)
				return b;
			else if (auxB == nullptr)
				return a;
			List* newList = new List();
			while(auxA != nullptr && auxB != nullptr) {
				if (auxA->GetKey() < auxB->GetKey()) {
					newList->Include(auxA->GetKey());
					auxA = auxA->next;
				}
				else {
					newList->Include(auxB->GetKey());
					auxA = auxB->next;
				}
			}
			if (auxA == nullptr)
				auxA = auxB;
			while(auxA != nullptr)
				newList->Include(auxB->GetKey());
			return newList;
		}*/
		void Merge(List* a) {
			Node* auxA = a->head;
			Node* auxB = this->head;
			List* newList = new List();
			while (auxA != nullptr && auxB != nullptr) {
				if (auxA->GetKey() < auxB->GetKey()) {
					newList->Include(auxA->GetKey());
					auxA = auxA->next;
				}
				else {
					newList->Include(auxB->GetKey());
					auxB = auxB->next;
				}
			}
			if (auxA == nullptr)
				auxA = auxB;
			while (auxA != nullptr)
			{
				newList->Include(auxA->GetKey());
				auxA = auxA->next;
			}
			DeleteList(this);
			this->head = newList->GetHead();
		}
	};

}

int main()
{
	std::priority_queue<int> heap;
	std::vector<List::List<int>*> Listas;
	List::List<int> ListaFinal;
	Listas.push_back(new List::List<int>);
	Listas.push_back(new List::List<int>);
	Listas.push_back(new List::List<int>);
	for (int i = 1; i < 90000; i++)
	{
		Listas[0]->Include(i);
		Listas[1]->Include(i);
		Listas[2]->Include(i);
	}
	//Listas[0]->Print();
	//Listas[1]->Print();
	//Listas[2]->Print();
	
	for (int i = 0; i < 3; i++)
	{
		ListaFinal.Merge(Listas[i]);
	}
	ListaFinal.Print();


}