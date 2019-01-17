#include <iostream>
#include <memory>
#include <string>

/*
	shared_ptr를 사용할 때 발생하는 순한 의존성 문제를 weak_ptr로 해결할 수 있다.

*/

class Person
{
private:
	std::string m_name;
	//std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner; 

public:
	Person(const std::string &name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is partnered with " << p2->m_name << "\n";

		return true;
	}

	const std::shared_ptr<Person> getPartner() const
	{
		return m_partner.lock();
	}

	const std::string & getName() const
	{
		return m_name;
	}
};

int main()
{
	auto lucy = std::make_shared<Person>("lucy");
	auto ricky = std::make_shared<Person>("ricky");

	partnerUp(lucy, ricky);

	// object가 소멸자를 호출할 때 이미 다른 shared_ptr이 존재하기 때문에
	// 멤버의 shared_ptr을 지울 수가 없게 된다. ==> 순환 의존성 문제!!
	// weak_ptr을 사용한다면 이 문제 해결이 가능하다.
	// 단 weak_ptr은 직접적으로 사용이 불가능하다. 
	// lock()이라는 함수를 통해 shared_ptr로 바꿔서 사용해 주어야 한다.

	std::cout << lucy->getPartner()->getName() << std::endl;

	return 0;
}