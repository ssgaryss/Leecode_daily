// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/2361725/235-er-cha-sou-suo-shu-de-zui-jin-gong-g-qqck/



 //Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root != nullptr) {
			if (root->val < p->val && root->val < q->val) // p,q 都在 root 的右子树中
				root = root->right; // 遍历至右子节点
			else if (root->val > p->val && root->val > q->val) // p,q 都在 root 的左子树中
				root = root->left; // 遍历至左子节点
			else break;
		}
		return root;
	}
};

int main() {
	// ...
	return 0;
}
