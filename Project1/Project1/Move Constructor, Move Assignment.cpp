#include "Resource.h"
#include "AutoPtr.h"
#include "Timer.h"

AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(1000000));
	return res;
}

int main()
{
	using namespace std;
	streambuf* orig_buf = cout.rdbuf();
	//cout.rdbuf(NULL);

	{
		AutoPtr<Resource> main_res;
		main_res = generateResource();  // 함수로 생성된 AutoPtr이 다시 쓰일 일이 없음.
										// 때문에 deep copy를 하기 보다 R-value reference로 받음
										// swallow copy
	}

	cout.rdbuf(orig_buf);

	return 0;
}