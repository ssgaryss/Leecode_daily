#include <iostream>
#include <string>
using namespace std;

auto _{ []() noexcept {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	return 0;
	}() };

long long minimumSteps(string s) {
	long long blackNums = 0;
	long long steps = 0;
	for (long long i = 0; i < s.length(); ++i) {
		if (s[i] == '1') {
			blackNums++;
			steps += s.length() - i;
		}
	}
	steps -= (1 + blackNums) * blackNums / 2;

	return steps;
}

int main() {
	string s = "101";
	int steps = minimumSteps(s);
	cout << steps << "\n";
}