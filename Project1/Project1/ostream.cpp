#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	/* flag를 가지고 출력 옵션 조절하기 */

	{ /* +기호 함께 출력하기 */
		cout.setf(std::ios::showpos);   // + 기호가 출력된다.
		cout << 108 << endl;

		cout.unsetf(std::ios::showpos); // + 기호 출력 제거
		cout << 200 << endl;
	}

	cout << endl;

	{ /* 진수 mode 바꾸기 */
		cout.unsetf(std::ios::dec); // hex를 출력하기 위해선 10진수 모드 off
		cout.setf(std::ios::hex);   // 16진수 모드 on
		cout << 108 << endl;

		cout.unsetf(std::ios::hex); // hex 해제
		cout << 108 << endl;

		cout.setf(std::ios::hex, std::ios::basefield); // basefield를 hex로 바꿔준다.
		cout << 108 << endl;

		cout.unsetf(std::ios::hex);	// hex 해제


		// 더 간편하게 mode 변환하기
		cout << std::hex;
		cout << 108 << endl;
		cout << 109 << endl;

		cout << std::dec;
		cout << 108 << endl;
	}

	cout << endl;

	{/* 대문자 출력하기 */
		cout << std::hex << std::uppercase; // #include <iomanip>
		cout << 108 << endl;

		cout << std::dec;
	}

	cout << endl;

	{/* boolalpha 사용하기 */
		cout << std::boolalpha;
		cout << true << " " << false << endl;
	}
	
	cout << endl;

	{/* 소수점 정밀도 조절하기 */
		cout << std::defaultfloat;	// 기본 type. 있는 그대로 출력
		cout << 123.456 << endl;

		cout << std::showpoint;						// 소수점 출력 (아래 자리가 없어도)
		cout << setprecision(3) << 123.456 << endl;	// 왼쪽부터 최대 3자리 숫자까지 표시 (123)
		cout << setprecision(4) << 123.456 << endl; // 4자리까지 표시. 즉 123.5 (반올림)
		cout << setprecision(5) << 123.456 << endl;
		cout << setprecision(6) << 123.456 << endl;
		cout << setprecision(7) << 123.456 << endl;
		cout << setprecision(8) << 123.456 << endl;

		cout << std::fixed;			// 소수점 자리만 고정
		cout << setprecision(3) << 123.456 << endl;
		cout << setprecision(4) << 123.456 << endl;
		cout << setprecision(5) << 123.456 << endl;

		// 맨 앞자리 다음 부터 숫자들을 갯수 만큼 소수로 보정.
		cout << std::scientific << std::uppercase;    
		cout << setprecision(3) << 123.456 << endl;
		cout << setprecision(4) << 123.456 << endl;
		cout << setprecision(5) << 123.456 << endl;
	}

	cout << endl;

	{ /* setw()와 빈칸 만들기 */
		cout << -12345 << endl;
		cout.fill('*');	// 생기는 빈칸을 별로 채워준다.
		cout << std::setw(10) << -12345 << endl;
		cout << std::setw(10) << std::left << -12345 <<  endl;
		cout << std::setw(10) << std::right << -12345 << endl;
		cout << std::setw(10) << std::internal << -12345 << endl;	// 부호와 숫자 사이에 빈칸
	}

	return 0;
}