#include <iostream>
using namespace std;

class Cents
{
private:
	int m_nCents;

public:
	Cents(int cents = 0)
	{
		m_nCents = cents;
	}

	operator int()
	{
		cout << "Case here" << endl;
		return m_nCents;
	}

	int getCents() { return m_nCents; }
	void setCents(int cents) { m_nCents = cents; }
};


class Dollar
{
private:
	int m_nDollars = 0;

public:
	Dollar(const int& input) : m_nDollars(input) {};

	operator Cents()
	{
		return Cents(m_nDollars * 100);
	}

};


void PrintInt(const int& value)
{
	cout << value << endl;
}

int main()
{
	Dollar dollar(2);
	Cents cents = dollar;

	// 다 같은 기능의 형변환
	//int value = (int)cents;
	//value = int(cents);
	//value = static_cast<int>(cents); 
	PrintInt(cents); // int 형변환이 없을 시에 불가능. operator int()를 클래스에 넣어주어야 함.



	return 0;
}