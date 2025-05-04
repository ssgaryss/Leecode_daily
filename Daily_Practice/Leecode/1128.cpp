#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Domino
{
public:
	Domino() = default;
	Domino(const std::pair<int, int>& vValue) {
		m_Value = std::minmax(vValue.first, vValue.second);
	}
	operator std::pair<int, int>() const {
		return std::minmax(m_Value.first, m_Value.second);
	}
	auto operator<=>(const Domino& vOther) const = default;
private:
	std::pair<int, int> m_Value;
};

namespace std {
	template <>
	struct hash<Domino> {
		size_t operator()(const Domino& p) const {
			auto ps = static_cast<std::pair<int, int>>(p);
			return std::hash<int>()(ps.first) ^ (std::hash<int>()(ps.second) << 1);
		}
	};
}

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
	int res = 0;
	int n = static_cast<int>(dominoes.size());
	unordered_map<Domino, int> record;
	for (int i = 0; i < n; ++i) {
		Domino temp = pair{ dominoes[i][0], dominoes[i][1] };
		if (record.count(temp))
			res += record[temp];
		record[temp]++;
	}
	return res;
}

int main(int argc, char** argv) {
	vector<vector<int>> dominoes{
		{1,2},
		{2,1},
		{3,4},
		{5,6},
	};
	auto res = numEquivDominoPairs(dominoes);
	cout << res << "\n";
}