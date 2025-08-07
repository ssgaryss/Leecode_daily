#include <iostream>
#include <vector>
#include <functional>
using namespace std;

auto _{[]() noexcept{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    return 0;
}()};

int maxCollectedFruits(vector<vector<int>>& fruits) {
    int res = 0;
    int n = static_cast<int>(fruits.size());
    function<int()> getOneRouteMaxFruits = [&n, &fruits]() -> int{
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][n-1] = fruits[0][n-1];
        for(int i = 1;i <= n-2; ++i){
            for(int j = i + 1; j < n; ++j){
                if(j + 1 < n)
                    dp[i][j] = max({dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]}) + fruits[i][j];
                else
                    dp[i][j] = max({dp[i-1][j], dp[i-1][j-1]}) + fruits[i][j];
            }
        }
        return dp[n-2][n-1];
    };
    for(int i = 0;i < n; ++i){
        res += fruits[i][i];
    }
    res += getOneRouteMaxFruits();
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            swap(fruits[i][j], fruits[j][i]);
        }
    }
    res += getOneRouteMaxFruits();
    
    return res;
}

int main(int argc, char** argv){
    vector<vector<int>> fruits  {
        { 1, 2, 3, 4},
        { 5, 6, 8, 7},
        { 9,10,11,12},
        {13,14,15,16}
    };
    auto res = maxCollectedFruits(fruits);
    cout << res << "\n";
}
