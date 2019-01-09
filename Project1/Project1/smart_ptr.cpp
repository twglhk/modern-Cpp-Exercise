#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

/*
new/delete 메모리, 즉 동적 메모리를 직접 관리하는 것이 번거로움.
스마트 포인터를 도입해 이 점을 개선
*/

// RAII : resource acquitition is initialization
// RAII ? 메모리 할당 받은 곳에서 해제해주어야 한다는 원칙

void dosomething()
{
	/*
		할당된 메모리는 모든 case에 대해서 delete를 해주어야 했음
		1. 함수가 끝나기 전
		2. 조기 리턴의 경우
		3. 예외 처리의 경우

		==> 이 번거로움의 해결 => 스마트포인터 등장
	*/


	// Resource* res = new Resource; // dull ptr
	AutoPtr<Resource> res = new Resource;

	try
	{

		if (true) throw - 1;

		// delete res; // not called
	}
	catch (...)
	{
		// CASE 3
		// delete res;
	}

	if (true)
	{
		// CASE 2
		// delete res;
		return;
	}

	// work with res

	// CASE 1
	// delete res;

	return;
}

int main()
{
	// dosomething();

	AutoPtr<Resource> res1(new Resource);
	AutoPtr<Resource> res2;

	cout << std::boolalpha;

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;

	res2 = res1; // 소유권 이전 ==> move semantics

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;

	/*
		value semantics (copy)
		reference semantics (pointer)
		move semantics (move)
	*/

	return 0;
}