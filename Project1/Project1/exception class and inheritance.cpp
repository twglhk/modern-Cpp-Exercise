#include <iostream>

using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array Exception" << endl;
	}
};

class MyArray
{
private:
	int m_data[5];

public:
	int & operator [] (const int& index)
	{
		// if (index < 0 || index > 5) throw -1;
		// if (index < 0 || index > 5) throw Exception();
		if (index < 0 || index > 5) throw ArrayException();

		return m_data[index];
	}
};

void dosomething()
{
	MyArray my_array;
	
	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	//catch (ArrayException & e)
	//{
	//	cout << "dosomething()" << endl;
	//	e.report();
	//	throw e; // re-throw
	//}
	catch (Exception & e)
	{
		cout << "dosomething()" << endl;
		e.report();
		throw; // 객체 잘림 방지. 자식 클래스 그대로 던져준다.
	}
}

int main()
{
	try
	{
		dosomething();
	}
	catch (ArrayException & e)
	{
		cout << "main()" << endl;
		e.report();
	}
	catch (Exception & e)
	{
		cout << "main()" << endl;
		e.report();
	}

	return 0;
}