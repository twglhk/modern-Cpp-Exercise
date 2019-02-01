#include <iostream>
#include <string>
#include <iomanip> // input/output manipulator

using namespace std;

int main()
{
char buf[5];

//cin >> buf;
cin >> setw(5) >> buf;	// 최대 10글자만 입력 받을 수 있게 해준다.
					    // 런타임 에러를 발생시키지 않고 5개만 출력.
						// input stream buffer에서 정해진 갯수의 char만 가져온다.
cout << buf << endl;

// 가져오지 못한 데이터는 buffer에 남아있다. 
// 추가로 cin을 사용하면 buffer에 남은 데이터를 모두 가져온다.
cin >> setw(5) >> buf;
cout << buf << endl;

cin >> setw(5) >> buf;
cout << buf << endl;


// 공백이 없어짐.
char ch;
while (cin >> ch)
	cout << ch;

// cin.get()을 사용하면 공백도 출력 가능해진다.
char ch;
while (cin.get(ch))
	cout << ch;

// buffer에서 읽어올 데이터의 사이즈를 지정할 수 있다. 공백도 포함
// 물론 buffer에 데이터가 남아있을 수 있다.
char buf[5];
cin.get(buf, 5);
cout << cin.gcount() << " " << buf << endl; // 몇 글자를 읽었는지 count한다.

// line 단위로 읽어온다. line을 전부 읽기 때문에 buffer는 비워진다.
// getline()은 줄바꿈 char 까지 같이 read한다.
char buf[100];
cin.getline(buf, 100);
cout << cin.gcount() << " " << buf << endl;

cin.getline(buf, 100);
cout << cin.gcount() << " " << buf << endl;

// string 단위로 read한다. buf 크기에 제한이 없다.
string buf;
getline(cin, buf);
cout << cin.gcount() << " " << buf << endl; // cin으로 읽은 것은 아니기 때문에 count 는 0

// cin.ignore 는 앞의 글자를 입력한 갯수만큼 무시한다.
char buf[1024];
cin.ignore(2);
cin >> buf;
cout << buf << endl;

// cin.peek()은 입력되는 버퍼의 앞 글자를 읽어오기만 한다.
char buf[1024];
cout << (char)cin.peek() << endl;
cin >> buf;
cout << buf << endl;

// unget()은 마지막에 읽은 글자를 다시 buffer에 넣는다.
char buf[1024];
cin >> buf;
cout << buf << endl;
cin.unget();
cin >> buf;
cout << buf << endl;

// putback()은 buffer에 다시 데이터를 넣는다.
char buf[1024];
cin >> buf;
cout << buf << endl;
cin.putback('A');
cin >> buf;
cout << buf << endl;


// 이렇게 데이터를 구분해서 쓰면 공백으로 따로 입력 가능
int i;
float f;

cin >> i >> f;
cout << i << " " << f << endl;
	
return 0;
}
