#include <iostream>

using namespace std;

//class Digit
//{
//private:
//	int m_digit;
//
//public:
//	Digit(int digit = 0): m_digit(digit) {}
//
//	// prefix
//	Digit& operator ++()
//	{
//		++m_digit;
//		return *this;
//	}
//
//	// postfix
//	Digit operator ++ (int)
//	{
//		Digit temp(m_digit); // 현재 값을 저장
//		++(*this);
//		return temp;
//	}
//
//	friend ostream &operator << (ostream& out, const Digit &d)
//	{
//		out << d.m_digit;
//		return out;
//	}
//
//};


// Digit 예제 구현하기
class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) : m_digit(digit) {}

	// prefix, 숫자 9가 1이 증가하면 0으로 바뀜.
	Digit& operator ++()
	{
		if (m_digit == 9)
			m_digit = 0;

		else
			++m_digit;
		
		return *this;
	}

	// postfix
	Digit operator ++ (int)
	{
		Digit temp(m_digit); // 현재 값을 저장
		++(*this);
		return temp;
	}

	friend ostream &operator << (ostream& out, const Digit &d)
	{
		out << d.m_digit;
		return out;
	}

};

int main()
{
	Digit d(5);

	while (true)
	{
		cout << ++d << endl;
	}
	
	cout << d << endl;



	/*cout << d++ << endl;
	cout << d << endl;*/

	return 0;
}