#pragma once

#include <iostream>

// std::auto_ptr<int>;  c++ 17에선 안 쓰이게 됨.
// 아래 클래스는 AutoPtr의 기능을 구현한 것
template <class T>
class AutoPtr
{
public:
	T *m_ptr;

public:
	AutoPtr(T *ptr = nullptr)
		: m_ptr(ptr)
	{
		std::cout << "AutoPtr default constructor" << std::endl;
	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor" << std::endl;
		if (m_ptr != nullptr) delete m_ptr;
	}

	AutoPtr(const AutoPtr &a)
	{
		std::cout << "AutoPtr copy constructor" << std::endl;

		// deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr; // Resource 에서 assignment 해줌

		/*m_ptr = a.m_ptr;
		a.m_ptr = nullptr;*/
	}

	AutoPtr& operator = (const AutoPtr &a)
	{
		std::cout << "autoptr copy assignment" << std::endl;

		if (&a == this)			// prevent self assignment
			return *this;

		if (m_ptr != nullptr) delete m_ptr;

		// deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
		return *this;

		/*delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		return *this;*/
	}

	// Copy constructor & Copy assignment 를 강제로 막아버리는 기능
	//AutoPtr(const AutoPtr& a) = delete;
	//AutoPtr& operator= (const AutoPtr& a) = delete;


	AutoPtr(AutoPtr&& a) // R-value reference 
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;  // really necessary? Risk가 있을 가능성이 있기 때문	
							// Destructor 에서도 nullptr가 아니면 delete 호출
		std::cout << "AutoPtr move constructor" << std::endl;
	}

	AutoPtr& operator= (AutoPtr&& a) // R-value reference 
	{
		std::cout << "AutoPtr move assignment" << std::endl;

		if (&a == this)
			return *this;	// prevent self-assignment

		if (!m_ptr) delete m_ptr;

		// shallow copy
		// move semantics
		m_ptr = a.m_ptr;	// Resource의 assignment 호출이 아니라 pointer만 옮겨주는 작업
		a.m_ptr = nullptr;  // really necessary? 소유권의 이전을 표시해준다. 

		return *this;
	}



	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};