#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int candy(vector<int>& ratings) {
	int n = static_cast<int>(ratings.size());
	vector<int> candies(n, 1);
	for (int i = 0; i < n - 1; ++i) {
		if (ratings[i] < ratings[i + 1]) {
			candies[i + 1] = candies[i] + 1;
		}
	}
	for (int i = n - 1; i > 0; --i) {
		if (ratings[i - 1] > ratings[i]) {
			if (candies[i - 1] <= candies[i])
				candies[i - 1] = candies[i] + 1;
		}
	}
	return std::reduce(candies.begin(), candies.end());
}

int main(int argc, char** argv) {
	vector<int> ratings{ 1,0,2 };
	auto res = candy(ratings);
	cout << res << "\n";
}