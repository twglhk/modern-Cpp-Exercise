#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

/*
	이미 존재하는 파일의 중간 부분 수정
	필요한 일부만 읽고 싶기도 함.
	이런 파일의 임의의 위치 접근 하는 방법이다.
*/

int main()
{
	const string filename = "my_file.txt";

	// make a file
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}

	// read the file
	{
		ifstream ifs(filename);

		// file 처음 부터 5 byte를 이동해서 read
		ifs.seekg(5); // ifs.seekg(5, ios::beg); // 시작 위치로 부터 5 byte
		cout << (char)ifs.get() << endl;

		// 현재 cursor 위치에서 5 byte 이동해서 read
		ifs.seekg(5, ios::cur);
		cout << (char)ifs.get() << endl;

		// 끝으로 부터 x byte
		ifs.seekg(0, ios::end);
		cout << ifs.tellg() << endl; // 위치를 숫자로 return

		// cursor 부터 line read
		string str;
		getline(ifs, str); 

		cout << str << endl;
	}

	{ /* file을 한 번 열어서 read/write 다 하기 */
		//fstream iofs(filename, ios::in | ios::out); // flag 설정도 가능하지만 보통 in/out 둘다 지원
		fstream iofs(filename);

		iofs.seekg(5);
		cout << (char)iofs.get() << endl; // read

		iofs.seekg(5);
		iofs.put('A'); // write
	}

	return 0;
}