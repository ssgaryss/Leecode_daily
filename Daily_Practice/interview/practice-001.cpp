//题目描述
//
//在求生游戏中，安全区的毒圈扩散时间已预先确定。
//你需要从起点出发，以最短时间到达终点，且在移动过程中必须始终处于安全区域。
//
//地图规则：地图为 M 行 N 列的网格，每个格子的状态如下，
//‘S’ : 起点（唯一）
//‘E’ : 终点（唯一）
//‘t’（数字，0≤t≤1000）：表示该区域在第 t 秒后被毒圈覆盖
//（玩家在 t 秒时仍可停留，t + 1 秒不可进入）
//‘#’ : 障碍物（不可通行）
//
//玩家移动规则：
//每秒可向上下左右四个方向移动一格。
//移动后所在的格子必须满足：当前时间 ≤ 该格子的毒圈时间。
//
//输入描述
//第 1 行：两个整数 M 和 N(1≤M, N≤100)。
//第 2 ~M + 1 行：每行包含 N 个字符，表示地图布局。
//字符间以空格分隔。例如：S 5 5 表示第一行有三个格子，分别为起点、时间 5、时间 5。
//
//输出描述
//输出一个整数，表示从起点到终点的最短时间。若无法到达，输出 - 1。

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>
#include <iterator>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

int main(int argc, char** argv) {
	int M = 0, N = 0;
	cin >> M >> N;
	vector<vector<string>> Map(M, vector<string>(N));
	for (auto& Raw : Map)
		std::copy_n(istream_iterator<string>(cin), N, Raw.begin());

	pair<int, int> Start;
	pair<int, int> End;

	vector<vector<int>> MapValue(M, vector<int>(N, -1));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (Map[i][j] == "S") {
				MapValue[i][j] = INT_MAX;
				Start = { i, j };
			}
			else if (Map[i][j] == "E") {
				MapValue[i][j] = INT_MAX;
				End = { i, j };
			}
			else if (Map[i][j] == "#")
				MapValue[i][j] = -1;
			else
				MapValue[i][j] = std::stoi(Map[i][j]);
		}
	}
	cout << "Start..." << "\n";

	int res = -1;
	vector<vector<int>> MinTime(M, vector<int>(N, INT_MAX));
	MinTime[Start.first][Start.second] = 0;
	queue<pair<int, int>> Queue; // BFS
	vector<int> XOffset = { 0, 0, 1,-1 };
	vector<int> YOffset = { 1,-1, 0, 0 };
	Queue.push(Start);
	while (!Queue.empty())
	{
		auto It = Queue.front();
		Queue.pop();
		auto X = It.first;
		auto Y = It.second;
		if (X == End.first && Y == End.second) {
			res = MinTime[X][Y];
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int NextX = X + XOffset[i];
			int NextY = Y + YOffset[i];
			if (NextX < M && NextX >= 0 && NextY < N && NextY >= 0) {
				if (MinTime[X][Y] + 1 <= MapValue[NextX][NextY]) {
					if (MinTime[X][Y] + 1 < MinTime[NextX][NextY]) {
						MinTime[NextX][NextY] = MinTime[X][Y] + 1;
						Queue.push({ NextX , NextY });
					}
				}
			}
		}
	}

	for (auto& Raw : MinTime) {
		std::copy_n(Raw.begin(), N, ostream_iterator<int>(cout, " "));
		cout << "\n";
	}
	cout << "Time: " << res;
	return 0;
}

