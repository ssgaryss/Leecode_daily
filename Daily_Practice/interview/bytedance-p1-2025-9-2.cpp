#include <iostream>
#include <algorithm>

// 设计一个vector模板，实现push_back() erase() operator[]
template <typename T>
class Vector {
private:
	T* data;         // 存储数据的指针
	size_t size;     // 当前元素数量
	size_t capacity; // 当前容量

	// 扩容逻辑
	void reserve(size_t new_capacity) {
		if (new_capacity <= capacity) return;

		T* new_data = new T[new_capacity];
		std::copy(data, data + size, new_data);
		delete[] data;
		data = new_data;
		capacity = new_capacity;
	}

public:
	// 构造函数
	Vector() : data(nullptr), size(0), capacity(0) {}

	// 析构函数
	~Vector() {
		delete[] data;
	}

	// 添加元素到末尾
	void push_back(const T& value) {
		if (size >= capacity) {
			reserve(capacity == 0 ? 1 : capacity * 2);
		}
		data[size++] = value;
	}

	// 删除指定位置的元素
	void erase(size_t pos) {
		if (pos >= size) return;

		for (size_t i = pos; i < size - 1; ++i) {
			data[i] = data[i + 1];
		}
		--size;
	}

	// 下标访问（非const版本）
	T& operator[](size_t index) {
		return data[index];
	}

	// 下标访问（const版本）
	const T& operator[](size_t index) const {
		return data[index];
	}

	// 获取当前元素数量
	size_t get_size() const { return size; }

	// 获取当前容量
	size_t get_capacity() const { return capacity; }
};

// 测试代码
int main() {
	Vector<int> vec;

	// 测试 push_back
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	// 测试 operator[]
	std::cout << "Elements: ";
	for (size_t i = 0; i < vec.get_size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";

	// 测试 erase
	vec.erase(1);
	std::cout << "After erase: ";
	for (size_t i = 0; i < vec.get_size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";

	return 0;
}
