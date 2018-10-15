#include <iostream>

using namespace std;

class Base
{
protected: 
	int m_i;

public:
	Base(int value)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}
};

class Derived : public Base
{
private:
	double m_d;

	using Base::print; // 마찬가지로 private에 using을 사용해주면 부모에선 public이었지만 
	                   // 여기서는 Private으로 바뀜. 외부 사용 막음.

public:
	Derived(int value)
		: Base(value)
	{}

	using Base::m_i; // proteced로 선언된 변수가 이렇게 사용하면 Derived 안에서 public이 되어버림.
	void print() = delete;
};

int main()
{
	Base b(10);
	Derived d(7);
	

	d.m_i = 1024;  // Derived class에서 상속을 받았으나 protected 영역에 있으므로 사용 불가능. 
				   // using Base::m_i; 사용하면 외부 사용 가능.


	b.print();
	d.print();     // Derived class 의 private 영역에서 using 하면 외부 사용 불가능.
	               // Access specifier를 바꾸는 방법 외에도 멤버에 delete를 적용하면 사용 불가능.

	return 0;
}