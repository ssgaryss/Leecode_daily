#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
	vector<int> ans{};
	int sum_m = accumulate(rolls.begin(), rolls.end(), 0);
	int sum_n = mean * (n + static_cast<int>(rolls.size())) - sum_m;
	if (n * 6 < sum_n || sum_n < n) return ans;
	else {
		int l = sum_n / n;
		int k = sum_n % n;
		for (int i = 0; i < n; ++i) {
			if (i < k)
				ans.emplace_back(l + 1);
			else
				ans.emplace_back(l);
		}
	}
	return ans;
}

int main() {
	vector<int> rolls{ 6,3,4,3,5,3 };
	int n = 6;
	int mean = 1;
	vector<int> ans{ missingRolls(rolls, mean, n) };
}