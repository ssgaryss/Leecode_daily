#include <iostream>
#include <string>
using namespace std;

auto _{ []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    return 0;
}() };

int longestContinuousSubstring(string s) {
    int n = (int)s.size();
    int res = 1;
    int cur = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] + 1 == s[i + 1]) {
            cur++;
        }
        else {
            res = max(res, cur);
            cur = 1;
        }
    }
    res = max(res, cur);
    return res;
}

int main() {
    string s = "abcde"s;
    cout << longestContinuousSubstring(s) << "\n";
}