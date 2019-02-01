#include <iostream>
#include <sstream>
using namespace std;

/* 문자열 흐름의 buffer 역할을 하는 것이 string stream*/

int main()
{
	{ /* str()로 string stream에 string 넣기와 extraction operator 사용해서 추출하기 */
		stringstream os;
		os.str("Hello World!"); // buffer에 있는 내용을 전부 ( )의 내용으로 바꾼다.

		string str;
		os >> str;				// 빈칸이 있으면 잘라서 가져온다.
		cout << str << endl;
	}

	{ /* insertion operator로 string stream에 string 넣기 */
		stringstream os;
		os << "Hello World";	// << insertion operator , >> extraction operator
		os << " Hi!\n" << endl;	// buffer의 string 데이터에 덧붙인다. 단 << 만 사용했을 때이다.
								// 줄바꿈(\n)도 string에 포함 될 수 있다. endl도 마찬가지이다.

		string str = os.str();	// 빈칸을 포함해 전부 가져온다.
		cout << str << endl;
		cout << os.str() << endl; 
	}
	
	{ /* 숫자를 string stream으로 넣기/받기. */
		
		// 문자열로 넣기/받기
		stringstream os;
		os << "12345 67.89";
		string str1, str2;
		os >> str1 >> str2;
		cout << str1 << " | " << str2 << endl;

		// 초기화는 이런 식으로 해야한다.
		os.str("");
		os.clear();
		// == os.str(""); , 단 param이 없을 때는 stream의 내용을 return 해준다.
		// == os.str(string);

		// 숫자로 넣기 / 문자열로 받기
		int i = 12345;
		double d = 67.89;
		os << i << " " << d;
		os >> str1 >> str2;
		cout << str1 << " | " << str2 << endl;

		os.clear();

		// 숫자로 넣기 / 숫자로 받기
		int i2;
		double d2;
		os << i << " " << d;
		os >> i2 >> d2;
		cout << i2 << " | " << d2 << endl;

		os.clear();

		// 문자열로 넣기 / 숫자로 받기
		os << "12345 67.89";
		os >> i2 >> d2;
		cout << i2 << " | " << d2 << endl;
	}


	return 0;
}