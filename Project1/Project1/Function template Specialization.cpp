#include <iostream>

using namespace std;


template <class T>
class Storage
{
	T m_value;

public:
	Storage(T value) 
	{
		m_value = value;
	}

	~Storage()
	{
	}

	void print()
	{
		cout << m_value << endl;
	}

};

template <> // 마찬가지로 typename || class 명시 x
void Storage<double>::print() // 범위 연산자와 instantiation할 type 명시
{
	std::cout << "Double Type";
	std::cout << std::scientific << m_value << endl;
}

template <typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

// template은 일반화를 시키는 것이지만 이 방법은 반대로 '특수화'를 시킨다.
// 특이 케이스를 다룰 때 사용
template<>  // typename 을 명시하지 않는다!!
char getMax(char x, char y)
{
	cout << "Warning : Comparing Chars" << endl;

	return (x > y) ? x : y;
}

int main()
{
	//cout << getMax(1, 2) << endl;
	// getMax<int>(1,2) 로 auto instantiation 해주고 있다.
	// 물론 getMax<double>(1,2) 로 사용할 경우는 double로 instantiation
	
	//cout << getMax('a', 'b') << endl;

	Storage<int> nValue(5);
	Storage<double> dValue(3.14);

	nValue.print();
	dValue.print();

	return 0;
}