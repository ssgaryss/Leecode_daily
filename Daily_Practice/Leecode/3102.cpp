#include <iostream>
#include <vector>
#include <set>
using namespace std;

int minimumDistance(vector<vector<int>>& points) {
	// distance = max(|(x1-y1)-(x2-y2)|,|(x1+y1)-(x2+y2)|)
	int n = points.size();
	multiset<int> sx, sy;
	for (int i = 0; i < n; ++i) {
		sx.emplace(points[i][0] - points[i][1]);
		sy.emplace(points[i][0] + points[i][1]);
	}
	int res = INT_MAX;
	for (auto& it : points)
	{
		sx.erase(sx.find(it[0] - it[1]));
		sy.erase(sy.find(it[0] + it[1]));
		res = min(res, max(*sx.rbegin() - *sx.begin(), *sy.rbegin() - *sy.begin()));
		sx.emplace(it[0] - it[1]);
		sy.emplace(it[0] + it[1]);
	}
	return res;
}

int main() {
	vector<vector<int>> points{
		{3,2},
		{3,9},
		{7,10},
		{4,4},
		{8,10},
		{2,7}
	};
	int res = minimumDistance(points);
	cout << res << "\n";
}