#include <iostream>
using namespace std;

// error C2061: syntax error: identifier 'B' 
// B가 A의 앞에 선언되어 있을 경우 A는 B를 알 수가 없다. 
// 이 때 전방 선언을 해주면 문제를 해결할 수는 있다.
// 읽기 복잡하긴 하지만 어쩔 수 없이 써야할 떄가 있다. 안 쓰면 복잡해질 수 있기 때문

class A; // Forward Declaration

class B
{
private:
	int m_value = 2;

public:
	//void doSomething(A& a)
	//{
	//	cout << a.m_value << endl; // 이렇게 다른 클래스의 private 변수를 사용하고 싶은 경우? 해당 클래스 내부로 가서 이 클래스를 friend 선언한다.
	//}

	void doSomething_sec(A& a);
};


class A
{
private:
	int m_value = 1;

	//friend void doSomething(A& a, B& b); // 외부 함수에서 private으로 선언된 멤버 변수를 사용하고 싶을 때 friend+함수 prototype
	//friend class B; // 통째로 다른 class를 friend로 선언하면 해당 클래스에서 이 클래스의 private 멤버를 사용할 수 있다.
	friend void B::doSomething_sec(A& a); // 이렇게 다 접근하는거 말고 멤버 함수에 대해서만 접근할 수 있도록 friend 선언도 가능. 
	//그런데 이렇게만 하면 A가 B에 이런 멤버가 있는줄 모름. 따라서 B 클래스 내부에서 선언부와 정의를 분리시켜줘야함
	
};

//class B
//{
//private:
//	int m_value = 2;
//
//
//	friend void doSomething(A& a, B& b); // 외부 함수에서 private으로 선언된 멤버 변수를 사용하고 싶을 때 friend+함수 prototype
//};




// class 내부에서 friend 관계가 된 외부 함수
//void doSomething(A& a, B& b)
//{
//	cout << a.m_value << " " << b.m_value <<  endl;
//}



void B::doSomething_sec(A& a)
{
	cout << a.m_value << endl; 
}


int main()
{
	A a;
	B b;
	//doSomething(a, b);

	b.doSomething_sec(a);

	return 0;
}