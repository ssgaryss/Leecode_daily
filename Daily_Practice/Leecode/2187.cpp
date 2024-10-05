#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

long long minimumTime(vector<int>& time, int totalTrips) {
	// ¶þ·Ö²éÕÒ
	function<bool(long long)> check = [&](long long t)->bool {
		long long sum = 0;
		for (auto it : time) {
			sum += t / it;
		}
		return sum >= totalTrips;
		};

	long long l = 1;
	long long r = (long long)*max_element(time.begin(), time.end()) * totalTrips;
	while (l < r)
	{
		long long mid = l + (r - l) / 2;
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}

int main() {
	vector time{ 5,10,10 };
	int totalTrips = 9;
	cout << minimumTime(time, totalTrips) << "\n";
}