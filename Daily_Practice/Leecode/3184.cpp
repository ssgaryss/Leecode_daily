#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int countCompleteDayPairs(vector<int>& hours) {
	int res = 0;
	int n = (int)hours.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if ((hours[i] + hours[j]) % 24 == 0)
				res++;
		}
	}
	return res;
}

int main() {
	vector hours{ 12,12,30,24,24 };
	cout << countCompleteDayPairs(hours) << "\n";
}