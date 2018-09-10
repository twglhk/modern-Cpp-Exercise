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

	// 안에 넣은 버전
	/*friend Cents operator +(const Cents& c1, const Cents& c2)
	{
		return Cents(c1.GetCents() + c2.GetCents());
	}*/

	// 위 버전에서 friend 빼면 syntex error, 이렇게 쓰려면 이항연산에서는 한 요소만 써주면 됨.
	Cents operator +(const Cents& c2)
	{
		return Cents(this->m_cents + c2.m_cents); // 이런 식으로 하나는 this pointer로 넣어줌
	}

	/*

	참고로 
	//, =, [], (), -> 얘네들은 멤버 함수로만 오버로딩이 가능하다. 

	*/
};

// version 1
void add(const Cents& c1, const Cents& c2, Cents& c_out)
{
	c_out.GetCents() = c1.GetCents() + c2.GetCents();
}

// version 2
Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.GetCents() + c2.GetCents());
}

// version 3
//Cents operator +(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.GetCents() + c2.GetCents());
//}

// version 4  (frined 추가한 버전. 바로 private 멤버 접근해서 사용 가능)
//Cents operator +(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.m_cents + c2.m_cents);
//}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	Cents c_sum;
	add(cents1, cents2, c_sum);

	cout << c_sum.GetCents() << endl;	// version 1
	cout << add(cents1, cents2).GetCents() << endl; // version 2
	cout << (cents1 + cents2).GetCents() << endl; // version 3
	cout << (cents1 + cents2 + Cents(6)).GetCents() << endl; // version 3.5, anonymous object 기억하자.
	cout << (cents1 + cents2).GetCents() << endl;

	/*
	오버로딩 안되는 연산자 친구들
	?: 삼항 연산자
	:: 범위 연산자
	sizeof 
	. member selection
	.* member pointer selection

	연산자 우선순위는 변경 불가능
	직관적으로 산술 연산이 당연해 보이는 것들만 연산자 오버로딩 하는 것을 추천. (벡터의 계산, 행렬의 계산 등)
	애매한건 그냥 함수 쓰는게 좋다.
	
	^ 얘는 연산자 우선 순위가 낮아서 괄호 쳐줘야 해서 잘 안하는게 좋음

	*/

	return 0;
}