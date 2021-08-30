#pragma once

template <class T>
class Vetor {
public:
	template <class T1>
	class Iterator {
	private:
		Iterator<T1>* iterator;
	public:
	};
private :
	T* _vetor;
	int size;
	int _capacity;
	void Realloc(int newSize);
public:
	Vetor() { this->size = 0; Realloc(2); }
	~Vetor() { delete[] _vetor; }
	void push_back(T element) { if (_capacity <= size) Realloc(size + size / 2); _vetor[size] = element; size++; }
	void pop_back() { if (size > 0) size--; _vetor[size].~T(); }
	void Clear() { delete[] _vetor; this->size = 0; this->_capacity = 0; }
	const int GetSize() const { return this->size; }
	const int GetCapacity() const { return (this->_capacity*sizeof(T)); }
	T operator[](int i) { return *(_vetor + i); }
	//T operator++() { _vetor++; }
	void ForEach(void (*ptr)(T)) { for (int i = 0; i < size; i++) ptr(_vetor[i]); }
};

template <class T>
void Vetor<T>::Realloc(int newSize) 
{
	T* aux = new T[newSize];
	if (newSize < size)
		size = newSize;
	for (int i = 0; i < this->size; i++)
		*(aux + i) = *(_vetor + i);
	this->_capacity = newSize;
	delete[] _vetor;
	_vetor = aux;
}

