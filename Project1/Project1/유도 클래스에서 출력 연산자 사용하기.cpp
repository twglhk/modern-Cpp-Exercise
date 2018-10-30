#include <iostream>
class Base
{
public:
	Base(){}

	// freint func은 member가 아니기 때문에 직접적으로 override 불가능하다.
	friend std::ostream& operator << (std::ostream &out, const Base &b)
	{
		return b.print(out); // 다른 멤버 함수가 출력하게 만든다.
	}

	// 이 출력 대행 함수를 자식 클래스에서 override
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}
	
	// @override 
	// 자식 클래스에서는 operator overloading 가 없어도 됨.
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}

};

int main()
{
	Base b;
	std::cout << b << '\n';
	
	Derived d;
	std::cout << d << '\n'; 

	Base &bref = d;
	std::cout << bref << '\n';

	return 0;
}