#include <iostream>

using namespace std;

int getFn(int n) {
	//����1��-1������2��/2������3��/3
	//�㷨�Ĺؼ�������Ҫ�жϳ���2����ǰ���һ��1��������3����ǰ�������1����
	//�������һ��1�����⣬������1���������2��3����
	//�ڴ˻����ϵݹ�
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