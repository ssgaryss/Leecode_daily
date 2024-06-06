#include <iostream>
#include <format>
#include <vector>

void quickSort(std::vector<int>& nums, int left, int right);

int main(int argc, char* argv[]) {
	std::vector<int> chaos{ 8,5,9,11,65,1,2,6,3,7,8,9,6,7,5,54 };
	for (auto i : chaos) {
		std::cout << i << " ";
	}
	std::cout << "\n" << "quick sort£º";
	quickSort(chaos, 0, chaos.size() - 1);
	for (auto i : chaos) {
		std::cout << i << " ";
	}
	return 0;
}

void quickSort(std::vector<int>& nums, int left, int right) {
	if (left >= right) {
		return;
	}

	int pivot = nums[left];
	int i = left;
	int j = right;

	while (i < j) {
		while (i < j && nums[j] >= pivot)
		{
			j--;
		}
		nums[i] = nums[j];
		while (i < j && nums[i] <= pivot) {
			i++;
		}
		nums[j] = nums[i];
	}
	nums[i] = pivot;

	quickSort(nums, left, j - 1);
	quickSort(nums, j + 1, right);
}