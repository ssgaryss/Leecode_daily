#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = (int)gas.size();
    int i = 0;
    while (i < n) {
        int sumOfGas = 0, sumOfCost = 0;
        int cnt = 0;
        while (cnt < n) {
            int j = (i + cnt) % n;
            sumOfGas += gas[j];
            sumOfCost += cost[j];
            if (sumOfCost > sumOfGas) {
                break;
            }
            cnt++;
        }
        if (cnt == n) {
            return i;
        }
        else {
            i = i + cnt + 1;
        }
    }
    return -1;
}

int main() {
	vector gas{ 1,2,3,4,5 };
	vector cost{ 3,4,5,1,2 };
	cout << canCompleteCircuit(gas, cost) << "\n";
}