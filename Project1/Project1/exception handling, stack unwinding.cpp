#include <iostream>

using namespace std;

// void last() throw(int) exception specifier
// void last() throw(...) exception specifier

void first();
void second();
void third();
void last();

void first()
{
	cout << "FIRST" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		// second 에서 날아온 throw를 처리 가능. 정상적으로 함수 진행.
		cerr << "first caught int exception" << endl;
	}

	cout << "END FIRST" << endl;
}

void second()
{
	cout << "SECOND" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		// 마찬가지로 try에서 날아온 throw를 받을 catch 처리가 없으므로 실행되지 않는다. 
		cerr << "second caught double exception" << endl;
	}

	cout << "SECOND END" << endl;
}

void third()
{
	cout << "THIRD" << endl;
	last();

	// last에서 throw 한 값을 catch할 부분이 없기 때문에 진행 불가능
	cout << "END THIRD" << endl;
}

void last() throw(int)
{
	cout << "LAST" << endl;
	cout << "Throws Exception" << endl;

	throw - 1;

	// 예외처리로 실행 불가능
	cout << "END LAST" << endl;
}

int main()
{
	cout << "START" << endl;

	try
	{
		first();
	}

	catch (int)
	{
		// cerr == cout 비슷하다. 
		// std::clog 도 비슷함. 
		// 기능상 큰 차이는 없는데 콘솔에 출력하는 채널이 여러가지가 있다는 의미.
		// cout 같은 경우 바로바로 출력을 안 하고 버퍼에 담아두다가 endl 나왔을 때 flush까지 해줌.
		// cerr 은 에러 메세지이므로 버퍼를 안 거치고 출력 한다.
		cerr << "main caught int exception" << endl;
	}
	// uncaught exception
	catch (...)
	{
		cerr << "main caught ellipses exception" << endl;
	}


	cout << "END MAIN" << endl;


	return 0;
}