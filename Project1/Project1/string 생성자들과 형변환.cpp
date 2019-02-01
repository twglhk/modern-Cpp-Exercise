#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template <typename T>
std::string toString(T x)
{
	std::ostringstream osstream;

	osstream << x;
	return osstream.str();
}

template <typename T>
bool FromString(const std::string& str, T& x)
{
	std::istringstream isstream(str);
	return (isstream >> x) ? true : false;
}

int main()
{
	/* String constructor types */
	{
		using namespace std;

		//std::string my_string;
		std::string my_string("My string");
		//const char* my_string = "my string";
		//std::string my_string(std::to_string(1004));

		//std::string second_string(my_string);
		std::string second_string(my_string, 3);
		//std::string second_string(my_string, 3, 5);
		//std::string second_string(10, 'A');
		cout << second_string << endl;
	}
	
	{
		//std::string my_string(toString(3.141592));
		std::string my_string("HELLO");
		my_string += std::to_string(128);

		// 문자열 int로 변환하기
		//int i = std::stoi(my_string);
		//std::cout << i << std::endl;

		// 문자열 float로 변환하기
		//float f = std::stof(my_string);
		//std::cout << f << std::endl;
		float f;

		// 문자열이 template type이랑 일치하는가 확인하기
		if (FromString(my_string, f))
			std::cout << f << std::endl;
		else
			std::cout << "Cannot convert string to double" << std::endl;


		//string도 iterator와 함께 사용이 가능하다는 점
		std::vector<char> vec;
		for (auto e : "Today is a good day")
			vec.push_back(e);

		//std::string second_string(vec.begin(), vec.end());
		std::string second_string(vec.begin(), std::find(vec.begin(), vec.end(), 'o'));

		// Print
		std::cout << my_string << std::endl;
		std::cout << second_string << std::endl;
	}
	

	return 0;
}