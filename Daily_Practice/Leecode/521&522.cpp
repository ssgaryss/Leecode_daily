#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

int findLUSlength(string a, string b) {
	return a != b ? max(a.length(), b.length()) : -1;
}

int findLUSlength(vector<string>& strs) {
	function<bool(string&, string&)> isSubsquence{ [](string& s, string& t) {
		int s_len = s.size();
		int t_len = t.size();
		int s_index = 0, t_index = 0;

		while (s_index < s_len && t_index < t_len) {
			if (s[s_index] == t[t_index]) {
				++s_index;
			}
			++t_index;
		}

		return s_index == s_len;
		} };

	int length = -1;
	bool notMatch = false;
	for (int i = 0; i < strs.size(); ++i) {
		notMatch = false;
		for (int j = 0; j < strs.size(); ++j) {
			if (i!=j &&isSubsquence(strs[i], strs[j])) {
				notMatch = true;
				break;
			}
		}
		if (!notMatch)
			length = max(length, (int)strs[i].length());
	}

	return length;
}

int main() {
	// 521
	string a{ "aba" }, b{ "cdc" };
	int res_521 = findLUSlength(a, b);
	cout << res_521 << "\n";
	// 522
	vector<string> strs_522{ "aaa","aaa","aa" };
	int res_522 = findLUSlength(strs_522);
	cout << res_522 << "\n";
}