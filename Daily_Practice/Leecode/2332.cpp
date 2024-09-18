#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	return 0;
	}() };

int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
	sort(buses.begin(), buses.end());
	sort(passengers.begin(), passengers.end());
	int n = (int)passengers.size();
	int index = 0;  // passenger index
	int cur_capacity = 0;
	for (auto bus : buses) {
		cur_capacity = capacity;
		while (index < n && bus >= passengers[index] && cur_capacity > 0) {
			cur_capacity--;
			index++;
		}
	}
	index--;
	int res = cur_capacity > 0 ? buses.back() : passengers[index];
	while (index >= 0 && passengers[index] == res) {
		res--;
		index--;
	}
	return res;
}

int main() {
	vector bused{ 3 };
	vector passengers{ 2, 3 };
	int capacity = 2;
	cout << latestTimeCatchTheBus(bused, passengers, capacity) << "\n";
}