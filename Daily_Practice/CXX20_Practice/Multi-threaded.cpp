#include <iostream>
#include <thread>
#include <format>

void counter(int id, int numIterations) {
	for (int i = 0; i < numIterations; ++i) {
		std::cout << std::format("Counter {0} has value {1}", id, i) << "\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	const int num_threads = 3;
	std::thread threads_1[num_threads];
	for (int i = 0; i < num_threads; ++i) {
		threads_1[i] = std::thread(counter, i, 5);
	}
	std::cout << std::format("Main thread continues while other threads_1 are running...") << std::endl;

	for (int i = 0; i < num_threads; ++i) {
		threads_1[i].join(); // 主线程调用join()等待所有threads线程执行完成，在所有threads执行完之前主线程被阻塞！
		std::cout << "Thread " << i << " joined." << std::endl;
	}

	std::cout << "All threads_1 have finished execution." << std::endl;

	std::thread threads_2[num_threads];
	for (int i = 0; i < num_threads; ++i) {
		threads_2[i] = std::thread(counter, i + 3, 5);
	}
	std::cout << std::format("Main thread continues while other threads_2 are running...") << std::endl;
	for (int i = 0; i < num_threads; ++i) {
		threads_2[i].detach(); // 主线程调用join()等待所有threads线程执行完成，在所有threads执行完之前主线程被阻塞！
		std::cout << "Thread " << i << " joined." << std::endl;
	}

	std::this_thread::sleep_for(std::chrono::seconds(5)); // 等待一段时间观察线程执行情况,若不等待会报错
	//如果主线程在分离后立即尝试使用已分离的线程对象，会导致未定义行为或错误。

	std::cout << "All threads_2 have finished execution." << std::endl;
}