#include <iostream>
#include <list>
#include <deque>
#include <vector>

#include <queue>
#include <stack>

int main() {
    std::list<int> list1 = { 1, 2, 3, 4, 5 };
    std::list<int> list2 = { 10, 11, 12 };

    // 将 list2 中的所有元素移动到 list1 的开头
    list1.splice(list1.end(), list2);

    std::cout << "list1 : ";
    for (int n : list1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "list2 : ";
    for (int n : list2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}