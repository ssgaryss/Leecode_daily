#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int edgeScore(vector<int>& edges) {
	int n = (int)edges.size();
	unordered_map<int, long long> scores;
	for (int i = 0; i < n; ++i) {
		scores[edges[i]] += i;
	}
	return (*max_element(scores.begin(), scores.end(), [](const auto& a, const auto& b) {
		return a.second < b.second || (a.second == b.second && a.first > b.first);
		})).first;
}

int main() {
	vector edges{ 1,0,0,0,0,7,7,5 };
	cout << edgeScore(edges) << "\n";
}