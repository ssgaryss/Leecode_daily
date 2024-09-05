#include <iostream>
#include <string>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

string clearDigits(string s) {
	int count = 0;
	int n = (int)s.length();
	for (int i = n - 1; i >= 0; --i) {
		if (isdigit(s[i])) {
			s.erase(s.begin() + i);
			count++;
		}
		else if (islower(s[i]) && count > 0) {
			s.erase(s.begin() + i);
			count--;
		}
	}
	return s;
}

int main() {
	string s{ "a8f" };
	cout << clearDigits(s) << "\n";
}