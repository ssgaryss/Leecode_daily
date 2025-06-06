#include <iostream>
#include <string>
#include <vector>
using namespace std;

string clearStars(string s) {
	int n = static_cast<int>(s.size());
	vector<int> vec[26];
	vector<bool> ban(n);

	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			for (int c = 0; c < 26; c++) if (vec[c].size() > 0) {
				ban[vec[c].back()] = true;
				vec[c].pop_back();
				break;
			}
		}
		else {
			vec[s[i] - 'a'].push_back(i);
		}
	}

	string ans;
	for (int i = 0; i < n; i++) 
		if (s[i] != '*' && !ban[i]) 
			ans.push_back(s[i]);
	return ans;
}

int main(int argc, char** argv) {
	string s = "aaba*"s;
	auto res = clearStars(s);
	cout << res << "\n";
}