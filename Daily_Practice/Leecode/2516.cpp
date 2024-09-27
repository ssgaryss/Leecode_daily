#include <iostream>
#include <string>
#include <vector>
using namespace std;

int takeCharacters(string s, int k) {
    vector<int> cnt(3, 0);
    int len = s.size();
    int ans = len;
    for (int i = 0; i < len; i++) {
        cnt[s[i] - 'a']++;
    }
    if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
        ans = min(ans, len);
    }
    else {
        return -1;
    }

    int l = 0;
    for (int r = 0; r < len; r++) {
        cnt[s[r] - 'a']--;
        while (l < r && (cnt[0] < k || cnt[1] < k || cnt[2] < k)) {
            cnt[s[l] - 'a']++;
            l++;
        }
        if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
            ans = min(ans, len - (r - l + 1));
        }
    }

    return ans;
}

int main() {
	string s = "aabaaaacaabc"s;
	int k = 2;
	cout << takeCharacters(s, k) << "\n";
}