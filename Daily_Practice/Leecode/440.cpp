#include <iostream>
using namespace std;

long getSteps(long n, long n1, long n2) {
    long steps = 0;
    while (n1 <= n) {
        steps += min(n + 1, n2) - n1;
        n1 *= 10;
        n2 *= 10;
    }
    return steps;
}

int findKthNumber(int n, int k) {
    long curr = 1;  // 从1开始
    --k;  // 因为我们已经包含了1

    while (k > 0) {
        long steps = getSteps(n, curr, curr + 1);
        if (steps <= k) {
            // 不在这个子树中，跳到下一个兄弟节点
            curr++;
            k -= steps;
        }
        else {
            // 在这个子树中，往下走一层
            curr *= 10;
            --k;
        }
    }

    return (int)curr;
}

int main(int argc, char** argv) {
	int n = 10, k = 3;
	auto res = findKthNumber(n, k);
	cout << res << "\n";
}