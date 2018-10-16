#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived : public Base
{
public:
	int m_j = 0;

	virtual void print() override
	{
		cout << "I'm Derived" << endl;
	}

};


void doSomething(Base b)
{
	b.print();
}

int main()
{
	Base b;
	Derived d;

	std::vector<std::reference_wrapper<Base>> my_vec; // reference_wrapper를 사용
	my_vec.push_back(b);
	my_vec.push_back(d);

	for (auto& element : my_vec)
		element.get().print(); // reference 로부터 인스턴스를 받아와야함.
	                           // get()을 사용해준다.

	return 0;
}