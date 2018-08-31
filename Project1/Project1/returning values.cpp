#include <iostream>
#include <array>

using namespace std;

// 변수들이 복사 되는 상황이 많음. performance 측면에서는 좋지 않음.
int getValue(int x)
{
	int value = x * 2;
	return value;
}

int& getValue_reference(int x)
{
	int value = x * 2;
	return value; // 해당 scope 내에서 사라지는 지역 변수는 & return 형식에서 return 하면 안 됨.
}

int* getValue_pointer(int x)
{
	int value = x * 2;
	return &value;
}

int* allocateMemory(int size)
{
	return new int[size];
}

int& get(std::array<int, 100>& my_array, int ix)
{
	return my_array[ix];
}

struct  S
{
	int a, b, c, d;
};

S getStruct()
{
	S my_s{ 1,2,3,4 }; // 이 방식의 단점은 함수 하나를 만들 때마다 구조체를 새로 만들어야함. 
					   // tuple을 만들어서 해결 가능

	return my_s;
}

std::tuple<int, double> getTuple()
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}


int main()
{
	int value1 = getValue(3);

	int pValue1 = *getValue_pointer(3); // 사라질 변수를 dereferencing 하는 경우인데 안전하지 않음.
									   // warning C4172: returning address of local variable or temporary: value
	
	int *pValue2 = getValue_pointer(3); // 이거도 마찬가지로 함수 내부에서 사라지는 local 변수의 메모리 주소를 가져오기 때문에 좋지 않음.
	cout << pValue1 << endl;
	
	//------------------------------------------------------------------------------------------------------------

	int *array1 = new int[10]; // 메모리를 생성하고 그 생성된 메모리의 pointer 값을 return 하는 기능을 함수로 별도 구현해서 사용함. => Factory pattern의 경우.
	int *array2 = allocateMemory(10); // 이런 식으로.
	
	delete[] array1; // 이렇게 new와 delete가 따로 있을 경우는 코딩할 때 난항을 겪을 수 있음. 이렇게 잘 안함.
	
	//------------------------------------------------------------------------------------------------------------

	int value2 = getValue_reference(4); // reference가 잠깐 남아있는 상황에서 함수의 local 변수 안에 있는 data가 복사되서 value2로 들어감.
	int &value3 = getValue_reference(5); // 이런식으로 받아버리면 함수의 소멸되는 local value의 reference를 그대로 받아오게 됨.
									     // pointer와 동일한 문제가 발생함.

	cout << value3 << endl;
	cout << value3 << endl; // 이렇게 2번 출력해보면 쓰레기 값이 나와서 원하는 값을 받아올 수가 없음. OS에 memory 할당되었던거 돌려준 상태가 되었음.
	                       
	//------------------------------------------------------------------------------------------------------------

	std::array<int, 100> my_array;
	my_array[30] = 10;
	get(my_array, 30) = 1024; // 윗줄의 코드와 동일한 기능을 한다. 많이 사용한다. 함수의 실행 전후의 메모리 영역이 크게 달라지지 않기 때문에 안정적.
	get(my_array, 30) *= 10;

	cout << my_array[30] << endl;

	//------------------------------------------------------------------------------------------------------------

	S my_s = getStruct();
	my_s.b;

	//------------------------------------------------------------------------------------------------------------

	std::tuple<int, double> my_tp = getTuple();
	cout << std::get<0>(my_tp) << endl; // a
	cout << std::get<1>(my_tp) << endl; // b
	// 구조체 받는 방식보다는 좋은거 같은데 불편함

	//------------------------------------------------------------------------------------------------------------

	auto[a, d] = getTuple();
	cout << a << endl;
	cout << d << endl;
	// 와 뭐 이런게 있네

	return 0;
}