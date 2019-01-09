#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception
{
public:
	const char* what() const noexcept override // noexcept : 이 안에서는 예외를 던지지 않는다 (C++ 11)
	{
		return "Custom Exception";
	}
};

int main()
{
	try
	{
		//std::string s;
		//s.resize(-1); // resize 의 크기가 이상할 경우 함수 내부에서 throw를 한다.

		// throw std::runtime_error("Bad thing happend"); // 원한다면 std의 exception을 직접 throw 할 수도 있다.
		throw CustomException();

	}
	//catch (std::length_error & exception) // 명시적으로 exception 처리
	//{
	//	std::cerr << "Length Error!!" << std::endl;	
	//	std::cerr << exception.what() << std::endl;
	//}
	catch (std::exception & exception) // exception은 모든 exception의 부모 클래스
	{
		std::cout << typeid(exception).name() << std::endl; // 어떤 예외인지 알고 싶을 경우 사용.
		std::cerr << exception.what() << std::endl;
	}

	return 0;
}