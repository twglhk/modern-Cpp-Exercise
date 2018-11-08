#include <iostream>

using namespace std;

template <class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		: m_value(input)
	{}

	void print()
	{
		cout << m_value << endl;
	}
};

template <class T>
class A<T*> // T가 pointer 일 때만 특수화 시키겠다는 의미!!
{
private:
	T* m_value;

public:
	A(T* input)
		: m_value(input)
	{}

	void print()
	{
		cout << *m_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	a_int.print();

	int temp = 456;

	A<int*> a_int_ptr(&temp);
	a_int_ptr.print();

	double temp_d = 3.141592;
	A<double*> a_double_ptr(&temp_d);
	a_double_ptr.print();

	return 0;
}