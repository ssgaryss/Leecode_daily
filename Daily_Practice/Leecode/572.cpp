#include <iostream>
#include <iomanip>
#include <functional>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
	}() };

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	function<bool(TreeNode*, TreeNode*)> check = [&check](TreeNode* o, TreeNode* t) {
		if (!o && !t)
			return true; // 两个都是空节点
		if ((!o && t) || (o && !t) || (o->val != t->val))
			return false; // 只有一个为空或二者非空值不相等显然不成立
		return check(o->left, t->left) && check(o->right, t->right); // 继续比较所有子节点
		};
	function<bool(TreeNode*, TreeNode*)> dfs = [&dfs, &check](TreeNode* o, TreeNode* t) {  // 深度
		if (!o)
			return false;
		return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
		};
	return dfs(root, subRoot);
}

int main() {
	// 这个实例太难写了，以下是示例2的情况
	TreeNode* Leaf3{ new TreeNode(0) };
	TreeNode* Leaf4{ new TreeNode(2, Leaf3, nullptr) };
	TreeNode* Leaf5{ new TreeNode(1) };
	TreeNode* Leaf6{ new TreeNode(4, Leaf5, Leaf4) };
	TreeNode* Leaf7{ new TreeNode(5) };
	TreeNode* Root{ new TreeNode(4, Leaf6, Leaf7) };

	TreeNode* Leaf1{ new TreeNode(1) }; 
	TreeNode* Leaf2{ new TreeNode(2) };
	TreeNode* SubRoot{ new TreeNode(4, Leaf1, Leaf2) };

	bool res = isSubtree(Root, SubRoot);
	cout << boolalpha << res << "\n";

	delete Leaf3;
	delete Leaf4;
	delete Leaf5;
	delete Leaf6;
	delete Leaf7;
	delete Root;
	delete Leaf1;
	delete Leaf2;
	delete SubRoot;
}