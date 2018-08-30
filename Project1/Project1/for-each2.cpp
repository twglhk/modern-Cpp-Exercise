#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	//int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34 };
	vector<int> fibonacci = { 0,1,1,2,3,5,8,13,21,34 };

	// numeric_limits 클래스 템플릿인데 산술형의 다양한 속성을 조회할 수 있음.
	// lowest는 주어진 타입(int)의 가장 낮은 숫자를 return 해준다.
	int nMax_number = std::numeric_limits<int>::lowest();

	// 반복하면서 vector 값들 중에 가장 큰 값을 찾음
	for (const auto& number : fibonacci)
		nMax_number = std::max(nMax_number, number);

	cout << nMax_number << endl;

	return 0;
}