#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

long long maximumSubsequenceCount(string text, string pattern) {
	int n = (int)text.length();
	long long res = 0;
	int num_former{}, num_latter{};
	for (int i = 0; i < n; ++i) {
		if (text[i] == pattern[1]) {
			num_latter++;
			res += num_former;
		}
		if (text[i] == pattern[0])
			num_former++;
	}
	res += max(num_former, num_latter);
	return res;
}

int main() {
	string text = "abdcdbc"s;
	string pattern = "ac"s;
	cout << maximumSubsequenceCount(text, pattern) << "\n";
}