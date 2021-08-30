#include "Principal.h"

int main()
{
	Principal principal;
	principal.menu();
	return 0;
}

/*using namespace std;

class base {
public:
	base()
	{
		cout << "Constructing base \n";
	}
	virtual ~base()
	{
		cout << "Destructing base \n";
	}
};

class derived : public base {
public:
	derived() : base()
	{
		cout << "Constructing derived \n";
	}
	~derived()
	{
		cout << "Destructing derived \n";
	}
};

int main(void)
{
	derived* d = new derived();
	base* b = d;
	delete b;
	getchar();
	return 0;
}
*/
/*
#include "ListaTemplate.h"
#include <iostream>
void lucas()
{
	std::cout << "Lucas" << std::endl;
}

int main()
{
	void (*ptr) () = nullptr;
	List::List<void (*) ()> list;
	List::Iterator<void(*) ()> iterator(&list);
	list.Include(&lucas);
	//iterator = list;
	iterator.SetIteratorHead();
	ptr = iterator.GetValue();
	ptr();
	(*ptr)();
	((void(*)())iterator.GetValue())();
	(iterator.GetValue())();
	
}*/
