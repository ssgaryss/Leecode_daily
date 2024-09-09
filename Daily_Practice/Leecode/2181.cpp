#include <iostream>
#include <vector>
#include <functional>
#include <utility>
using namespace std;

auto _{ []() noexcept {
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	return 0;
}() };

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeNodes(ListNode* head) {
	ListNode* dummy = new ListNode(); // 维护一个dummy方便保存头节点
	ListNode* tail = dummy;

	int sum = 0;
	head = head->next;
	while (head)
	{
		if (head->val == 0)
		{
			ListNode* Node = new ListNode(sum);
			tail->next = Node;
			tail = tail->next;
			sum = 0;
		}
		else {
			sum += head->val;
		}
		head = head->next;
	}
	return dummy->next;
}

void getResult(vector<int>& res, ListNode* head) {
	res.emplace_back(head->val);
	if (head->next)
		getResult(res, head->next);
	else
		return;
}

int main() {
	ListNode node7(0);
	ListNode node6(2, &node7);
	ListNode node5(5, &node6);
	ListNode node4(4, &node5);
	ListNode node3(0, &node4);
	ListNode node2(1, &node3);
	ListNode node1(3, &node2);
	ListNode node0(0, &node1);
	ListNode mergeNode = *mergeNodes(&node0);
	vector<int> res;
	getResult(res, &mergeNode);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
}