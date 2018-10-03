#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

	/*

	+) copy constructor를 내부에 private 영역에 선언할 경우 외부에서 복사 불가능. 보안성 증가
	
	Fraction(const Fraction& fraction) // copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "called copy constructor" << endl;
	}
	
	*/

public:
	
	// constructor
	Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

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

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}


int main()
{
	Fraction frac(3,5);
	Fraction fr_copy(frac); // call copy constructor
	Fraction fr_init = frac; // copy initialization, call copy constructor
	Fraction fr_skip(Fraction(3, 7)); // 이 경우에는 복사 생성자가 호출 되지 않고 Fraction(3, 7) -> 3,7 로 컴파일러가 변경함.
	
	Fraction fr_func = doSomething();  // call copy constructor, Debug->Release 모드로 변경시 호출 안됌.
	                                   // 함수에서 return 된 값은 함수가 끝나면서 유지될 필요 x
	                                   // 그래서 컴파일라 자체적으로 이 부분에서 변수에 바로 값을 옮겨줌.
	                                   // Return value Optimization

	cout << &fr_func << endl;          // 함수 내부의 return 값 주소와 이 갑스이 주소는 다름.
	                                   // 다르기 때문에 복사 생성자가 호출되는게 맞음.
	                                   // 그런데 Release 모드에서는 생략해줌.

	cout << frac << fr_copy << fr_init <<  endl;


	return 0;
}