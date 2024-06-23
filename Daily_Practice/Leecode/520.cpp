#include <iostream>
#include <string>
#include <iomanip>
#include <functional>
using namespace std;

bool detectCapitalUse(string word) {
	if (word.size() <= 1) return true;
	int type = 0; // 1 : 全大写 2 : 全小写 3 : 大写开头
	if (isupper(word[0]) && isupper(word[1])) type = 1;
	if (!isupper(word[0])) type = 2;
	if (isupper(word[0]) && !isupper(word[1])) type = 3;
	if (type == 0) return false;

	for (size_t i = 1; i < word.size(); ++i) {
		if (type == 1 && !isupper(word[i])) return false;
		if (type == 2 && isupper(word[i])) return false;
		if (type == 3 && isupper(word[i])) return false;
	}
	return true;
}

int main() {
	string word{ "USA" };
	bool res = detectCapitalUse(word);
	cout << boolalpha << res << "\n";
}