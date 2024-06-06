#include <iostream>
#include <vector>

using namespace std;

int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    int N = plants.size();
    int times = 0;
    int remainA = capacityA, remainB = capacityB;
    for (int i = 0; i < (N + 1) / 2; i++) {
        int j = N - 1 - i;
        if (i != j) {
            if (remainA >= plants[i]) {
                remainA -= plants[i];
            }
            else {
                times++;
                remainA = capacityA - plants[i];
            }
            if (remainB >= plants[j]) {
                remainB -= plants[j];
            }
            else {
                times++;
                remainB = capacityB - plants[i];
            }
        }
        else {
            int max = std::max(remainA, remainB);
            if (max < plants[i])
                times++;
        }
    }
    return times;
}

int main(){
	vector<int> plants{ 1,2,4,4,5 };
    int nums = minimumRefill(plants, 6, 5);
    cout << nums;
}