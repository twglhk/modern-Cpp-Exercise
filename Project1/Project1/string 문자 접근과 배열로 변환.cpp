#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	/* string 접근 및 수정 */
	string my_string("abcdefg");

	cout << my_string[0] << endl;
	cout << my_string[3] << endl;

	my_string[3] = 'Z';
	cout << my_string << endl;


	/* 참조 exception */
	try
	{
		//my_string[100] = 'X';  // 이 case는 예외처리가 안 된다. 느려질 수 있기 때문.
		my_string.at(100) = 'X'; // invalid string position exception occur
								 // vector도 마찬가지로 이런 식으로 예외 처리 가능.
							     // performance를 생각해서 사용하자.
	}
	catch(std::exception& e)
	{
		cout << e.what() << endl;
	}


	/* string을 const char*로 바꾸기 */
	cout << my_string.c_str() << endl;
	cout << my_string.c_str()[6] << endl;

	const char *arr = my_string.c_str();
	cout << (int)arr[6] << endl;
	cout << (int)arr[7] << endl; // 맨 뒤에 null char를 붙여서 돌려준다.
								 // C style로 사용 가능.


	/* string을 c style Array로 바꾸기 */
	char buf[20];

	my_string.copy(buf, 5, 1); // null char를 넣어주지는 않는다. 
							   // offset 은 시작 위치

	buf[5] = '\0';

	cout << buf << endl;

	return 0;
}