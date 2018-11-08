#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// try, catch, throw
	
	try
	{
		// somthing happend
		throw - 1.0;
	}
	catch (int x)
	{
		cout << "Catch Integer " << x << endl;
	}
	catch (double x)
	{
		cout << "Catch double " << x << endl;
	}

	catch (std::string error_message)
	{
		// do something respond
		cout << error_message << endl;
	}
	
	return 0;
}