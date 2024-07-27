#include <iostream>
#include <string.h>
#include <functional>
using namespace std;

string getSmallestString(string s, int k) {
	function<int(char, char)> getDistance = [](char a, char b) -> decltype(auto) {
		int temp = abs(a - b);
		return min(temp, 26 - temp);
		};
	int n = (int)s.length();
	for (int i = 0; i < n; ++i) {
		int temp = getDistance(s[i], 'a');
		if (temp <= k) {
			k -= temp;
			s[i] = 'a';
		}
		else {
			s[i] = s[i] - k;
			break;
		}
	}
	return s;
}

int main() {
	string s{ "zbbz"s };
	int k = 3;
	auto res = getSmallestString(s, k);
	cout << res << "\n";
}