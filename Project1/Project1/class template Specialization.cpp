#include <iostream>

using namespace std;

template <typename T>
class A
{
public:
	A(const T& input)
	{
		// constructor
	}

	void doSomething()
	{
		cout << typeid(T).name() << endl; // type의 이름 출력
	}

	void test()
	{}
};

// Class template specialization!!
template<>
class A<char>
{
public:
	A(const char& input)
	{
		// constructor
	}

	void doSomething()
	{
		cout << "Char type Specialization" << endl;
	}
};

template <typename T>
class Storage8
{
private:
	T m_array[8];

public:
	void set(int index, const T& value)
	{
		m_array[index] = value;
	}

	const T& get(int index)
	{
		return m_array[index];
	}
};

template<>
class Storage8<bool>
{
private:
	unsigned char m_data;

public:
	Storage8() : m_data(0)
	{}

	void set(int index, bool value)
	{
		unsigned char mask = 1 << index;

		if (value)
			m_data |= mask;
		else
			m_data &= ~mask;
	}

	bool get(int index)
	{
		unsigned char mask = 1 << index; 
		return (m_data & mask) != 0;
	}
};


int main()
{
	//A a_int(1);
	//A a_double(3.14);
	//A a_char('A');

	//a_int.doSomething();
	//a_double.doSomething();
	//a_char.doSomething();

	// Define a Storage8 for integers
	Storage8<int> intStorage;

	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);

	for (int count = 0; count < 8; ++count)
		cout << intStorage.get(count) << endl;

	cout << "Size of Storage8<int> " << sizeof(Storage8<int>) << endl;

	// Define a Storage8 for bool
	Storage8<bool> boolStorage;
	for (int count = 0; count < 8; ++count)
		boolStorage.set(count, count & 3);

	for (int count = 0; count < 8; ++count)
		cout << (boolStorage.get(count) ? "True" : "False") << endl;

	cout << "Size of Storage8<bool> " << sizeof(Storage8<bool>) << endl;

	return 0;
}