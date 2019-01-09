#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Actor
{
public:
	unsigned long long l;
	//Actor(int x) {}
	virtual void draw() = 0;
};

class NullActor : public Actor
{
public:
	virtual void draw() override {}; // do Nothing
};

class Player : public Actor
{
public:
	int id = 1;

	virtual void draw() override
	{
		cout << "Player Draw!" << endl;
	}
};

int main()
{
	std::vector<Player> actor;

	Player p;
	actor.push_back(p);
	std::for_each(actor.begin(), actor.end(), [](Player player) { player.draw(); });

	auto player = std::find_if(actor.begin(), actor.end(),
		[](Player player) { return player.id == 1; } );

	(*player).draw();

	return 0;
}