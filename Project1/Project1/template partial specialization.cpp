#include <iostream>
using namespace std;

template <class T, int size>
class StaticArrayBase
{
private:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[] (int index)
	{
		return m_array[index];
	}

	void print()
	{
		for (int count = 0; count < size; ++count)
			cout << (*this)[count] << ' ';
		cout << endl;
	}
};


template <class T, int size>
class StaticArray : public StaticArrayBase<T,size>
{
};

template <int size>
class StaticArray<char,size> : public StaticArrayBase<char, size>
{
public:
	void print()
	{
		for (int count = 0; count < size; ++count)
			cout << (*this)[count];
		cout << endl;
	}
};

//template <int size>
//void print(StaticArray<char, size> &array)
//{
//	for (int count = 0; count < size; ++count)
//		cout << array[count];
//	cout << endl;
//}

int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	int4.print();


	StaticArray<char, 14> char14;
	char14[0] = 'H';
	char14[1] = 'e';
	//..

	strcpy_s(char14.getArray(), 14, "Hello World");
	// strcpy_s((char*)&char14[0], 14 * sizeof(char), "HelloWorld");

	char14.print();

	return 0;
}