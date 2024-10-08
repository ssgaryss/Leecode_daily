#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

string destCity(vector<vector<string>>& paths) {
	unordered_map<string, int> next;
	for (const auto& path : paths)
		next[path[0]]++;
	for (const auto& path : paths) {
		if (!next.count(path[1]))
			return path[1];
	}
	return ""s;
}

int main() {
	vector<vector<string>> paths{
		{"B","C"},
		{"D","B"},
		{"C","A"}
	};
	cout << destCity(paths) << "\n";
}