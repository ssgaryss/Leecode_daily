#include <iostream>
#include <vector>
#include <functional>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
	int n = (int)variables.size();
	vector<int> res;
	res.reserve(n);
	// ±‹√‚“Á≥ˆ!!!÷ÿ–¥º∆À„ a^b % c
	function<int(int, int, int)> pow_mod = [](int a, int b, int c) {
		int result = 1;
		while (b)
		{
			if (b & 1)
				result = result * a % c;

			a = a * a % c;
			b >>= 1;
		}
		return result;
		};
	for (int i = 0; i < n; ++i) {
		int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
		if (pow_mod(pow_mod(a, b, 10), c, m) == target)
			res.emplace_back(i);

	}
	return res;
}

int main() {
	vector<vector<int>> variables{
		{2,3,3,10},
		{3,3,3,1},
		{6,1,1,4}
	};
	int target = 2;
	auto res = getGoodIndices(variables, target);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
}