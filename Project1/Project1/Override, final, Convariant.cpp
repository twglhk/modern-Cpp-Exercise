#include <iostream>

using namespace std;

class A
{
public:
	virtual void printOverride(int x) { cout << "A" << endl; }
	void printCovariant() { cout << "A" << endl; }
	virtual A* getThis() 
	{ 
		cout << "A::getThis()" << endl;
		return this; 
	}
};

class B : public A
{
public:
	long x;

	//void printOverride(short x) { cout << "B" << endl; } 
	// 함수 param이 다르면 overriding 불가
	// Overloading으로 인식한다. 상위 클래스 함수 호출

	
	void printOverride(int x) override { cout << "B" << endl; }
	// 함수 뒤에 'override'를 명시해주면 컴파일러가 override가 아닐 경우 미리 에러를 발견해줌.
	// 혹은 함수의 이름을 틀릴 경우도 찾아준다. ex) printOverride2 (int x)
	// prototype 이 다를 경우도 발견해줌.      ex) printOverride (int x) const override
	// 실수를 방지하는 기능.


	virtual void printFinal(int x) final { cout << "B final" << endl; }
	// Final 선언시 하위 클래스에서 Override 사용 불가능

	void printCovariant() { cout << "B" << endl; }
	virtual B* getThis() 
	{ 
		cout << "B::getThis()" << endl;
		return this; 
	} // 보통 return type이 다르면 overriding이 안 되는데 부모 자식 관계이기 때문에 됨.
	


	// void print1() { cout << "B" << endl; }
	

};

class C : public B
{
public:
	// virtual void printFinal(int x) { cout << "C" << endl; } // Final이라 사용 불가
};

int main()
{
	A a;
	B b;
	//C c;

	A& ref = b;
	ref.printOverride(1);
	
	b.getThis()->printCovariant();
	ref.getThis()->printCovariant();

	
	/*
	Convariant Return type : 첫번째 변수의 크기가 두번째 변수의 크기에 따라 변함
	간단하게 이야기해서 상위 클래스에서 virtual로 선언된 멤버 함수는 자식 클래스의 것을 호출.
	virtual로 선언되지 않은 것은 부모 클래스의 것을 호출한다.
	A& ref = b; 에서 ref는 어쨌든 본질은 A이다. 그런데 여기에 자식 클래스를 대입함으로써
	virtual로 override한 함수는 자식 클래스에서 정의한 것을 사용하겠다는 의미이다.
	*/

	cout << sizeof(ref) << endl;
	cout << sizeof(b) << endl;
	
	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;

	return 0;
}