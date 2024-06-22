#include <iostream>
#include <string>
using namespace std;

string smallestBeautifulString(string s, int k) {
	int n = s.length();
	int i = n - 1;
	s[i] += 1;
	while (i < n)
	{
		if (s[i] == k + 'a') {
			if (i == 0) return "";
			s[i] = 'a';
			s[--i]++;
		}
		else if ((i >= 1 && s[i] == s[i - 1]) || (i > 1 && s[i] == s[i - 2])) {
			s[i]++;
		}
		else {
			i++;
		}
	}
	return s;
}

int main() {
	string	s{ "dc" };
	int k = 4;
	string res = smallestBeautifulString(s, k);
	cout << res << "\n";
}