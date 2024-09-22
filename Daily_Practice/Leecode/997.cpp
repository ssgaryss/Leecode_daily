#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

int findJudge(int n, vector<vector<int>>& trust) {
	if (!trust.size() && n == 1)
		return 1;
	unordered_map<int, int> IsJudge;
	for (const auto& each : trust) {
		IsJudge[each[1]]++;
		IsJudge[each[0]] = INT_MIN;
	}
	auto it = find_if(IsJudge.begin(), IsJudge.end(), [&n](const auto& a) {
		return a.second == n - 1;
		});
	return it == IsJudge.end() ? -1 : (*it).first;
}

int main() {
	int n = 3;
	vector<vector<int>> trust{
		{1,3},{2,3},{3,1}
	};
	cout << findJudge(n, trust) << "\n";
}