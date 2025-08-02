//��Ŀ����
//
//��������Ϸ�У���ȫ���Ķ�Ȧ��ɢʱ����Ԥ��ȷ����
//����Ҫ���������������ʱ�䵽���յ㣬�����ƶ������б���ʼ�մ��ڰ�ȫ����
//
//��ͼ���򣺵�ͼΪ M �� N �е�����ÿ�����ӵ�״̬���£�
//��S�� : ��㣨Ψһ��
//��E�� : �յ㣨Ψһ��
//��t�������֣�0��t��1000������ʾ�������ڵ� t ��󱻶�Ȧ����
//������� t ��ʱ�Կ�ͣ����t + 1 �벻�ɽ��룩
//��#�� : �ϰ������ͨ�У�
//
//����ƶ�����
//ÿ��������������ĸ������ƶ�һ��
//�ƶ������ڵĸ��ӱ������㣺��ǰʱ�� �� �ø��ӵĶ�Ȧʱ�䡣
//
//��������
//�� 1 �У��������� M �� N(1��M, N��100)��
//�� 2 ~M + 1 �У�ÿ�а��� N ���ַ�����ʾ��ͼ���֡�
//�ַ����Կո�ָ������磺S 5 5 ��ʾ��һ�����������ӣ��ֱ�Ϊ��㡢ʱ�� 5��ʱ�� 5��
//
//�������
//���һ����������ʾ����㵽�յ�����ʱ�䡣���޷������� - 1��

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

