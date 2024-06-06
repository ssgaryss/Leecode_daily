#include <iostream>
#include <limits>
#include <cmath>
#include <format>
#include <vector>
#include <array>


using namespace std;

int addNumber(int a, int b);

int main(int argc, char* argv[]) {
	////{}:初始化器
	//int i{};
	//float j{};
	//char k{};
	//cout << "i = " << i << "\n";
	//cout << "j = " << i << "\n";
	//cout << "k = " << i << "\n";

	//cout << numeric_limits<double>::max() << "\n";
	//cout << numeric_limits<double>::infinity << "\n";

	int i{ 100 }; //0b1100100
	cout << i << "\n";
	i <<= 2; //0b110010000 (右侧用0填充，左移两位即 i*=4)
	cout << i << "\n";
	i >>= 2; //0b1100100
	cout << i << "\n";
	int j{ 0b0011011 };
	cout << j << "\n";
	cout << static_cast<int>(j ^ i) << "\n"; //0b1100100与0b0011011做异或运算 = 0b1111111 = 127

	addNumber(i, j);

	vector<int> a{ 1,2,6 };
	array<int, 3> b{ 1,2,6 }; //array b也行 CTAD
	pair<double, int> c{ 1.546, 5 };
	cout << format("1nd element is {}", a[0]) << "\n";
	cout << format("2nd element is {}", b[1]) << "\n";
	cout << format("first element is {}, second element is {}", c.first, c.second) << "\n";

}

int addNumber(int a, int b)
{
	cout << format("当前函数为{}", __func__) << "\n"; //__func__为预定义局部变量包含当前函数名
	return a + b;
}
