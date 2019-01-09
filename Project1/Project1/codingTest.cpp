#include <iostream>
#include <cassert>

int main()
{
	int num = 30;
	int num2 = 20;
	static const int table[] = { 10,20,30,40 };
	assert(std::find(&table[0], &table[4], num) != &table[4]);
	std::cout << std::find(&table[0], &table[4], num) << std::endl;
	std::cout << std::find(&table[0], &table[4], num) - &table[0] << std::endl;
	

	int arr[] = { 10,40,30 };
	std::cout << &arr[2] - &arr[1] << std::endl;
	std::cout << sizeof(&arr[1]) << std::endl;
	std::cout << sizeof(arr[1]) << std::endl;
	std::cout << &arr[0] << std::endl;
	std::cout << &arr[1] << std::endl;

	std::cout << &num2 << std::endl;
	std::cout << &num << std::endl;
	std::cout << &num2 - &num << std::endl;
	
	return 0;
}