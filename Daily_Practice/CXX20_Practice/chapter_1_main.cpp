#include <iostream>
#include <limits>
#include <cmath>
#include <format>
#include <vector>
#include <array>


using namespace std;

int addNumber(int a, int b);

int main(int argc, char* argv[]) {
	////{}:��ʼ����
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
	i <<= 2; //0b110010000 (�Ҳ���0��䣬������λ�� i*=4)
	cout << i << "\n";
	i >>= 2; //0b1100100
	cout << i << "\n";
	int j{ 0b0011011 };
	cout << j << "\n";
	cout << static_cast<int>(j ^ i) << "\n"; //0b1100100��0b0011011��������� = 0b1111111 = 127

	addNumber(i, j);

	vector<int> a{ 1,2,6 };
	array<int, 3> b{ 1,2,6 }; //array bҲ�� CTAD
	pair<double, int> c{ 1.546, 5 };
	cout << format("1nd element is {}", a[0]) << "\n";
	cout << format("2nd element is {}", b[1]) << "\n";
	cout << format("first element is {}, second element is {}", c.first, c.second) << "\n";

}

int addNumber(int a, int b)
{
	cout << format("��ǰ����Ϊ{}", __func__) << "\n"; //__func__ΪԤ����ֲ�����������ǰ������
	return a + b;
}
