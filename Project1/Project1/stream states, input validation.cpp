#include <iostream>
#include <cctype>
#include <string>
#include <bitset>

using namespace std;

/*
	stream을 이용해서 user로부터 입력을 받아들일 때, file로부터 데이터를 읽어들일 떄
	원하는 데이터인지 확신할 수가 없다. 
	그래서 해당 내용을 검증하는 과정이 필요하다.
*/

void printStates(const std::ios& stream);
void printChracterClassification(const int& i);
bool isAllDigit(const string& str);

int main()
{
	while (true)
	{
		//int i;
		char i;
		cin >> i;

		printStates(cin);

		// 이렇게 쓸 수도 있다는 것만 알자.
		//cout << boolalpha;
		//cout << std::bitset<8>(cin.rdstate()) << endl;
		//cout << std::bitset<8>(std::istream::goodbit) << endl;
		//cout << std::bitset<8>(std::istream::failbit) << endl;
		//cout << !bool((cin.rdstate() & std::istream::failbit) != 0) << endl;

		// 이렇게 테스트도 가능하다.
		//cin.rdstate() == std::istream::goodbit;

		printChracterClassification(i);

		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
	}

	// 입력한 내용이 다 숫자냐 판단
	// 해당 예시는 한 글자씩 비교하는 것이지만 정규 표현식을 쓰면 통째로 비교 가능
	cout << boolalpha;
	cout << isAllDigit("1234") << endl;
	cout << isAllDigit("a1234") << endl;

	return 0;
}

void printStates(const std::ios& stream)
{
	cout << boolalpha;
	cout << "good()=" << stream.good() << endl;
	cout << "eof()=" << stream.eof() << endl;
	cout << "fail()=" << stream.fail() << endl;
	cout << "bad()=" << stream.bad() << endl;
}

void printChracterClassification(const int& i)
{
	cout << boolalpha;
	cout << "isalnum " << bool(std::isalnum(i)) << endl;
	cout << "isblank " << bool(std::isblank(i)) << endl;
	cout << "isdigit " << bool(std::isdigit(i)) << endl;
	cout << "islower " << bool(std::islower(i)) << endl;
	cout << "isupper " << bool(std::isupper(i)) << endl;
}

bool isAllDigit(const string& str)
{
	bool ok_flag = true;

	for (auto e: str)
		if (!std::isdigit(e))
		{
			ok_flag = false;
			break;
		}

	return ok_flag;
}