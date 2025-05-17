#include <iostream>
#include <vector>

using namespace std;

static constexpr long long mod = static_cast<int>(1e9 + 7);

int colorTheGrid(int m, int n) {
    if (m == 1)
    {
        int ans = 3;
        for (int i = 1; i < n; ++i)    ans = ans * 2LL % mod;
        return ans;
    }
    else if (m == 2)
    {
        int fi = 6;
        for (int i = 1; i < n; ++i)    fi = 3LL * fi % mod;
        return fi;
    }
    else if (m == 3)
    {
        int fi0 = 6, fi1 = 6;
        for (int i = 1; i < n; ++i) {
            int new_fi0 = (2LL * fi0 + 2LL * fi1) % mod;
            int new_fi1 = (2LL * fi0 + 3LL * fi1) % mod;
            fi0 = new_fi0;
            fi1 = new_fi1;
        }
        return ((long long)fi0 + fi1) % mod;
    }
    else if (m == 4)
    {
        //ABAB//ABAC//ABCA//ABCB
        int fi0 = 6, fi1 = 6, fi2 = 6, fi3 = 6;
        for (int i = 1; i < n; ++i) {
            int new_fi0 = (3LL * fi0 + 2LL * fi1 + 1LL * fi2 + 2LL * fi3) % mod;
            int new_fi1 = (2LL * fi0 + 2LL * fi1 + 1LL * fi2 + 2LL * fi3) % mod;
            int new_fi2 = (1LL * fi0 + 1LL * fi1 + 2LL * fi2 + 1LL * fi3) % mod;
            int new_fi3 = (2LL * fi0 + 2LL * fi1 + 1LL * fi2 + 2LL * fi3) % mod;
            fi0 = new_fi0;
            fi1 = new_fi1;
            fi2 = new_fi2;
            fi3 = new_fi3;
        }
        return ((long long)fi0 + fi1 + fi2 + fi3) % mod;
    }
    else
    {
        //ABABA//ABABC//ABACA//ABACB//ABCAB//ABCAC//ABCBA//ABCBC
        int fi0 = 6, fi1 = 6, fi2 = 6, fi3 = 6, fi4 = 6, fi5 = 6, fi6 = 6, fi7 = 6;
        for (int i = 1; i < n; ++i) {
            int new_fi0 = (3LL * fi0 + 2LL * fi1 + 2LL * fi2 + 1LL * fi3 + 0LL * fi4 + 1LL * fi5 + 2LL * fi6 + 2LL * fi7) % mod;
            int new_fi1 = (2LL * fi0 + 2LL * fi1 + 2LL * fi2 + 1LL * fi3 + 1LL * fi4 + 1LL * fi5 + 1LL * fi6 + 1LL * fi7) % mod;
            int new_fi2 = (2LL * fi0 + 2LL * fi1 + 2LL * fi2 + 1LL * fi3 + 0LL * fi4 + 1LL * fi5 + 2LL * fi6 + 2LL * fi7) % mod;
            int new_fi3 = (1LL * fi0 + 1LL * fi1 + 1LL * fi2 + 2LL * fi3 + 1LL * fi4 + 1LL * fi5 + 1LL * fi6 + 1LL * fi7) % mod;
            int new_fi4 = (0LL * fi0 + 1LL * fi1 + 0LL * fi2 + 1LL * fi3 + 2LL * fi4 + 1LL * fi5 + 0LL * fi6 + 1LL * fi7) % mod;
            int new_fi5 = (1LL * fi0 + 1LL * fi1 + 1LL * fi2 + 1LL * fi3 + 1LL * fi4 + 2LL * fi5 + 1LL * fi6 + 1LL * fi7) % mod;
            int new_fi6 = (2LL * fi0 + 1LL * fi1 + 2LL * fi2 + 1LL * fi3 + 0LL * fi4 + 1LL * fi5 + 2LL * fi6 + 1LL * fi7) % mod;
            int new_fi7 = (2LL * fi0 + 1LL * fi1 + 2LL * fi2 + 1LL * fi3 + 1LL * fi4 + 1LL * fi5 + 1LL * fi6 + 2LL * fi7) % mod;
            fi0 = new_fi0;
            fi1 = new_fi1;
            fi2 = new_fi2;
            fi3 = new_fi3;
            fi4 = new_fi4;
            fi5 = new_fi5;
            fi6 = new_fi6;
            fi7 = new_fi7;
        }
        return ((long long)fi0 + fi1 + fi2 + fi3 + fi4 + fi5 + fi6 + fi7) % mod;
    }
}

int main(int argc, char** argv) {
	int m = 1, n = 2;
	auto res = colorTheGrid(m, n);
	cout << res << "\n";
}