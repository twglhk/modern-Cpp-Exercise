#pragma once

#include <iostream>

class Resource
{
//private:
public:
	int *m_data = nullptr;
	unsigned m_length = 0;

public:
	Resource()
	{
		std::cout << "Resource default constructed" << std::endl;
	}

	Resource(unsigned length)
	{
		std::cout << "Resource length constructed" << std::endl;

		this->m_data = new int[length];
		this->m_length = length;
	}

	Resource(const Resource& res)
	{
		std::cout << "Resource copy constructor" << std::endl;

		Resource(res.m_length);

		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];
	}


	~Resource()
	{
		std::cout << "Resource Destroyed" << std::endl;
		if (m_data != nullptr) delete[] m_data;
	}

	Resource& operator = (Resource& res)
	{
		std::cout << "Resource assignment" << std::endl;

		if (&res == this) return *this;
		if (this->m_data != nullptr)delete[] m_data;

		m_length = res.m_length;
		m_data = new int[m_length];

		for (unsigned i = 0; i < m_length; ++i)
			m_data[i] = res.m_data[i];

		return *this;
	}

	void print()
	{
		for (unsigned i = 0; i < m_length; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	void setAll(const int& v)
	{
		for (unsigned i = 0; i < m_length; ++i)
		{
			m_data[i] = v;
		}
	}

};