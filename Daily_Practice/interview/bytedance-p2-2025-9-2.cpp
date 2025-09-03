#include <iostream>
#include <string>
#include <algorithm> // reverse
#include <cstdint>   // int64_t
#include <climits>   // LLONG_MIN

using namespace std;

// 将两个int64_t相乘，结果转为字符串
string multiplyInt64ToString(int64_t a, int64_t b) {
	// 处理符号位
	bool isNegative = (a < 0) ^ (b < 0);
	uint64_t abs_a = a == LLONG_MIN ? static_cast<uint64_t>(LLONG_MAX) + 1 : abs(a);
	uint64_t abs_b = b == LLONG_MIN ? static_cast<uint64_t>(LLONG_MAX) + 1 : abs(b);

	// 大数乘法（按位相乘）
	uint64_t low = 0, high = 0;
	for (int i = 0; i < 64; ++i) {
		if (abs_b & (1ULL << i)) {
			uint64_t carry = 0;
			uint64_t temp_a = abs_a;
			uint64_t temp_low = low;
			uint64_t temp_high = high;

			// 64位加法（处理进位）
			for (int j = 0; j < 64; ++j) {
				uint64_t bit = (temp_a & (1ULL << j)) ? 1 : 0;
				uint64_t sum = (temp_low & (1ULL << j)) ? 1 : 0;
				sum += bit + carry;
				carry = sum >> 1;
				if (sum & 1) temp_low |= (1ULL << j);
				else temp_low &= ~(1ULL << j);
			}

			// 处理高位进位
			for (int j = 0; j < 64; ++j) {
				uint64_t bit = (temp_high & (1ULL << j)) ? 1 : 0;
				uint64_t sum = bit + carry;
				carry = sum >> 1;
				if (sum & 1) temp_high |= (1ULL << j);
				else temp_high &= ~(1ULL << j);
			}

			low = temp_low;
			high = temp_high;
		}
		abs_a <<= 1;
	}

	// 合并高低位到字符串
	string result;
	uint64_t val[2] = { low, high };
	bool leadingZero = true;

	for (int i = 1; i >= 0; --i) {
		for (int j = 63; j >= 0; --j) {
			if (val[i] & (1ULL << j)) {
				leadingZero = false;
				result += '1';
			}
			else if (!leadingZero) {
				result += '0';
			}
		}
	}

	if (result.empty()) result = "0";

	// 二进制转十进制
	string decimal;
	while (!result.empty()) {
		uint64_t remainder = 0;
		string temp;
		for (char c : result) {
			remainder = remainder * 2 + (c - '0');
			if (remainder >= 10) {
				temp += '0' + remainder / 10;
				remainder %= 10;
			}
			else if (!temp.empty()) {
				temp += '0';
			}
		}
		decimal += '0' + remainder;
		result = temp;
	}

	reverse(decimal.begin(), decimal.end());
	if (isNegative && decimal != "0") decimal = "-" + decimal;
	return decimal;
}

int main() {
	// 测试用例
	cout << multiplyInt64ToString(123456789, 987654321) << endl;  // 121932631112635269
	cout << multiplyInt64ToString(-2, 3) << endl;                 // -6
	cout << multiplyInt64ToString(LLONG_MAX, LLONG_MAX) << endl; // 85070591730234615847396907784232501249
	cout << multiplyInt64ToString(0, 123) << endl;                // 0
	return 0;
}
