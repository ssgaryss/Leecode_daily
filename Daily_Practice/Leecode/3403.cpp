#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string answerString(string word, int numFriends) {
	int n = static_cast<int>(word.length());
	int length = n - numFriends + 1;
	string res = ""s;
	if (numFriends <= 1)
		return word;
	for (int i = 0; i < n; ++i) {
		if (word.substr(i, 1) > res)
			res = word.substr(i, 1);
	}
	for (int i = 0; i < n; ++i) {
		if (word.substr(i, length) > res)
			res = word.substr(i, length);
	}
	return res;
}

int main(int argc, char** argv) {
	string word = "aann"s;
	int numFriends = 2;
	auto res = answerString(word, numFriends);
	cout << res << "\n";
}