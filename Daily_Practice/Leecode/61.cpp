#include <iostream>
#include <vector>
using namespace std;

int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
	int res = 0;
	int n = (int)temperatureA.size();
	vector<int> result(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		int resA = 0, resB = 0;
		std::strong_ordering resultA = temperatureA[i] <=> temperatureA[i + 1];
		std::strong_ordering resultB = temperatureB[i] <=> temperatureB[i + 1];
		if (std::is_lt(resultA)) resA = 1;
		if (std::is_eq(resultA)) resA = 2;
		if (std::is_gt(resultA)) resA = 3;
		if (std::is_lt(resultB)) resB = 1;
		if (std::is_eq(resultB)) resB = 2;
		if (std::is_gt(resultB)) resB = 3;
		result[i] = resA - resB;
	}
	int temp = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (result[i] == 0) temp++;
		else {
			res = max(res, temp);
			temp = 0;
		}
	}
	res = max(res, temp);
	return res;
}

int main() {
	vector<int> temperatureA{ 21,18,18,18,31 };
	vector<int> temperatureB{ 34,32,16,16,17 };
	int res = temperatureTrend(temperatureA, temperatureB);
	cout << res << "\n";
}