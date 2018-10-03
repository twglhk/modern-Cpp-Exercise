#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/*
동적 할당된 메모리에 대한 포인터 변수를 멤버로써 가지고 있는 클래스의 경우 copy나 assignment 할 때
깊은 복사나 얕은 복사냐에 따라서 assignment operator overloading, copy constructor 구현이 까다로워진다.
최근에는 std::vector나 std::string을 사용하기 때문에 사용자가 이 문제를 직접적으로 고민하는 경우가 별로 없을 것이다.
깊은 이해를 위해서 공부하면 좋다.
*/

class Mystring
{

//private: 주소를 찍어보기 위해 예제에서는 임시로 public으로 만들었다.
public:
	char *m_data = nullptr;
	int m_length = 0;

	/*
	Default copy constructor가 변수 값들을 그대로 복사하는 것.
	포인터 변수면 주소도 그대로 복사해주는 것
	이 것을 얕은 복사 (Shallow copy) 라고 한다.
	*/

	// 이 복사 문제를 간단히 해결하려면 string을 사용하면 됨.
	// 혹은 std::string 클래스 상속하면 됨.
	std::string str; 


public:
	Mystring(const char * source = "")
	{
		assert(source);

		m_length = std::strlen(source)+1;
		m_data = new char[m_length];

		for (int i = 0; i < m_length; i++)
		{
			m_data[i] = source[i];
		}

		m_data[m_length - 1] = '\0';
	}

	Mystring(const Mystring &source)
	{
		cout << "Copy constructor" << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr) // source가 가진 데이터가 있으면
		{
			m_data = new char[m_length]; // 이 객체에도 메모리 생성 후

			for (int i = 0; i < m_length; i++) // source의 데이터 복사
				m_data[i] = source.m_data[i];

			/*
			<실행화면 2>

			이런 식으로 새로 메모리를 할당 받아서
			복사하는 방법을 깊은 복사 (Deep copy)라고 한다.
			*/
		}

		else
			m_data = nullptr; // 그냥 0을 넣을 수도 있는데 포인터 구분을 위해 nullptr 사용
	}

	Mystring& operator = (const Mystring & source)
	{
		// Shallow copy
		/*this->m_data = source.m_data;
		this->m_length = source.m_length;*/

		cout << "Assignment operator" << endl;

		// assignment operator의 경우 자기 자신을 대입할 수도 있는데 프로그램상 문제가 생길 수 있기 때문에 막음.
		if (this == &source) // prevent self-assignment
			return *this;

		delete[] m_data; // assignment operator의 경우 새로 만드는 것이 아닐 수 있기 때문에 기존 메모리 삭제해야함.


		// 이 복사 부분은 copy constructor랑 2번 나오기 때문에 함수화 시키는게 좋음.
		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; i++)
				m_data[i] = source.m_data[i];
		}

		else
			m_data = nullptr;

		

		return *this;
	}


	// Mystring(const Mystring& source) = delete; // 차선책임. 얕은 복사를 아예 막겠다는 의미.

	~Mystring()
	{
		delete[] m_data;
	}

	char* getString() { return m_data; }
	int getLength() { return m_length; }

};

int main()
{
	Mystring hello("Hello");
	
	/*
	<실행화면 3> , str1은 객체가 만들어지고 있으므로 = 가 쓰였지만 copy constructor 호출.
	str2는 assignment operator가 호출된다.
	*/

	//Mystring str1 = hello;
	Mystring str1(hello); // copy constructor가 호출되기 때문에 이렇게 명시적으로 쓰면 좋다.
	Mystring str2;
	str2 = hello;
	

	cout << (int*)hello.m_data << endl;
	cout << hello.getString() << endl;

	{
		Mystring copy = hello; // 생성되는 곳에 copy가 발생할 경우 copy constructor call
							   // default copy constructor가 호출된다.

		// copy = hello; // 이런 식으로 될 때는 대입 연산자가 호출
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;

		/*
		+) 실행화면 1의 상황, Custom copy constructor를 사용하지 않는 경우

		default copy constructor는 변수를 그대로 복사해준다. 그러면 어떤 문제가 생기는가?
		heap 메모리에는 m_data가 하나만 존재한다. 즉 copy와 hello 두 객체가 한 데이터를 참조하는 상황.
		그런데 이 scope가 끝나면서 destructor가 호출됨. heap의 데이터를 삭제.
        그래서 hello 객체에서는 사라진 m_data를 알 수가 없게되버림.
		*/

	}

	cout << hello.getString() << endl;

	return 0;
}