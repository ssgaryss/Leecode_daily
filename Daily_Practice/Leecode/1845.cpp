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
	SeatManager seatManager = SeatManager(5); // 初始化 SeatManager ，有 5 个座位。
	std::cout << seatManager.reserve() << "\n"; // 所有座位都可以预约，所以返回最小编号的座位，也就是 1 。
	std::cout << seatManager.reserve() << "\n"; // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
	seatManager.unreserve(2); // 将座位 2 变为可以预约，现在可预约的座位为 [2,3,4,5] 。
	std::cout << seatManager.reserve() << "\n"; // 可以预约的座位为 [2,3,4,5] ，返回最小编号的座位，也就是 2 。
	std::cout << seatManager.reserve() << "\n"; // 可以预约的座位为 [3,4,5] ，返回最小编号的座位，也就是 3 。
	std::cout << seatManager.reserve() << "\n"; // 可以预约的座位为 [4,5] ，返回最小编号的座位，也就是 4 。
	std::cout << seatManager.reserve() << "\n"; // 唯一可以预约的是座位 5 ，所以返回 5 。
	seatManager.unreserve(5); // 将座位 5 变为可以预约，现在可预约的座位为 [5] 。
}