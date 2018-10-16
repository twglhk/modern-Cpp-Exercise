#include <iostream>
#include <cassert>

using namespace std;

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 add / 1 sub / 2 mul" << endl;
	cin >> op;
	assert(op >= 0 && op < 3 && "Not valid range");

	// static binding (early binding)
	// ==> 모든 변수명이나 함수명이 build time에 정의가 되어 있는 것
	/*int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = sub(x, y); break;
	case 2: result = mul(x, y); break;
	}

	cout << result << endl;*/


	// Dynamic binding (late binding)
	// Compile time에 func_ptr에 어떤 데이터가 들어있을 지 알 수 없음.
	// Runtime에 결정.
	// Static에 비해서 느리지만 프로그램이 유연해질 수 있다.
	// 반복문 같은 곳에서 남발하지 않으면 됨.
	int(*func_ptr)(int, int) = nullptr;
	switch (op)
	{
	case 0: func_ptr = add; break;
	case 1: func_ptr = sub; break;
	case 2: func_ptr = mul; break;
	}

	cout << func_ptr(x,y) << endl;


	return 0;
}