#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents_ = 0) { m_cents = cents_; } // constructor
	int GetCents() const { return m_cents; }
	int& GetCents() { return m_cents; }

	// - 연산자 overloading
	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	bool operator ! () const
	{
		// 이 부분은 어떤 프로그램이냐에 따라 상황에 맞게 설계
		return (m_cents == 0) ? true : false; 
	}

	// 입출력 overloading
	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out; // 이 return을 하는 이유는 chaining 때문이다. 연달아 다른 값을 출력할 떄 필요하다. 
	}
};

int main()
{
	Cents cents1(3);
	Cents cents2(0);

	// - operator
	cout << cents1 << endl;
	cout << -cents1 << endl;
	cout << -Cents(10) << endl; 

	// ! operator
	cout << !cents1 << endl;
	cout << !cents2 << endl;
	return 0;
}