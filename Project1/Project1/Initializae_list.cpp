#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length) 
		: m_length (length)
	{	
		m_data = new int[length];
	}

	~IntArray()
	{
		delete[] this->m_data;
	}


	// initialize_list를 class의 constructor에서 사용하기.
	IntArray(const std::initializer_list<int>& list)
		: IntArray(list.size()) // 이렇게 하면 위에서 정의한 생성자가 호출되어 메모리를 할당받아옴.
	{
		int count = 0;
		for (auto & element : list) // for-each는 Initializer_list 내부의 iterator를 이용함. 
		{
			m_data[count] = element;
			++count;
		}

		//for (unsigned count = 0; count < list.size(); count++)
		//	m_data[count] = list[count]; // error , initializer_list는 [] 를 지원하지 않음. 
	}


	// Assignment operator ver
	IntArray& operator = (const std::initializer_list<int>& list) 
	{
		if (this->m_data != nullptr)
			delete[] m_data;
			
		m_length = list.size();
		m_data = new int[m_length];
	
		int count = 0;
		for (auto & element : list)
		{
			m_data[count] = element;
			++count;
		}
		
		return *this;
	}

	friend ostream& operator << (std::ostream& out, const IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; i++)
			out << arr.m_data[i] << " ";
		out << endl;
		return out;
	}

};


int main()
{
	int my_arr1[5] = { 1,2,3,4,5 };
	int *my_arr2 = new int[5]{ 1,2,3,4,5 };

	auto i1 = { 10,20,30 };
	/*
	class std::initializer_list<int>
	이니셜라이즈 리스트를 사용하면 편하게 리스트 작성이 가능하다. 
	*/


	IntArray int_array{ 1,2,3,4,5 };
	cout << int_array << endl;

	IntArray ass_array = { 1,2,3,4,5 };
	cout << ass_array;
	
	ass_array = i1;
	cout << ass_array;

	return 0;
}