#include <assert.h>
#include <iostream>

template <typename T, unsigned int T_SIZE> // T_SIZE는 compile time에 결정
                                           // Compile time에 알려져 있어야함.
class MyArray
{
private:
	//int m_length; // 멤버 변수를 별도로 받는 대신에 T_SIZE로 받는다.
	T* m_data;      // T m_data[T_SIZE] stack에는 큰 size 저장 불가능
	                // 그래서 간단한 경우가 아니면 동적할당이 좋다.

public:
	MyArray() 
	{
		//m_length = 0;
		m_data = new T[T_SIZE];
	}

	~MyArray()
	{
		delete[] m_data;
 	}

	T & operator[] (int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print()
	{
		for (int i = 0; i < T_SIZE; i++)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	// explicit instantiation
	// template class MyArray<char>
	// template class MyArray<double>

	// template void MyArray<char>::print();
	// template void MyArray<double>::print();
	// 이렇게 만들었을 경우에 이 예제에서는 문제가 된다.
	// T_SIZE의 모든 경우에 대응해줄 수가 없기 때문.
	// template class MyArray<char,1~100> 등
	// 따라서 non type param에 대응하는 것은 header에 있어야 한다.
	// Header only Open source lib 등 에는 헤더에 모든 내용이 몰아져 있는 경우도 있다.

};


int main()
{
	// std::vector<double> my_array; my_array.resize(100);
	// MyArray<double> my_array(100);
	// 위와 같이 쓸 경우 100이라는 사이즈가 compile time에 알려져 있지 않아도 가능하다.
	// Runtime에 결정되어도 상관 없다.
	// 물론 double과 같은 자료형은 compile time에 알려져 있어야 한다.

	MyArray<double, 100> my_array; // 100은 compile time에 알려져 있어야함.
	                               // 이 기능은 주로 메모리 개수 결정보다는
	                               // 2차원~3차원의 구별 및 결정에 사용.

	for (int i = 0; i < my_array.getLength(); i++)
		my_array[i] = i + 65;

	my_array.print();

	return 0;
}