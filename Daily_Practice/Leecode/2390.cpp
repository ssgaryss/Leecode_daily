#include <iostream>
#include <vector>
#include <string>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

string removeStars(string s) {
	string res;
	for (const auto& ch : s) {
		if (ch == '*')
			res.pop_back();
		else
			res.push_back(ch);
	}
	return res;
}

int main() {
	string s = "leet**cod*e";
	cout << removeStars(s) << "\n";
}