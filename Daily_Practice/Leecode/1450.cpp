#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
	int n = (int)startTime.size();
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (startTime[i] <= queryTime && queryTime <= endTime[i])
			res++;
	}
	return res;
}

int main() {
	vector startTime{ 1,2,3 };
	vector endTime{ 3,2,7 };
	int queryTime = 4;
	cout << busyStudent(startTime, endTime, queryTime);
}