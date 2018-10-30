#include <iostream>
#include <vector>
#include <string>

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

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm Derived" << endl;
	}

};

class Derived2 : public Base
{
public:
	string m_name = "Dr, two";

	virtual void print() override
	{
		cout << "I'm Derived" << endl;
	}
};


int main()
{
	Derived1 d1;
	d1.m_j = 2048;
	//.... 

	Base *base = &d1; // base로는 d1의 멤버 접근이 불가능

	auto *base_to_d2 = dynamic_cast<Derived2*>(base);
	
	if (base_to_d2 != nullptr)
		cout << base_to_d2->m_name << endl;
	else
		cout << "FAILED" << endl;


	return 0;
}