#include <iostream>
#include <memory>
#include "Resource.h"

/*	
	unique_ptr과 달리 소유권을 여러군데서 공유할 수 있는 스마트 포인터가 
	std::shared_ptr이다.
*/

void doSomething(std::unique_ptr<Resource> res)
{

}

int main()
{
	{

		// 함수의 param으로 넣을 때 이런 식으로 만들면 좋지 않다.
		// doSomething(std::unique_ptr<Resource>(new Resource(1000))); 
		doSomething(std::make_unique<Resource>(1000)); // 이 방식으로 만드는 것이 좋다.

		Resource *res = new Resource(3);
		res->setAll(1);
		std::shared_ptr<Resource> ptr1(res);
		// std::shared_ptr의 특징은 공유를 몇 군데서 하고 있는지 count 한다는 것이다.

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1);
			//std::shared_ptr<Resource> ptr2(res); // 이렇게 res로 직접 만들게 되면 
												 // str1이 share하는 것을 모름. 에러 발생

			// 다른 스마트 포인터를 참조하는 것은 안정적이지 못하다.
			// 때문에 직접적으로 만드는 것이 권장된다.
			auto ptr2 = std::make_shared<Resource>(3);

			// 혹은 다른 스마트 포인터를 share하고 싶다면
			auto ptr3 = ptr1;

			//ptr2->setAll(3);
			//ptr2->print();

			std::cout << "Going out of the block" << std::endl;
			// ptr1이 소유하고 있기 때문에 ptr2가 블럭이 끝나고 사라져도 delete이 되지 않는다.
		}

		ptr1->print();

		std::cout << "Going out of the outer block" << std::endl;

	}// 마지막 shared_ptr이 지워져야지 destructor가 호출 된다.

	// unique_ptr보다 유연한 것이 특징

	return 0;
}