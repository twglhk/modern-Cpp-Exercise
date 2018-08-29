#include <iostream>
//#include <cstdint> 
//iostream을 include 해도 쓸 수 있음

int main()
{
	using namespace std;
	std::int16_t i(5);  // 16bit = 2byte 로 바꿔주는 것. short로 정의되어 있음.
	std::int8_t myint = 65; // 1byte 이므로 char임.

	// int형으로 생각할 수 있는데 define이 다르게 되어있음.

	cout << myint << endl;

	std::int_fast8_t fi(5); // 8bit 중에서 가장 빠른 data type.  
	std::int_least64_t fl(5); // 적어도 64bit, 8byte를 갖는 data type

	return 0;
}