// Operator overloading - 첨자 연산자

#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };

public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	// list의 address를 return
	int* getList()
	{
		return m_list;
	}

	// subscript operator overloading
	int &  operator [] (const int index) // param 은 꼭 int type이 아니라 상황에 맞게
	{
		// 런타임 에러를 방지. 예외 처리. if문을 사용할 경우 performance가 낮아지므로 사용하지 않는다.
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];

		// reference로 return 하는 이유는 my_list[3] = 10; 처럼 수정이 가능해야 되기 때문도 있지만
		// return 값이 항상 주소를 담고 있어야 하기 때문이다. 
	}

	const int &  operator [] (const int index) const // overloading to read only.
	{
		// 런타임 에러를 방지. 예외 처리.
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

	
};


int main()
{
	IntList my_list;
	
	// 함수를 이용한 셋팅과 출력
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;
	
	// 첨자를 이용한 셋팅과 출력
	my_list.getList()[3] = 2;
	cout << my_list.getList()[3] << endl; // 이렇게 쓰면 보기 불편하다.

	// 첨자 overloading
	my_list[3] = 10;
	cout << my_list[3] << endl;

	// Const의 경우
	const IntList myConList;
	// myConList[1] = 0; // 불가능. 
	cout << myConList[3] << endl; // 읽기만 가능
	
	// Class를 Pointer로 선언한 경우
	IntList* lpList = new IntList;
	//lpList[3] = 10; // 불가능. 이건 애초에 포인터 변수에 인덱스 접근을 하는 것이기 때문.
	(*lpList)[3] = 10; // dereferencing을 하고 진행해야함.
	lpList[2] = IntList(); // 이게 되는 이유는 lpList가 포인터 변수이기 때문에 array 일 수가 있기 때문.
	                       // 따라서 IntList의 array가 있다면 가능한 설정.

	return 0;
}