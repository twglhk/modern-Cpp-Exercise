#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <ctime>

class Actor
{
private:
	int m_position;

public: 
	Actor()
	{
		std::cout << "Actor counstructor" << std::endl;
	}

	~Actor()
	{
		std::cout << "Destructor" << std::endl;
	}

	int distance(const int& position)
	{
		int result = position - m_position;

		if (result < 0)
			result *= -1;

		return result;
	}

	void setDistance(int d)
	{
		m_position = d;
	}

	int getDistance()
	{
		return m_position;
	}
};

int main()
{
	int position = 0;

	std::vector<Actor*> actors(10);
	for (auto& vec : actors)
	{
		//vec = std::make_unique<Actor>();
		vec = new Actor();

		position = rand() % 10;
		vec->setDistance(position);
		std::cout << vec->getDistance() << std::endl;
		
	}

	int myPosition = 3;
	/*auto i = std::min_element(actors.begin(), actors.end(),
		[&](std::unique_ptr<Actor> actor, std::unique_ptr<Actor> min)
		{
			return actor->distance(position) < min->distance(position);
		});
	*/

	auto i = std::min_element(actors.begin(), actors.end(),
		[&](Actor* actor, Actor* min) 
		{  
		std::cout << "actor pos : " << actor->getDistance() << " " << 
			"min pos : " << actor->getDistance() << std::endl;

			return actor->distance(myPosition) < min->distance(myPosition);
		});


	std::cout << (*i)->getDistance() << std::endl;


	return 0;
}