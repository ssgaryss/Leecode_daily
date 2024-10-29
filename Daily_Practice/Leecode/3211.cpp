#include <iostream>
#include <vector>
#include <string>
using namespace std;

string intToBinaryString(int num, int n) {
    string binary(n, '0');
    for (int j = 0; j < n; j++) {
        binary[n - 1 - j] = (num & (1 << j)) ? '1' : '0';
    }
    return binary;
}

vector<string> validStrings(int n) {
    vector<string> res;
    int mask = (1 << n) - 1;
    for (int i = 0; i < (1 << n); i++) {
        int t = mask ^ i;
        if (!(t >> 1 & t)) {
            res.push_back(intToBinaryString(i, n));
        }
    }
    return res;
}

int main() {
    int n = 3;
    auto res = validStrings(n);
    std::copy(res.begin(), res.end(), std::ostream_iterator<string>(cout, ", "));
}