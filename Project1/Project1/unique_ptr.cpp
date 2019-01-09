#include <iostream>
#include <memory> // for unique_ptr
#include "Resource.h"

/*
	pointer가 가리키는 데이터의 소유권이 한 곳에만 속할 경우에 사용하는 smart pointer인 
	unique_ptr이다.
*/

auto doSomething()
{
	// 1번 방법
	auto res1 = std::make_unique<Resource>(5);
	return res1;

	// 2번 방법
	return std::unique_ptr<Resource>(new Resource(5));

	// 3번 방법
	return std::make_unique<Resource>(5);   // 내부적으로 move semantics 구현
											// 소유권이 확실히 넘어간다. 빠르다.
}

void doSomething2(std::unique_ptr<Resource> & res)
{
	res->setAll(100);
	res->print();
}

// 만약에 L-value reference로 받으면 error!!
// unique_ptr은 copy semantics를 허용하지 않는다.
// 이렇게 넣고 싶다면 param을 넣을 떄 std::move(res)를 활용한다.
// move semantics를 활용해 들어왔을 경우 해당 param은 이 함수의 local val로 처리된다.
// 때문에 다시 함수 밖에서 사용할 수 없게 된다.
//void doSomething2(std::unique_ptr<Resource> res)
//{
//	res->setAll(100);
//	res->print();
//
//}

// std::move로 옮겨줬는데 다시 밖에서 사용하고 싶다면 다시 돌려주는 구조로 만든다.
//auto doSomething2(std::unique_ptr<Resource> res)
//{
//	res->setAll(100);
//	res->print();
//  return res;
//}

// unique_ptr이 가리키는 instance의 pointer 값만 넘겨주어서 작업을 하고 싶은 경우이다.
void doSomething2(Resource* res)
{
	res->setAll(100);
	res->print();
}


int main()
{
	{
		//Resource *res = new Resource(1000000);

		std::unique_ptr<Resource> res(new Resource(100000));

		// early return or throw

		// delete res;
		// delete 해주지 않을 시에 소멸자가 호출이 안 되고 운영체제가 메모리 누수를 처리함
		// unique_ptr 사용하면 delete 자동 처리 가능
	}

	{
		std::unique_ptr<int> upi(new int); // 기본 data type에도 사용 가능

		// 1번 방법
		std::unique_ptr<Resource> res1(new Resource(5));

		// 2번 방법
		auto* ptr = new Resource(5);
		std::unique_ptr<Resource> res2(ptr);

		// 3번 방법 (권장)
		auto res3 = std::make_unique<Resource>(5);
		//(==) std::unique_ptr<Resource> res3 = std::make_unique<Resource>(5);

		// 4번 방법 : 함수로 부터 받기
		auto res4 = doSomething();

		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res5; // pointer value

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl; // nullptr가 아니다. 초기화가 되었음
		std::cout << static_cast<bool>(res5) << std::endl; // nullptr

		// res5 = res1;  // unique_ptr는 copy semantics 사용이 불가능하다.
						 // 소유권이 한 곳에만 있어야 하기 때문이다.

		res5 = std::move(res1);

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl; // nullptr가 아니다. 초기화가 되었음
		std::cout << static_cast<bool>(res5) << std::endl; // nullptr
		
		if (res1 != nullptr) res1->print();
		if (res5 != nullptr) res5->print(); //(*res5).print();
	}

	{
		auto res1 = std::make_unique<Resource>(5);
		res1->setAll(1);
		res1->print();

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		doSomething2(res1);
		// res1 = doSomething2(res1); // 소유권을 다시 돌려 받을 수 있다.
		// doSomething2(res1.get());  // unique_ptr의 get()을 이용하면 가리키는 data의 pointer를 얻는다.

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		res1->print();
	}

	{
		Resource *res = new Resource;
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res); // unique_ptr이 2번 참조하면 delete를 2번 하려함.
											 // 절대 이렇게 사용하면 안 된다.

		delete res;							 // 마찬가지로 unique_ptr을 썼으면 delete 하면 안 된다.
	}


	return 0;
}