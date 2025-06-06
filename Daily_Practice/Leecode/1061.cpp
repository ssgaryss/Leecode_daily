#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;

string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<int> parent(26);

    for (int i = 0; i < 26; ++i) 
        parent[i] = i;

    // Find with path compression
    function<int(int)> find = [&](int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

    // Union：将两个集合合并，保证字典序小的为代表
    auto unite = [&](int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) 
            return;
        if (px < py) 
            parent[py] = px;
        else 
            parent[px] = py;

        };

    for (int i = 0; i < s1.size(); ++i) {
        unite(s1[i] - 'a', s2[i] - 'a');
    }

    for (char& c : baseStr) {
        c = find(c - 'a') + 'a'; // 转换为等价类的最小代表字符
    }

    return baseStr;
}

int main(int argc, char** argv) {
	string s1 = "dccaccbdafgeabeeghbigbhicggfbhiccfgbechdicbhdcgahi"s;
	string s2 = "igfcigeciahdafgegfbeddhgbacaeehcdiehiifgbhhehhccde"s;
	string baseStr = "sanfbzzwblekirguignnfkpzgqjmjmfokrdfuqbgyflpsfpzbo"s;
	auto res = smallestEquivalentString(s1, s2, baseStr);
	cout << res << "\n";
}