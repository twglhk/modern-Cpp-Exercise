#include <iostream>
#include <string>

using namespace std;

int main()
{
	string my_str("012345678");
	//string my_str("");
	/*
		string은 null char가 없다.
		길이를 직접 가지고 있기 때문이다.
		때문에 길이가 0이면 empty 함수 true 출력
	*/



	/*
		여분을 사용하고 싶다면 ? reserve
	*/

	my_str.reserve(1000); // 최소한의 size 요구 사항


	cout << std::boolalpha;
	cout << my_str.length() << endl;
	cout << my_str.empty() << endl;
	cout << my_str.size() << endl;
	cout << my_str.capacity() << endl; 

	/*
		데이터가 추가될 가능성이 있기 때문에 메모리 relocation을 하지 않으려고 한다.
		즉 new/delete를 안하려고 한다. 그래서 글자가 더해진다면 relocation을 하지 않고 
		빠르게 추가가 된다.
	*/

	cout << my_str.max_size() << endl;


	return 0;
}