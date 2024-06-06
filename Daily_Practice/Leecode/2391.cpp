#include <iostream>
#include <vector>
#include <string>

using namespace std;

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int minTime = 0;
    int travelM = 0, travelP = 0, travelG = 0; //M、P、G的travel时间
    int travelToI = 0;//从0到i的travel时间
    for (int i = 0; i < garbage.size(); i++) {
        int countM = std::count(garbage[i].begin(), garbage[i].end(), 'M');
        int countP = std::count(garbage[i].begin(), garbage[i].end(), 'P');
        int countG = std::count(garbage[i].begin(), garbage[i].end(), 'G');
        if (i > 0) {
            travelToI += travel[i - 1];
        }
        if (countM > 0) {
            travelM = travelToI;
            minTime += countM;
        }
        if (countP > 0) {
            travelP = travelToI;
            minTime += countP;
        }
        if (countG > 0) {
            travelG = travelToI;
            minTime += countG;
        }
    }
    minTime += travelM + travelP + travelG;
    return minTime;
}

int main() {
    vector<string> garbage{ "G","P","GP","GG" };
    vector<int> travel{ 2,4,3 };
    int minTime = garbageCollection(garbage, travel);
    cout << minTime;
    return 0;
}