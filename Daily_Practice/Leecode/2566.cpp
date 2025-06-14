#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int minMaxDifference(int num) {
    string s = to_string(num);
    string t = s;
    size_t pos = s.find_first_not_of('9');
    if (pos != string::npos) {
        char a = s[pos];
        replace(s.begin(), s.end(), a, '9');
    }
    char b = t[0];
    replace(t.begin(), t.end(), b, '0');
    return stoi(s) - stoi(t);
}

int main(int argc, char** argv) {
	int num = 90;
	auto res = minMaxDifference(num);
	cout << res << "\n";
}