#include <iostream>
#include <vector>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	return 0;
}() };

// 线段树
class SegmentTree {
public:
	SegmentTree(const vector<int>& vData) {
		n = (int)vData.size();
		m_Tree.resize(4 * n); // 由于vData并不一定是一个完全二叉树因此2 * 2 * n确保空间够用
		build(vData, 0, 0, n - 1);
	}

	// 将完全二叉树的构造到一个数组中
	void build(const std::vector<int>& data, int node, int start, int end) {
		if (start == end) {
			m_Tree[node] = data[start];
		}
		else {
			int mid = (start + end) / 2;
			int leftChild = 2 * node + 1;
			int rightChild = 2 * node + 2; // 计算数组中对应index

			build(data, leftChild, start, mid);
			build(data, rightChild, mid + 1, end);
			m_Tree[node] = m_Tree[leftChild] + m_Tree[rightChild];
		}
	}
	// 跟新从叶子节点到根节点所有节点的值
	void update(int node, int start, int end, int idx, int value) {
		if (start == end) {
			m_Tree[node] = value;
		}
		else {
			int mid = (start + end) / 2;
			int leftChild = 2 * node + 1;
			int rightChild = 2 * node + 2;

			if (idx <= mid) {
				update(leftChild, start, mid, idx, value);
			}
			else {
				update(rightChild, mid + 1, end, idx, value);
			}
			m_Tree[node] = m_Tree[leftChild] + m_Tree[rightChild];
		}
	}
	// 求区间和
	int query(int node, int start, int end, int L, int R) {
		if (R < start || end < L) {
			return 0; // 表示无效区间
		}
		if (L <= start && end <= R) {
			return m_Tree[node];
		}
		int mid = (start + end) / 2;
		int leftChild = 2 * node + 1;
		int rightChild = 2 * node + 2;

		int leftSum = query(leftChild, start, mid, L, R);
		int rightSum = query(rightChild, mid + 1, end, L, R);
		return leftSum + rightSum;
	}
	// 查找第一个比target大的下标
	int query(int node, int start, int end, int L, int R, int target) {
		if (R < start || end < L) {
			return -1; // 表示无效区间
		}
		if (start == end) {
			return (m_Tree[node] > target) ? start : -1;
		}

		int mid = (start + end) / 2;
		int leftChild = 2 * node + 1;
		int rightChild = 2 * node + 2;

		int leftResult = query(leftChild, start, mid, L, R, target);
		if (leftResult != -1) {
			return leftResult;
		}
		return query(rightChild, mid + 1, end, L, R, target);
	}
private:
	vector<int> m_Tree;
	int n;
};

vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
	int n = (int)heights.size();
	SegmentTree SegmentTree(heights);

	int m = (int)queries.size();
	vector<int> ans(m);
	for (int i = 0; i < m; ++i) {
		int a = queries[i][0];
		int b = queries[i][1];
		if (a > b)
			swap(a, b); // 简化操作，因为a b顺序不影响结果，假定b > a
		if (a == b || heights[a] < heights[b]) {
			ans[i] = b;
			continue;
		}
		// heights[a] > heights[b]
		ans[i] = SegmentTree.query(0, 0, n - 1, b + 1, n - 1, heights[a]);
	}
	return ans;
}

int main() {
	vector<int> heights{ 6,4,8,5,2,7 };
	vector<vector<int>> queries{
		{0,1},{0,3},{2,4},{3,4},{2,2}
	};
	auto res = leftmostBuildingQueries(heights, queries);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
}