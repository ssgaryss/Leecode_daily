#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int maximumLength(string s) {
	//3 <= s.length <= 50, s ����СдӢ����ĸ���
	array<vector<int>, 26> record; //��¼ÿ����ĸ���������ִ���Ŀ
	int count = 0;
	for (int i = 0; i < s.length(); ++i) {
		count++;
		if (i + 1 == s.length() || s[i] != s[i + 1]) {
			record[s[i] - 'a'].emplace_back(count);
			count = 0;
		}
	}
	int ans = -1;
	for (auto& it : record) {
		if (it.empty()) continue;
		sort(it.begin(), it.end(), [](int a, int b) {
			return a > b;
			});
		it.emplace_back(-1); it.emplace_back(-1); //��֤��Խ��
		ans = max({ it[0] - 2, ans, it[2], min(it[0] - 1, it[1]) });
	}
	return ans ? ans : -1;
}

int main() {
	string s = "abcdef";
	int ans = maximumLength(s);
	cout << ans << "\n";
}


//ans = max({ it[0] - 2, ans, it[2], min(it[0] - 1, it[1]) }); std::max ���Խ���һ����ʼ���б������ظ��б��е����ֵ��