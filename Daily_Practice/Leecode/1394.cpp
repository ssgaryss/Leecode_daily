#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findLucky(vector<int>& arr) {
	int res = -1;
	unordered_map<int, int> count;
	for (auto it : arr)
		count[it]++;
	for (const auto& it : count) {
		if (it.first == it.second)
			res = std::max(res, it.first);
	}
	return res;
}

int main(int argc, char** argv) {
	vector<int> arr{ 1,2,2,3,3,3 };
	auto res = findLucky(arr);
	cout << res << "\n";
}