#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

long long findMaximumElegance(vector<vector<int>>& items, int k) {
	sort(items.begin(), items.end(), [](vector<int> a, vector<int> b) {
		return a[0] > b[0];
		});
	long long res = 0;
	long long profit = 0;
	int n = items.size();
	long long categoriesCount = 0;
	unordered_set<int> categories;
	vector<int> allowChange; //同种类但多余一个的部分
	for (int i = 0; i < n; ++i) {
		if (i < k) {
			profit += items[i][0];
			if (categories.count(items[i][1])) {
				allowChange.emplace_back(items[i][0]);
			}
			else {
				categories.insert(items[i][1]);
				categoriesCount++;
			}
		}
		else {
			if (categories.count(items[i][1]) == 0 && !allowChange.empty()) {
				categoriesCount++;
				categories.insert(items[i][1]);
				profit -= allowChange.back() - items[i][0];
				allowChange.pop_back();
			}
		}
		res = max(res, profit + categoriesCount * categoriesCount);
	}
	return res;
}

int main() {
	vector<vector<int>> items{
		{3,4},
		{8,4},
		{2,2},
		{1,3},
	};
	int k = 2;
	long long res = findMaximumElegance(items, k);
	cout << res << "\n";
}