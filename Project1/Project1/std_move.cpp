#include "Resource.h"
#include "AutoPtr.h"
#include <vector>
#include <string>

using namespace std;

/*
	주기적으로 move semantics를 사용하다 보면 프로그래머가 사용할 때를 정하고 싶을 때가 있다.
	std::move 는 이런 상황에 사용할 수 있다.
*/

template<typename T>
void MySwap(T &a, T &b)
{
	// Call copy constructor
	/*T tmp = a;
	a = b;
	b = tmp;*/

	// Call move constructor
	// 단 이 동작도 클래스에서 move semantics를 꼭 구현해 놓아야 한다.
	T tmp { std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	//AutoPtr<Resource> res1(new Resource(1000000));
	//cout << res1.m_ptr << endl;

	////AutoPtr<Resource> res2 = res1;
	//AutoPtr<Resource> res2 = std::move(res1);
	//// std::move의 역할은 param이 && (R-value reference)로 인식될 수 있도록 바꿔준다.
	//// 그냥 대입 식에서는 copy semantics가 실행이 되지만
	//// std::move가 있으면 move semantic이 실행된다. 
	//// 단 주의할 것은 res1에서 res2로 move를 한다는 의미는 앞으로 res1으로 동일한 작업을 하지
	//// 않겠다는 것을 프로그래머가 명시해준 것이다. R-value 로 만든다는 의미 자체가
	//// 해당 코드 이후에는 사용하지 않겠다는 의미이기 때문이다. 
	//// 때문에 일반적인 경우, 즉 res1을 다시 사용한다는 상황에는 move가 위험할 수 있다.

	//cout << res1.m_ptr << endl;
	//cout << res2.m_ptr << endl;


	/*{
		AutoPtr<Resource> res1(new Resource(3));
		res1->setAll(3);

		AutoPtr<Resource> res2(new Resource(5));
		res2->setAll(5);

		MySwap(res1, res2);

		res1->print();
		res2->print();
	}*/

	{
		vector<string> v;
		string str = "Hello";

		v.push_back(str); // copy semantics를 사용하겠다는 의미이다

		cout << str << endl;
		cout << v[0] << endl;

		v.push_back(std::move(str)); // move semantics를 사용하겠다는 의미이다.
									 // &&를 param으로 받는다. 내부적으로 vector에 move가 구현되어 있다.
		cout << str << endl;		 // move가 되었기 때문에 더 이상 str에서는 사용할 수 없다.
		cout << v[0] << " " << v[1] << endl;

		str = "BACK";
		cout << str << endl;

	}

	{
		std::string x{ "abc" };
		std::string y{ "de" };

		std::cout << "x : " << x << std::endl;
		std::cout << "y : " << y << std::endl;

		MySwap(x, y);

		std::cout << "x : " << x << std::endl;
		std::cout << "y : " << y << std::endl;
	}

	return 0;
}