#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
	unordered_map<int, int> times;
	vector<int> temp;
	for (size_t i = 0; i < matches.size(); ++i) {
		times[matches[i][1]]--;
		temp.emplace_back(matches[i][0]);
		temp.emplace_back(matches[i][1]);
	}
	vector<vector<int>> ans(2, vector<int>());
	sort(temp.begin(), temp.end());
	for (size_t i = 0; i < temp.size(); ++i) {
		if (i + 1 >= temp.size() || temp[i + 1] != temp[i]) { //此处i+1判断要在前，否则先判断后者会访问越界
			if (times.count(temp[i])) {
				if (times[temp[i]] == -1) ans[1].emplace_back(temp[i]);
			}
			else {
				ans[0].emplace_back(temp[i]);
			}
		}
	}

	return ans;
}

int main() {
	vector<vector<int>> matches
	{
		{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}
	};
	vector<vector<int>> ans{ findWinners(matches) };
}