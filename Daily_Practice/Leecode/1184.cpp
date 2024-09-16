#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
	int round = reduce(distance.begin(), distance.end());
	int temp = reduce(distance.begin() + (start < destination ? start : destination),
		distance.begin() + (start < destination ? destination : start));
	return min(temp, round - temp);
}

int main() {
	vector distance{ 1,2,3,4 };
	int start = 0, destination = 1;
	cout << distanceBetweenBusStops(distance, start, destination) << "\n";
}