//Operator overloading - 괄호 연산자와 함수 객체

#include <iostream>

using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

public:
	int operator()(int i) { return (m_counter += i); }
};

int main()
{
	Accumulator acc;
	cout << acc(10) << endl; // 이런 형태로 사용하는 것을 functor라고 한다.
	cout << acc(20) << endl;

	return 0;
}