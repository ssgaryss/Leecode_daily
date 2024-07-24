#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
	unordered_map<int, bool> IsOccupied;
	for (auto it : nums)
		IsOccupied[it] = true;
	for (int i = 0; i < moveFrom.size(); ++i) {
		IsOccupied.erase(moveFrom[i]);
		IsOccupied[moveTo[i]] = true;
	}
	vector<int> res;
	for (auto it : IsOccupied)
		res.emplace_back(it.first);
	sort(res.begin(), res.end());
	return res;
}

int main() {
	vector nums{ 1,1,3,3 };
	vector moveFrom{ 1,3 }, moveTo{ 2,2 };
	auto res = relocateMarbles(nums, moveFrom, moveTo);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
}