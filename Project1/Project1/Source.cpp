#include <iostream>
#include "test.hpp"

using namespace std;

class DerivedEnm : public Enum
{
public:
	enum STATUS
	{
		Z,X,C
	};
};

int main()
{
	DerivedEnm de;
	cout << de.X << endl;

	return 0;
}