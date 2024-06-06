#include <iostream>

using namespace std;

int getFn(int n) {
	//方法1：-1、方法2：/2、方法3：/3
	//算法的关键在于需要判断出在2方法前最多一次1方法，在3方法前最多两次1方法
	//除了最后一次1方法外，连续的1方法后必有2或3方法
	//在此基础上递归
	if (n <= 1) return n;
	return min(n % 2 + 1 + getFn(n / 2), n % 3 + 1 + getFn(n / 3));
}

int minDays(int n) {
	return getFn(n);
}


int main() {
	int n = 10;
	int days = minDays(n);
	cout << days;
}