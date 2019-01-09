#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	~A()
	{
		throw "error";  // 하면 안 되는 짓. 
					    // 메모리 할당 해제 구간에서 예외를 정상적으로 던질 수 없다고 컴파일러가 해석한다.
						// 실제로도 런타임 에러가 뜬다.
	}
};

int main()
{
	// for문 안에 예외처리는 넣지 않는다. 
	// performance가 아주 나빠진다.
	// 최근엔 zero cost exception이 나오긴 하나 아직까지는 runtime에서 비효율적이라고 한다.

	// 모든 error를 예외처리 하지 말아라.
	// 정상적으로 작동해야하는 코드들은 if로 거른다 (ex. 사용자 입력 등.)
	
	// 네트워크 등에서 분산 처리, 병렬 처리 혹은 하드웨어의 I/O 등에서는 예외처리를 활용한다.
	// 논리적으로 대책을 마련하기 어려운 환경에서 예외처리를 활용한다.

	try
	{
		int *i = new int[1000000];
		unique_ptr<int> up_i(i); // unique_ptr이 있다면 예외처리나 블럭을 벗어났을 때 메모리 할당을 해제해준다!!
								 // Smart pointer!!

		// do something with i
		throw "error";

		//delete[] i; // 실행되지 못함. throw 때문에. 메모리 누수가 발생할 수 있다!!

		//A a;
	}
	catch(...)
	{
		cout << "Catch" << endl;
	}
	
	return 0;
}