#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <iterator>
#include <utility>
using namespace std;

vector<vector<string>> process(vector<int>& nums, vector<pair<string, vector<int>>>& choices) {
	vector<vector<string>> res(3, vector<string>());
	for (auto& it : choices) {
		for (auto i : it.second) {
			if (nums[i] > static_cast<int>(res[i].size())) {
				res[i].emplace_back(it.first);
				break;
			}
		}
	}
	return res;
}

int main() {
	int N;
	vector<int> nums(3);
	vector<pair<string, vector<int>>> choices;
	cin >> N;
	for (auto& i : nums) {
		cin >> i;
	}
	string id;
	int X;
	for (int k = 0; k < N; ++k) {
		cin >> id >> X;
		vector<int> list;
		list.reserve(X);
		for (int i = 0; i < X; ++i) {
			string Value;
			if (cin >> Value) {
				int temp = -1;
				if (Value == "A") temp = 0;
				else if (Value == "B") temp = 1;
				else if (Value == "C") temp = 2;
				list.emplace_back(temp);
			}
			else {
				break;
			}
		}
		choices.emplace_back(make_pair(id, list));
	}

	auto res = process(nums, choices);
	
	for (auto& it : res) {
		cout << static_cast<int>(it.size()) << " ";
		copy(it.begin(), it.end(), ostream_iterator<string>(cout, " "));
		cout << "\n";
	}
}