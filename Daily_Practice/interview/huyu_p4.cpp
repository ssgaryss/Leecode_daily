#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;

struct Danzai {
	Danzai() = default;

	int HP;
	int ATK;
	int DIST;
	int x, y;
	bool IsOut = false;
};

struct Attack
{
	Attack() = default;
	int IndexOurs = -1, IndexEnemy = -1;
	bool IsOurAttack = true;
};

struct Move
{
	Move() = default;
	int Index = -1;
	int XOffset = 0, YOffset = 0;
	bool IsOurMove = true;
};

int getManhatonDist(const Danzai& A, const Danzai& B) {
	return abs(A.x - B.x) + abs(A.y - B.y);
}

int main() {
	int T;
	cin >> T;
	for (int l = 0; l < T; ++l) {
		int N, M, p, q;
		cin >> N >> M >> p >> q;
		vector<Danzai> OurDanzais(p);
		vector<Danzai> EnemyDanzais(q);
		for (int i = 0; i < p; ++i) {
			cin >> OurDanzais[i].HP >> OurDanzais[i].ATK >> OurDanzais[i].DIST
				>> OurDanzais[i].x >> OurDanzais[i].y;
		}
		for (int i = 0; i < q; ++i) {
			cin >> EnemyDanzais[i].HP >> EnemyDanzais[i].ATK >> EnemyDanzais[i].DIST
				>> EnemyDanzais[i].x >> EnemyDanzais[i].y;
		}

		// 算法开始
		// 每个回合的事件都通过一个Quene处理并更新各个蛋仔实时状态
		// 先处理所有攻击事件，再处理移动事件更新状态
		// 暂时用粗暴方式遍历
		queue<Attack> AttackEventPool;
		queue<Move> MoveEventPool;
		for (int i = 0; i < p; ++i) {
			int MinDistance = INT_MAX;
			Attack AttackEvent;
			AttackEvent.IndexOurs = i;
			AttackEvent.IsOurAttack = true;
			for (int j = 0; j < q; ++j) {
				int distance = getManhatonDist(OurDanzais[i], EnemyDanzais[j]);
				if (!EnemyDanzais[j].IsOut && OurDanzais[i].DIST >= distance) {
					if (MinDistance > distance) {
						AttackEvent.IndexEnemy = j;
					}
				}
				MinDistance = min(MinDistance, distance);
			}
		}
	}
}