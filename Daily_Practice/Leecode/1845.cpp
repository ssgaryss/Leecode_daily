#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

class SeatManager {
public:
	SeatManager(int n)
		: m_Seats{ std::vector<int>(n) } {}

	int reserve() {
		for (int i = m_Index; i < (int)m_Seats.size(); ++i) {
			if (m_Seats[i] == 0) {
				m_Seats[i] = 1;
				m_Index = i;
				return i + 1;
			}
		}
		return -1;
	}

	void unreserve(int seatNumber) {
		m_Seats[seatNumber - 1] = 0;
		m_Index = min(m_Index, seatNumber - 1);
	}
private:
	int m_Index = 0;
	std::vector<int> m_Seats;
};

int main() {
	SeatManager seatManager = SeatManager(5); // ��ʼ�� SeatManager ���� 5 ����λ��
	std::cout << seatManager.reserve() << "\n"; // ������λ������ԤԼ�����Է�����С��ŵ���λ��Ҳ���� 1 ��
	std::cout << seatManager.reserve() << "\n"; // ����ԤԼ����λΪ [2,3,4,5] ��������С��ŵ���λ��Ҳ���� 2 ��
	seatManager.unreserve(2); // ����λ 2 ��Ϊ����ԤԼ�����ڿ�ԤԼ����λΪ [2,3,4,5] ��
	std::cout << seatManager.reserve() << "\n"; // ����ԤԼ����λΪ [2,3,4,5] ��������С��ŵ���λ��Ҳ���� 2 ��
	std::cout << seatManager.reserve() << "\n"; // ����ԤԼ����λΪ [3,4,5] ��������С��ŵ���λ��Ҳ���� 3 ��
	std::cout << seatManager.reserve() << "\n"; // ����ԤԼ����λΪ [4,5] ��������С��ŵ���λ��Ҳ���� 4 ��
	std::cout << seatManager.reserve() << "\n"; // Ψһ����ԤԼ������λ 5 �����Է��� 5 ��
	seatManager.unreserve(5); // ����λ 5 ��Ϊ����ԤԼ�����ڿ�ԤԼ����λΪ [5] ��
}