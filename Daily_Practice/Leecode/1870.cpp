#include <iostream>
#include <vector>
using namespace std;

int minSpeedOnTime(vector<int>& dist, double hour) {
    int n = (int)dist.size();
    // �� hour �� 100 ��תΪ����
    long long hr = llround(hour * 100);
    // ʱ�����Ҫ����·�̶����� 1
    if (hr <= (n - 1) * 100) {
        return -1;
    }
    // ����
    int l = 1;
    int r = (int)1e7;
    while (l < r) {
        int mid = l + (r - l) / 2;
        // �жϵ�ǰʱ���Ƿ�����ʱ��
        long long t = 0;
        // ǰ n-1 ���е� i �ι��׵�ʱ�䣺 floor(dist[i] / mid)
        for (int i = 0; i < n - 1; ++i) {
            t += (dist[i] - 1) / mid + 1;
        }
        // ���һ�ι��׵�ʱ�䣺 dist[n-1] / mid
        t *= mid;
        t += dist[n - 1];
        if (t * 100 <= hr * mid) {   // ͨ����ת��Ϊ�����Ƚ�
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;   // ������������Сʱ��
}

int main() {
	vector dist{ 1,3,2 };
	double hour = 6;
	cout << minSpeedOnTime(dist, hour) << "\n";
}