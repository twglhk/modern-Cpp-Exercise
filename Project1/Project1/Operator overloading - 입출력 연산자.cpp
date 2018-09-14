#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0) 
		: m_x(x), m_y(y), m_z(z)
	{

	}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }


	// 보통 출력을 이렇게 하는데 번거로울 수 있다.
	/*void Print()
	{
		cout << m_x << " " << m_y << " " << m_z;
	}*/


	// 입출력 overloading
	friend std::ostream& operator << (std::ostream& out, const Point& point)
	{
		out << point.m_x << " " << point.m_y << " " << point.m_z;
		return out; // 이 return을 하는 이유는 chaining 때문이다. 연달아 다른 값을 출력할 떄 필요하다. 
	}

	friend std::istream& operator >> (std::istream& in, Point& point)
	{
		in >> point.m_x >> point.m_y >> point.m_z;
		return in; // 이 return을 하는 이유는 chaining 때문이다. 연달아 다른 값을 입력할 때 필요하다. 
	}
};

int main()
{
	//Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);
	Point p1, p2;

	// Output stream의 장점. 파일 출력도 그대로 가능하다.
	ofstream of("text.txt");
	
	// Input file stream
	ifstream ifs("text.txt", std::ifstream::in); // 2번째 param은 mode에 관한 것이다. in을 쓰면 input operation mode


	// 함수 호출로 print 하기
	/*p1.Print(); 
	cout << "// ";
	p2.Print();*/

	// Operator overloading 
	cin >> p1 >> p2;
	cout << p1 << " / " << p2 << endl;

	// File writing
	of << p1 << " " << p2 << endl; // 이런 식으로 파일 출력도 오버로딩으로 간단하게 가능.

    // File Reading
	ifs >> p1 >> p2;
	cout << p1 << " / " << p2;
	
	of.close();
	ifs.close();

	return 0;
}