#include <iostream>
#include <vector>
using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
	int n = static_cast<int>(fruits.size());
	int res = n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (baskets[j] >= fruits[i]) {
				baskets[j] = -1;
				res--;
				break;
			}
		}
	}
	return res;
}

int main(int argc, char** argv) {
	vector<int> fruits = { 4, 2, 5 };
	vector<int> baskets = { 3, 5, 4 };
	int res = numOfUnplacedFruits(fruits, baskets);
	cout << res << "\n";
}