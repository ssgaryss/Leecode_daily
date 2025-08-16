#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator>
#include <unordered_map>
#include <numeric>
#include <cmath>
using namespace std;

int getDistance(const pair<int, int>& a, const pair<int, int>& b) {
	float x = static_cast<float>(abs(a.first - b.first));
	float y = static_cast<float>(abs(a.second - b.second));
	auto dis = static_cast<float>(pow(x * x + y * y, 0.5));
	int distance = dis - static_cast<float>((int)dis) < 0.0000001f ? (int)dis : (int)dis + 1;
	return distance;
}

int main() {
	int T;
	int	n, e, p, r1, r2;
	cin >> T >> n >> e >> p >> r1 >> r2;
	vector<pair<int, int>> location(n);
	for (auto& it : location) {
		cin >> it.first >> it.second;
	}
	int min_long = 0, min_youlan = 0;

	int init_youlan = e;
	bool longxue_status = false;
	unordered_map<>

	if (min_long != -1 && min_youlan != -1) {
		min_long = longxue_status ? 1 : 0;
		min_youlan = init_youlan - e;
	}
	cout << min_long << " " << min_youlan;

	//for (const auto& it : location) {
	//	cout << it.first << " " << it.second << "\n";
	//}
	//std::copy(location.begin(), location.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}