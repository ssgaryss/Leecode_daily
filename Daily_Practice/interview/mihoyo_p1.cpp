// N个输入样本，区间[l,r]内有多少个三元组（a,b,c）
// 满足a<b<c,max(a,b,c) < lcm(a,b,c) < sum(a,b,c)
// 输出满足条件三元组个数

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int lcm(int a, int b, int c) {
	return lcm(lcm(a, b), c);
}

int main(int argc, char** argv) {
	int N;
	cin >> N;

	while (N--) {
		int l, r;
		cin >> l >> r;  // 输入一个区间
		long long count = 0;

		for (int a = l; a <= r; a++) {
			for (int b = a + 1; b <= r; b++) {
				for (int c = b + 1; c <= r; c++) {
					int L = lcm(a, b, c);
					int mx = max({ a, b, c });
					int sum = a + b + c;
					if (mx < L && L < sum) {
						cout << "(" << a << "," << b << "," << c << ")  "
							<< "max=" << mx << "  lcm=" << L << "  sum=" << sum << "\n";
						count++;
					}
				}
			}
		}
		cout << count << "\n";  // 输出当前区间的结果
	}

	return 0;
}
