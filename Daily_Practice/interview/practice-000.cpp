// https://niumacode.com/problem/P1471
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> getResult(const vector<int>& vInput) {
    int Min = numeric_limits<int>::max();
    int Max = numeric_limits<int>::min();
    int n = static_cast<int>(vInput.size());
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        Min = std::min(Min, vInput[i]);
        Max = std::max(Max, vInput[i]);
        if (Min > 0) {
            res[i] = 0;
        }
        else {
            res[i] = Max + 1;
        }
    }
    return res;
}

int main(int argc, char** argv) {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    copy_n(istream_iterator<int>(cin), n, nums.begin());
    auto res = getResult(nums);
    copy_n(res.begin(), n, ostream_iterator<int>(cout, " "));
    return 0;
}