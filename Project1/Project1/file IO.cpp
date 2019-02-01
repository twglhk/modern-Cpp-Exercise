#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit()
#include <sstream>

using namespace std;

int main()
{
	// writing
	if (true)
	{
		// ASCII , ios::app, ios::binary ,  파일이 없다면 새로 생성한다.
		//ofstream ofs("my_first_file.dat");
		//ofstream ofs("my_first_file.dat", std::ios::binary);
		ofstream ofs("my_first_file.dat", std::ios::app);

										 
		//ofs.open("my_first_file.dat");   // 생성자로 하거나 open()으로 불러온다.
										   // ASCII type의 text file을 저장한다. == 메모장 오픈 가능
										   // ASCII는 문제가 너무 느림. 그래서 binary 저장이 더 많음
		

		if (!ofs)
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}

		// ASCII writing type
		// stream이기 때문에 기존에 stream 쓰는 방식처럼 사용 가능하다.
		ofs << "Line 1" << endl;
		ofs << "Line 2" << endl;


		// Binary writing type
		//const unsigned num_data = 10;
		//ofs.write((char*)&num_data, sizeof(num_data));

		//for (int i = 0; i < num_data; ++i)
		//	ofs.write((char*)&i, sizeof(i));


		// ofs.close(); // not necessary , 영역이 끝나면 소멸자가 알아서 파일을 닫아준다.
	}
									  
	// reading
	if (true)
	{
		ifstream ifs("my_first_file.dat");
		
		if (!ifs)
		{
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		// ASCII reading type
		while (ifs) // 파일 끝까지 도달하면 false return
		{
			std::string str;
			getline(ifs, str);

			std::cout << str << endl;
		}

		// Binary reading type
		//unsigned num_data = 0;
		//ifs.read((char*)&num_data, sizeof(num_data));

		//for (unsigned i = 0; i < num_data; ++i)
		//{
		//	int num;
		//	ifs.read((char*)&num, sizeof(num));

		//	std::cout << num << endl;
		//}
	}


	return 0;
}