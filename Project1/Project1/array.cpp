#include <iostream>
#include <array>

using namespace std;

// Reference pointer, const 사용을 함수 만들 때마다 생각해볼 것.
void printLength(const array<int,5>& my_arr)
{
	cout << my_arr.size() << endl;
}

int main()
{
	int arr[5] = { 1,2,3,4,5 }; // 일반적인 array
	//int arr[] = { 1,2,3,4,5 }; [] index 명시하지 않아도 됐지만 std::array는 불가능
	
	std::array<int, 5> my_arr = { 1,2,3,4,5 }; // std::array, 갯수는 다 써주어야함.
	my_arr = { 0,1,2,3,4 };
	my_arr = { 30,6,7,3 }; // 나머지는 0으로 채워짐

	cout << my_arr[0] << endl;	 // memory access를 함. performance 생각할 때는 at보다는 이거 쓸 것.
	cout << my_arr.at(0) << endl; // 예외처리를 함. 경계 검사

	cout << my_arr.size() << endl; // size return
	printLength(my_arr);

	for (auto &element : my_arr)	// auto 사용 기억하자.
		cout << element << " ";
	cout << endl;

	std::sort(my_arr.begin(), my_arr.end()); // Quick sort 기반 함수

	for (auto &element : my_arr)	
		cout << element << " ";
	cout << endl;

	std::sort(my_arr.rbegin(), my_arr.rend()); // reverse 알아두기
	
	for (auto &element : my_arr)
		cout << element << " ";
	cout << endl;
	
	return 0;
}