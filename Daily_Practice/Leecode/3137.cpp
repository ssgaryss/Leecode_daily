#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

int minimumOperationsToMakeKPeriodic(string word, int k) {
	unordered_map<string, int> times;
	int n = (int)word.size();
	for (int i = 0; i < n / k; ++i) {
		times[word.substr(i * k, k)]++;
	}
	int res = INT_MAX;
	for (const auto& subword : times)
		res = min(res, n / k - subword.second);
	return res;
}

int main() {
	string word = "leetcodeleet"s;
	int k = 4;
	auto res = minimumOperationsToMakeKPeriodic(word, k);
	cout << res << "\n";
}