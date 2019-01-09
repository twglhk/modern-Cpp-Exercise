#include <iostream>

using namespace std;

/*
	move semantics는 항상 사용 안 된다.
	R-value reference는 move semantics를 사용할 지, 사용할 수 있을지, 사용하면 안 되는지
	판별하게 해준다. 
*/

void doSomething(int& lref)
{
	cout << "L-value ref" << endl;
}

void doSomething(int &&ref)
{
	cout << "R-value ref" << endl;
}

int getResult()
{
	return 100 * 100;
}

int main()
{
	int x = 5;
	int y = getResult();
	const int cx = 6;
	const int cy = getResult();

	// L-value reference
	int &lr1 = x;			// Modifiable l-values, old c++의 reference 의미
	// int &lr2 = cx;		// Non modifiable l-values, lr2가 const가 아니기 때문에 불가능
	// int &lr3 = 5;		// R-values, 이 변수가 참조하는 변수가 메모리를 가져야함. 그래서 불가능

	const int &lr4 = x;		// Modifiable l-values
	const int &lr5 = cx;	// Non-modifiable l-values
	const int &lr6 = 5;		// R-values, symbolic const 로 사용한다면 인정


	// R-value reference
	//int &&rr1 = x;			// Modifiable l-values
	//int &&rr2 = cx;			// Non modifiable l-values
	int &&rrr = getResult();
	int &&rr3 = 5;				// R-values, 이 문법의 특징은 R-value만 받을 수 있다. 
								// 5 같은 상수는 이 문장이 끝나면 사라질 운명.
								// R-value reference는 임시로 존재하는 상수를 저장한다.

	cout << rr3 << endl;
	rr3 = 10;
	cout << rr3 << endl;

	// &&의 의미는 5라는 r-value 자체는 나만 사용할 수 있다는 것을 나타낸다.
	// 클래스의 인스턴스라면 rr가 사용하거나 rr만 바꿀 수 있게 하는 것이다.


	//const int &&rr4 = x;		// Modifiable l-values
	//const int &&rr5 = cx;		// Non modifiable l-values
	const int &&rr6 = 5;		// R-values

	// L-R value reference parameters
	doSomething(x);				// L-value
	//doSomething(cx);			// const. const는 const가 아닌 lvalue로 받을 수 없다.
	doSomething(5);				// R-value
	doSomething(getResult());	// R-value

	/*
		결론적으로는 move semantics의 활용이 key point
		L-value로 넘겨줄 경우 move semantics가 발생하면 안 되는 경우가 생긴다.
		예를 들어 x가 함수의 reference param으로 들어갔을 때 x를 다시 함수 밖에서 사용할 일이 있다는 것
		그러면 move semantics를 이용할 때 제한이 걸린다. 충돌이 일어날 수 있다.

		반대로 R-value reference는 어차피 없어질 놈인데 변수처럼 이용이 가능하게 만들어주는 것이다.
		때문에 move semantics를 활용해도 문제가 없다.
	*/
		
	return 0;
}