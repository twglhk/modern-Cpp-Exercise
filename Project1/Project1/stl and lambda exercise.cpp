#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

class Actor
{
public:
	int distance;

	Actor(int num) : distance(num)
	{

	}
};

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);

	vector<Actor*> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(new Actor(dis(gen)));
		cout << i << "  : " << vec[i]->distance << " " << endl;
	}

	/*auto i = std::min_element(vec.begin(), vec.end(), 
		[](Actor* actor, Actor* min) {
		cout << "ACTOR : " << actor->distance << " / " << "Min : " << min->distance << endl;
		return actor->distance < min->distance;
	});

	cout << (*i)->distance << endl;*/

	vector<Actor*> nearVec;
	std::copy_if(vec.begin(), vec.end(),
		std::back_inserter(nearVec),
		[](Actor* actor) { return actor->distance > 50; });

	for (const auto& e : nearVec)
		cout << e->distance << " ";
	cout << endl;
}