#include <iostream>
#include <string>
#include <cstddef>
#include <locale>

int main()
{
	// c-style string example
	{
		char *strHello = new char[7];
		strcpy_s(strHello, sizeof(char) * 7, "hello!");
		std::cout << strHello << std::endl;
	}

	// basic_string<>, string, wstring
	{
		std::string string;
		std::wstring wstring;

		/*
		using string = basic_string<char, char_traits<char>, allocator<char>>;
		using wstring = basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>;
		
		같은 basic_string에서의 다른 instanciation
		*/

		wchar_t wc; // unsigned short
					// 데이터 사이즈를 많이 먹는 char 표현할 때 쓴다.
					// wide-character/unicode
					// 여러 국가 언어에 localization 할 때는 필요하다.
	}


	// wstring example
	{
		const std::wstring texts[] =
		{
			L"안녕하세요?"
			// 기타 다른 언어 등등
		};

		std::locale::global(std::locale(""));
		std::wcout.imbue(std::locale()); // wide cout

		for (size_t i = 0; i < 1; ++i)
			std::wcout << texts[i] << std::endl;
	}


	return 0;
}