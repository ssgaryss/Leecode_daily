#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;


int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
	int n = static_cast<int>(tops.size());
	array<int, 6> cache_top{};
	array<int, 6> cache_bottom{};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (cache_top[j] != -1 && tops[i] == j + 1) {
				cache_top[j]++;
			}
			else if(tops[i] != j + 1 && bottoms[i] != j + 1){
				cache_top[j] = -1;
			}

			if (cache_bottom[j] != -1 && bottoms[i] == j + 1) {
				cache_bottom[j]++;
			}
			else if (tops[i] != j + 1 && bottoms[i] != j + 1) {
				cache_bottom[j] = -1;
			}
		}
	}
	int res_a = *min_element(cache_top.begin(), cache_top.end(), [&n](int a, int b) {
		return (a == -1 ? std::numeric_limits<int>::max() : min(a, n - a)) < (b == -1 ? std::numeric_limits<int>::max() : min(b, n - b));
		});
	int res_b = *min_element(cache_bottom.begin(), cache_bottom.end(), [&n](int a, int b) {
		return (a == -1 ? std::numeric_limits<int>::max() : min(a, n - a)) < (b == -1 ? std::numeric_limits<int>::max() : min(b, n - b));
		});

	return min((res_a == std::numeric_limits<int>::max() ? -1 : min(res_a, n - res_a)),
		(res_b == std::numeric_limits<int>::max() ? -1 : min(res_b, n - res_b)));
}

int main(int argc, char** argv) {
	vector<int> tops{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	vector<int> bottoms{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	auto res = minDominoRotations(tops, bottoms);
	cout << res << "\n";
}