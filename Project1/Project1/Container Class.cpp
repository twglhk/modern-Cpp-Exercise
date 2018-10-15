#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class IntArray
{
private:
	int m_length = 0;
	int *m_data = nullptr;

public:
	// Constructor
	IntArray(int length)
		: m_length(length)
	{
		m_data = new int[length];
	}

	IntArray(const std::initializer_list<int>& list)
		: IntArray(list.size())
	{
		initialize(list);
	}

	// Destructor
	~IntArray()
	{
		if (m_data != nullptr)
			delete[] m_data;
	}
	
	// initialize
	IntArray& initialize(const std::initializer_list<int>& list)
	{
		setNewArray(m_length);

		int count = 0;
		for (auto& number : list)
		{
			m_data[count] = number;
			count++;
		}

		return *this;
	}


	// reset
	void reset()
	{
		setNewArray(0);
	}


	// resize
	void resize(unsigned size, int num = 0)
	{
		int* temp = new int[size];
		
		if (size > m_length)
		{
			int ix;
			for (ix = 0; ix < m_length; ix++)
				temp[ix] = m_data[ix];

			for (; ix < size; ix++)
				temp[ix] = num;
		}

		else
		{
			int ix;
			for (ix = 0; ix < size; ix++)
				temp[ix] = m_data[ix];
		}

		setNewArray(size);

		for (int ix = 0; ix < m_length; ix++)
			m_data[ix] = temp[ix];
	}


	void insertBefore(const int& value, const int& ix)
	{
		unsigned length = getLength() + 1;
		int* temp = new int[length];
		
		int i;
		for (i = 0; i < ix; i++)
			temp[i] = m_data[i];
		
		temp[i] = value;
		i++;
		
		for (; i < length; i++)
			temp[i] = m_data[i - 1];

		setNewArray(length);
		for (int j = 0; j < m_length; j++)
			m_data[j] = temp[j];
	}
	

	void remove(const int& ix)
	{
		unsigned length = getLength() - 1;
		
		assert(length > 0);
		
		int* temp = new int[length];

		int i;
		for (i = 0; i < ix; i++)
			temp[i] = m_data[i];

		i++; // skip ix

		for (; i < m_length; i++)
			temp[i-1] = m_data[i];

		setNewArray(length);
		for (int j = 0; j < m_length; j++)
			m_data[j] = temp[j];
	}


	void push_back(const int& value)
	{
		unsigned length = getLength() + 1;
		int* temp = new int[length];
		
		for (int ix = 0; ix < m_length; ix++)
			temp[ix] = m_data[ix];

		temp[length-1] = value;

		setNewArray(length);
		for (int j = 0; j < m_length; j++)
			m_data[j] = temp[j];
	}


	// Assignment operator ver
	IntArray& operator = (const std::initializer_list<int>& list)
	{
		m_length = list.size();
		return initialize(list);
	}

	friend ostream& operator << (std::ostream& out, const IntArray& arr)
	{
		for (int ix = 0; ix < arr.m_length; ix++)
			cout << arr.m_data[ix] << " ";
		out << endl;

		return out;
	}

	void setLength(unsigned length) { m_length = length; }
	unsigned getLength() { return m_length; }
	
	void setNewArray(int length)
	{  
		if (m_data != nullptr)
			delete[] m_data;

		setLength(length);
		m_data = new int[m_length];
	}

};


int main()
{
	IntArray my_arr{ 1, 3, 5, 7, 9 };
	cout << my_arr;

	my_arr.reset();
	cout << my_arr;

	my_arr = { 1,2,3,4 };
	cout << my_arr;

	my_arr.resize(10, 2);
	cout << my_arr;

	my_arr.resize(3, 1);
	cout << my_arr;

	my_arr.insertBefore(10, 1);
	cout << my_arr;

	my_arr.remove(1);
	cout << my_arr;

	my_arr.push_back(99);
	cout << my_arr;

	return 0;
}