#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
	int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34 };
	
	// change array
	// 1. 함수 param 으로 전달되는 방식이라 값이 변하지 않음.
	for (int number : fibonacci)
		number = 10;

	// 2. Reference 형으로 바꿔주면 값의 변경이 가능해짐.
	for (int& number : fibonacci)
		number *= 10;

	// 3. auto& 를 사용하면 : 뒤의 자료형에 따라서 자동으로 casting 해줌
	for (auto& number : fibonacci)
		number *= 30;

	// output. const auto& 이런 식으로 설정하면 이 반복문에선 number의 변경 x
	for (const auto& number : fibonacci)
		cout << number << " ";
	cout << endl;


	return 0;
}