#include <iostream>
using namespace std;

int sumOfTheDigitsOfHarshadNumber(int x) {
	int (*SumOfDigits)(int) = [](int x) {
		int sum = 0;
		int num = x;
		while (num != 0)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
		};

	int sum = SumOfDigits(x);
	return x % sum ? -1 : sum;
}

int main() {
	int num = 18;
	int res = sumOfTheDigitsOfHarshadNumber(num);
	cout << res << "\n";
}