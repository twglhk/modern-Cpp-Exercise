#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
	현대적 C++에서 프로그램의 유연성을 늘려주고 프로그래머의 부담을 줄여주는 것들이다.
	lambda 함수? 익명 함수. 여타 언어에서도 많이 지원한다.
*/

void goodBye(const string& s)
{
	cout << "Good Bye " << s << endl;
}

class Object
{
public:
	void hello(const string & s)
	{
		cout << "Hello " << s << endl;
	}
};


int main()
{
	// 1. lambda 코딩

	// lambda-introducer []
	// lambda-parameter-declaration ()
	// lambda-return-type-clause ->
	// compound-statement { }
	auto func = [](const int& i)->void { cout << "Hellor World" << endl; };
	[](const int& i)->void { cout << "Hellor World" << endl; } (1234);

	{
		string name = "JackJack";
		
		// lambda-introducer는 외부 변수 참조 가능하게 만든다. 
		// reference & copy, scope 내의 변수를 모두 사용 가능하게 해줌.
		[&]() {std::cout << name << endl; } ();
		[&name]() {std::cout << name << endl; } ();
		[=]() {std::cout << name << endl; } ();
		[name]() {std::cout << name << endl; } ();

		// class member 를 쓰고 싶다면 introducer에 this면 ok
		// [this]() {std::cout << name << endl; } ();

	}
	
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	// 이렇게 쓸 수도 있는데 사실 lambda는 이렇게 사용하지 않는다.
	// return type이 void일 경우 생략
	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);

	// 이렇게 바로 param으로 넣는다.
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	// 신세계 코딩
	cout << []() ->int { return 1; }() << endl;



	// 2. std::function 과 std::bind

	// function pointer을 체계화 시킨 것 ==> std::function
	std::function<void(int)> func3 = func2;
	func3(123);
		
	// std::bind?? std::function에서 param type을 입력하고 싶지 않을 때 사용한다.
	// 근데 이걸 잘 쓰고 싶으면 std::placeholders를 알아야 한다.
	std::function<void()> func4 = std::bind(func3, 456);
	func4();

	{
		// 클래스 멤버 함수의 pointer, instance의 pointer, hello 함수의 param의 개수
		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		// 그러면 이렇게 뚝딲
		f(string("World"));
		f("World");


		// 물론 그냥 함수도 bind 가능, 함수의 포인터, 함수 param의 개수
		auto f2 = std::bind(&goodBye, std::placeholders::_1);

		// 마찬가지로 뚝딲
		f2(string("World"));
		f2("World");
	}

	return 0;
}