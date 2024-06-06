#include <iostream>
#include <ios>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#include <string>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS


int main()
{
	int i = 123;
	bool k = false;
	cout << setw(6) << i << "\n";
	cout << boolalpha << k << "\n";
	cout << put_money(i) << "\n";
	time_t t_t{ time(nullptr) };
	struct tm t;
	localtime_s(&t, &t_t);
	cout << put_time(&t, "%c") << "\n";
	cerr << "error!" << "\n";
	clog << "log!" << "\n";
	cout << 0xa << " " << 012 << " " << 10 << " " << 0b1010 << "\n"; // = 10
	//char buffer[10]{ 0 }; //最后一位时'\0'所以实际上只容纳9个数
	//cin.getline(buffer, 10);
	//cout << buffer;
	int test[2]{ 3,5 };
	auto& [x, y] {test};
	x = 10;
	cout << test[0] << " " << test[1] << "\n";
	std::cout << std::unitbuf;
	std::cout << "Hello, world!"; // 没有刷新缓冲区

	auto str1 = "hello";
	auto str2 = "hi"s;
	decltype(str1) temp1;
	decltype(str2) temp2;
	cout << typeid(str1).name() << "\n" << typeid(str2).name() << "\n";
	cout << typeid(temp1).name() << "\n" << typeid(temp2).name() << "\n";

	int i_1 = 123;
	cout << format("|{:^5}|", i_1) << "\n";

	std::cout << "秒:" << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() << std::endl;
	std::cout << "毫秒:" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << std::endl;
	std::cout << "微秒:" << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << std::endl;
	std::cout << "纳秒:" << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(5)); // 程序暂停5秒钟
}