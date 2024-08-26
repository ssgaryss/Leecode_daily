#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int findPermutationDifference(string s, string t) {
	int n = (int)s.length();
	int res = 0;
	unordered_map<char, int> s_index;
	for (int i = 0; i < n; ++i)
		s_index[s[i]] = i;
	for (int i = 0; i < n; ++i)
		res += abs(i - s_index[t[i]]);
	return res;
}

int main() {
	string s{ "rwohu" };
	string t{ "rwuoh" };
	auto res = findPermutationDifference(s, t);
	cout << res << "\n";
}