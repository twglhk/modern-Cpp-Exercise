#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void sequenceContainers()
{
	cout << "Sequence Containers : vector, deque" << endl;

	// vector
	{
		cout << "<Vector>" << endl;
		vector<int> vec;
		for (int i = 0; i < 10; ++i)
			vec.push_back(i);

		for (auto& e : vec)
			cout << e << " ";
		cout << endl << endl;
	}

	// deque
	{
		cout << "<Deque>" << endl;
		deque<int> deq;
		for (int i = 0; i < 10; ++i)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		for (auto & e : deq)
			cout << e << " ";
		cout << endl << endl;
	}

	cout << endl;
}

void associativeContainers()
{
	cout << "Associative Containers : Set, Map" << endl;

	// set
	{
		cout << "<Set>" << endl;
		set<string> str_set;

		// 겹치는 원소 넣지 않는다
		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto & e : str_set)
			cout << e << " ";
		cout << endl << endl;
	}

	// multiset : duplication is allowed
	{
		cout << "<Multi-Set>" << endl;
		multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto & e : str_set)
			cout << e << " ";
		cout << endl << endl;
	}

	// map : key/value
	{
		cout << "<Map>" << endl;
		std::map<char, int> map;

		//map[key] = value;
		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50;

		cout << map['a'] << endl;

		map['a'] = 100;

		cout << map['a'] << endl;

		for (auto & e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl << endl;

		
	}

	// multi-map : key/value (duplicated keys)
	{
		cout << "<Multi-Map>" << endl;

		std::multimap<char, int> map;
		map.insert(std::pair('a', 10));
		map.insert(std::pair('b', 10));
		map.insert(std::pair('c', 10));
		map.insert(std::pair('a', 100));

		cout << map.count('a') << endl;

		for (auto & e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl << endl;
	}
}

void containerAdapters()
{
	cout << "<Container Adapters>" << endl;

	// stack
	{
		cout << "<Stack>" << endl;

		std::stack<int> stack;
		stack.push(1);		// push adds a copy
		stack.emplace(2);	// emplace constructs a new object
		stack.emplace(3);

		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl;
		cout << endl;
	}

	// queue
	{
		cout << "<Queue>" << endl;
		std::queue<int> queue;
		queue.push(1);
		queue.push(2);
		queue.push(3);

		cout << queue.front() << " " << queue.back() << endl;
		queue.pop();
		cout << queue.front() << " " << queue.back() << endl;
		cout << endl;
	}

	// Priority queue
	{
		cout << "<Priority Queue>" << endl;
		std::priority_queue<int> queue;
		// size 비교 연산자가 overloading 되어 있으면 클래스도 가능

		for (const int n : {1, 8, 7, 4, 5, 6, 3, 9})
			queue.push(n);

		for (int i = 0; i < 8; ++i)
		{
			cout << queue.top() << endl;
			queue.pop();
		}
	}
}


int main()
{
	sequenceContainers();
	associativeContainers();
	containerAdapters();

	return 0;
}