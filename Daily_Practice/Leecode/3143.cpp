#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
	}() };

int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
	int n = (int)points.size();
	vector<pair<int, string>> pointsSize(n); // 记录正形边长一半至少为多少才能包含这个点
	for (int i = 0; i < n; ++i)
		pointsSize[i] = make_pair(max(abs(points[i][0]), abs(points[i][1])), s[i]);
	sort(pointsSize.begin(), pointsSize.end());
	int res = 0;
	unordered_map<string, bool> IsExist;
	int numOfSameSize = 0, Size = pointsSize[0].first;
	for (int i = 0; i <= n; ++i) {
		if (i == n)
			return n;
		if (!IsExist.count(pointsSize[i].second)) {
			IsExist[pointsSize[i].second] = true;
			if (pointsSize[i].first > Size) {
				res += numOfSameSize;
				numOfSameSize = 1, Size = pointsSize[i].first;
			}
			else
				numOfSameSize++;
		}
		else {
			if (pointsSize[i].first > Size)
				res += numOfSameSize;
			break;
		}
	}
	return res;
}

int main() {
	vector<vector<int>> points{
		{16,32},{27,3},{23,-14},{-32,-16},{-3,26},{-14,33}
	};
	string s = "aaabfc"s;
	auto res = maxPointsInsideSquare(points, s);
	cout << res << "\n";
}