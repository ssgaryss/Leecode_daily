#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int maxScoreSightseeingPair(vector<int>& values) {
	int n = (int)values.size();
	int mx = values[0] + 0;
	int res = 0;
	for (int i = 1; i < n; ++i) {
		res = max(res, mx + values[i] - i);
		mx = max(mx, values[i] + i);
	}
	return res;
}

int main() {
	vector values{ 8,1,5,2,6 };
	cout << maxScoreSightseeingPair(values) << "\n";
}