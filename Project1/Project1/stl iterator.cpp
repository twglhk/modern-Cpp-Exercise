#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
	//vector<int> container;
	//list<int> container;
	//set<int> container;
	map<int, char> container;

	// vector, list input
	/*for (int i = 0; i < 10; ++i)
		container.push_back(i);*/

	// set input
	for (int i = 0; i < 10; ++i)
		container.insert(std::pair(i, char(i+65)));

	// const_iterator를 사용할 경우 dereferencing 할 때 const로 받아온다.
	// prevent modification
	// vector<int>::const_iterator itr;
	// list<int>::const_iterator itr;
	// set<int>::const_iterator itr;
	map<int, char>::const_iterator itr;

	itr = container.begin();
	while (itr != container.end())
	{
		cout << itr->first << " " << itr->second;

		++itr;
	}
	cout << endl;

	/*for (auto iter = container.begin(); iter != container.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	for (auto & e : container)
		cout << e << " ";
	cout << endl;*/


	return 0;
}