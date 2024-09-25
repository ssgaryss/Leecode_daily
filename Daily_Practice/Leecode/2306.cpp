#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

// ³¬Ê±
//long long distinctNames(vector<string>& ideas) {
//	unordered_map<string, char> Count;
//	unordered_map<char, vector<string>> FirstLetters;
//	long long res = 0;
//	sort(ideas.begin(), ideas.end());
//	const auto& End = unique(ideas.begin(), ideas.end());
//	ideas.erase(End, ideas.end());
//	int n = (int)ideas.size();
//	for (int i = 0; i < n; ++i) {
//		Count[ideas[i]] = ideas[i][0];
//		FirstLetters[ideas[i][0]].emplace_back(ideas[i]);
//	}
//	function<bool(string, char)> check = [&Count](string str, char letter) {
//		str[0] = letter;
//		return !Count[str];
//		};
//	for (int i = 0; i < n; ++i) {
//		for (const auto& FirstLetter : FirstLetters) {
//			if (check(ideas[i], FirstLetter.first)) {
//				for (const auto& it : FirstLetter.second) {
//					if (check(it, ideas[i][0]))
//						res++;
//				}
//			}
//		}
//	}
//	return res;
//}

long long distinctNames(vector<string>& ideas) {
	unordered_map<char, unordered_set<string>> names;
	for (const string& idea : ideas) {
		names[idea[0]].insert(idea.substr(1, idea.size() - 1));
	}
    auto get_intersect_size = [](const unordered_set<string>& a, const unordered_set<string>& b) -> size_t {
        size_t ans = 0;
        for (const string& s : a) {
            if (b.count(s)) {
                ++ans;
            }
        }
        return ans;
        };

    long long ans = 0;
    for (auto&& [pre_a, set_a] : names) {
        for (auto&& [pre_b, set_b] : names) {
            if (pre_a == pre_b) {
                continue;
            }
            int intersect = get_intersect_size(set_a, set_b);
            ans += static_cast<long long>(set_a.size() - intersect) * (set_b.size() - intersect);
        }
    }
    return ans;
}

int main() {
	vector<string> ideas{
		"coffee","donuts","time","toffee"
	};
	cout << distinctNames(ideas) << "\n";
}