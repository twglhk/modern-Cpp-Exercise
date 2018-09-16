#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents_ = 0) { m_cents = cents_; } // constructor
	int GetCents() const { return m_cents; }
	int& GetCents() { return m_cents; }

	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}

	friend bool operator != (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents != c2.m_cents;
	}

	// std::sort를 사용할 떄 왼쪽이 더 크다는 비교 연산자를 만들 경우 => 정렬이 반대로 됨(내림차순).
	/*friend bool operator > (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents > c2.m_cents;
	}*/

	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents < c2.m_cents;
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
	Cents cents1(6);
	Cents cents2(6);

	if (cents1 == cents2)
		cout << "Equal" << endl;

	/////////////////////////////////////////

	std::vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; i++)
		arr[i].GetCents() = i;
	
	// Random generating
	//std::random_shuffle(arr.begin(), arr.end());
	std::random_device rng;
	std::mt19937 urng(rng());
	std::shuffle(arr.begin(), arr.end(), urng); 

	for (const auto& num : arr)
		cout << num << " ";
	cout << endl;

	sort(arr.begin(), arr.end()); // 이걸 하기 위해서는 크기 비교가 가능해야한다.
	                              // int 끼리는 비교가 가능하지만 Cent 클래스 끼리는 비교 불가능
	                              // 따라서 비교 연산자를 오버로딩 해주어야 한다.

	for (const auto& num : arr)
		cout << num << " ";
	cout << endl;

	return 0;
}