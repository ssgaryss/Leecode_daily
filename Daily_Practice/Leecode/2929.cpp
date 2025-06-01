#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

//long long distributeCandies(int n, int limit) {
//    long long res = 0;
//    function<int(int n, int limit)> getNum = [](int n, int limit){
//        return max(min(limit, n) - max(n - limit, 0) + 1, 0);
//    };
//    for(int i = 0;i <= min(n, limit);++i){
//        res += getNum(n - i, limit);
//    }
//    return res;
//}

long long c(long long n) { return n > 1 ? n * (n - 1) / 2 : 0; }

long long distributeCandies(int n, int limit) {
    return c(n + 2) - 3 * c(n - limit + 1) + 3 * c(n - 2 * limit) -
           c(n - 3 * limit - 1);
}

int main(int argc, const char * argv[]) {
    int n = 5;
    int limit = 2;
    auto res = distributeCandies(n, limit);
    cout << res << "\n";
}
