#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool checkRecord(string s) {
	int A = 0, L = 0;
	for (const auto& it : s) {
		if (it == 'A') {
			A++;
			if (A > 1) return false;
		}
		if (it == 'L') L++;
		if (it != 'L') L = 0;
		if (L > 2) return false;
	}
	return true;
}

int main() {
	string s{ "PPALLP"s };
	bool res = checkRecord(s);
	cout << boolalpha << res << "\n";
}