#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:

	// constructor
	explicit Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	// Delete, char로 들어오는 생성자를 막아버리는 기능.
	Fraction(char) = delete;


	Fraction(const Fraction& fraction) // copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "called copy constructor" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

void doSomething(Fraction frac)
{
	cout << frac << endl;
}


int main()
{
	Fraction frac(3, 5);
	//Fraction f('c');  // 생성자에 delete를 사용하면 이게 불가능해진다.
	
	// doSomething(7); // 이렇게 해도 자동으로 생성이 되는데 이 것을 'Converting constructor'라고 한다.
	                // 함수 입장에서 Fraction밖에 받아들일 변수가 없다면 자동 생성.

	doSomething(Fraction(7)); // 만약 생성자에 Explicit가 걸려있다면 위처럼 사용 불가능. 이렇게 쓰거나
	doSomething(frac);        // 이렇게 써야함. 다만 이렇게 사용할 경우 이 예제에서는 explicit가 걸린 constructor가 아닌
	                          // copy constructor가 호출된다는 점 유의할 것.
	return 0;
}