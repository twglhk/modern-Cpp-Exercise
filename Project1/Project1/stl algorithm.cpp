#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> container;
	list<int> li;

	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	auto iter = min_element(container.begin(), container.end());
	cout << *iter << endl;

	iter = max_element(container.begin(), container.end());
	cout << *iter << endl;

	cout << endl;

	// find를 user defined container에서 사용하고 싶다면 비교 연산자 오버로딩이 필요하다.
	iter = find(container.begin(), container.end(), 3);
	container.insert(iter, 128);
	for (const auto& e : container)
		cout << e << " ";
	cout << endl;


	// list도 vector랑 거의 유사한데 다만 sort와 reverse는 멤버 함수로 구현되어 있다.
	li.sort();
	sort(container.begin(), container.end());
	for (const auto& e : container)
		cout << e << " ";
	cout << endl;

	li.reverse();
	reverse(container.begin(), container.end());
	for (const auto& e : container)
		cout << e << " ";
	cout << endl;



	return 0;
}