#include <iostream>

using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base" << endl;
	}
};

class Derived : public Base
{
private:
	int *m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	virtual ~Derived() override // Base 소멸자가 virtual이 아닐 경우 error
		                        // virtual 을 명시해주는 것이 좋다.
	{
		cout << "~Derived" << endl;
		delete[] m_array;
	}

};

int main()
{
	//Derived derived(5);

	Derived *derived = new Derived(5);
	Base *base = derived;
	delete base; // 다형성의 장점을 생각해서 base로 지우는 경우가 일반적.
	             // 그러나 Base의 소멸자만 호출됨. Derived 객체 소멸자가 호출되지 않음.
	             // 메모리 leak 발생



	return 0;
}