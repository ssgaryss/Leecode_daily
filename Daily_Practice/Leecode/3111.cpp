#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
	int n = (int)points.size();
	sort(points.begin(), points.end());
	int res = 1;
	int RectStart = points[0][0];
	for (int i = 0; i < n; ++i) {
		if (points[i][0] > RectStart + w) {
			res++;
			RectStart = points[i][0];
		}
	}
	return res;
}

int main() {
	vector<vector<int>> points{
		{2,1},{1,0},{1,4},{1,8},{3,5},{4,6}
	};
	int w = 1;
	int res = minRectanglesToCoverPoints(points, w);
	cout << res << "\n";
}