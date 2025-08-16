#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <iterator>
#include <unordered_map>
#include <numeric>
using namespace std;

#define MAX_DISTANCE 1000000;


vector<int> getResult(int n, const vector<pair<int, int>>& events) {
	vector<int> pos(n + 2, -1);
	pos[0] = 1;
	pos[n + 1] = 1;
	unordered_map<int, int> id2pos;
	function<int()> getPosition = [&pos]() -> int {
		int len = static_cast<int>(pos.size());
		int min_distance = MAX_DISTANCE;
		int min_distance_index = -1;
		int part = 0; // Ã¿¶Î³¤¶È
		for (int i = len - 1; i >= 0; --i) {
			if (part == len - 2)
				return 1;
			if (pos[i] != -1) {
				if (min_distance >= (part / 2) && part > 0) {
					if (i + part == len - 2) {
						min_distance_index = len - 2;
						break;
					}
					else if (i == 0)
						min_distance_index = 1;
					else {
						min_distance = part / 2;
						min_distance_index = part % 2 ? (i + min_distance + 1) : (i + min_distance);
					}
				}
				part = 0;
			}
			else {
				part++;
			}
		}
		return min_distance_index;
		};

	vector<int> result;
	result.reserve(100);
	for (const auto& it : events) {
		if (it.first == 1) {
			if (id2pos.count(it.second))
				continue;
			int add_index = getPosition();
			pos[add_index] = 1;
			id2pos[it.second] = add_index;
			result.emplace_back(add_index);
		}
		else if (it.first == 2) {
			if (id2pos.count(it.second)) {
				result.emplace_back(id2pos[it.second]);
				pos[id2pos[it.second]] = -1;
				id2pos.erase(it.second);
			}
		}
	}
	return result;
}

int main() {
	int  n = 0, m = 0;
	cin >> n >> m;
	vector<pair<int, int>> events(m);
	for (auto& it : events) {
		cin >> it.first >> it.second;
	}
	auto result = getResult(n, events);

	//for (const auto& it : events) {
	//	cout << it.first << " " << it.second << "\n";
	//}
	std::copy(result.begin(), result.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}