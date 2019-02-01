#include <iostream> 
#include <regex>

using namespace std;

/* 
	어떤 문자열이 사용자가 원하는 형식에 맞춰져 있는가 아닌가 판별하는 것은 
	입출력 데이터를 처리할 때 중요한 문제이다.
 	ex) 이메일, 비밀번호 등 최소한의 형식에 맞는가 판별해야함.

	유효성 검사를 일일이 구현하는 것은 버겁다. 정규식을 사용하면 간편하다

	Reference : 
	http://www.cplusplus.com/reference/regex/ECMAScript/
*/

int main()
{
	//regex re("\\d");  // \d는 숫자인가 판별하는 것이다. 
	//regex re("\\d+"); // +를 쓰면 여러개의 숫자 입력도 가능
	//regex re("[ab]");	// a와 b만 됨. 1글자만 가능
	//regex re("[[:digit:]]{3}"); // 바깥 쪽 대괄호 안의 글자는 허용이다. 중괄호는 갯수
	//regex re("[A-Z]+");		  // A-Z 까지 갯수 상관 없이 허용
	//regex re("[A-Z]{1,5}");	  // A-Z 까지 최소 1개, 최대 5개 허용
	regex re("([0-9]{1})([-]?)([0-9]{1,4})"); // ?는 있어도 되고 없어도 된다는 의미

	string str;

	while (true)
	{
		getline(cin, str);

		if (std::regex_match(str, re))
			cout << "Match" << endl;
		else
			cout << "No Match" << endl;

		// print matches
		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();
			for (auto itr = begin; itr != end; ++itr)
			{
				std::smatch match = *itr;
				cout << match.str() << " ";
			}
			cout << endl;
		}

		cout << endl;
	}
}


