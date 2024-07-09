#include <iostream>
#include <thread>
#include <format>
#include <mutex>
#include <syncstream> //��ʽ2 ͬ����

static std::mutex s_Mutex; //ͬ�����

void counter(int id, int numIterations) {
	for (int i = 0; i < numIterations; ++i) {
		//std::lock_guard Lock{ s_Mutex };
		//std::cout << std::format("Counter {0} has value {1}", id, i) << "\n";
		std::osyncstream{ std::cout } << std::format("Counter {0} has value {1}", id, i) << "\n"; //ͬ����ʵ�����ͬ��
	}
	std::this_thread::sleep_for(std::chrono::seconds(5));
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
		threads_1[i].join(); // ���̵߳���join()�ȴ�����threads�߳�ִ����ɣ�������threadsִ����֮ǰ���̱߳�������
		std::lock_guard Lock{ s_Mutex };
		std::cout << "Thread " << i << " joined." << std::endl;
	}

	std::cout << "All threads_1 have finished execution." << std::endl;

	std::thread threads_2[num_threads];
	for (int i = 0; i < num_threads; ++i) {
		threads_2[i] = std::thread(counter, i + 3, 5);
	}
	std::cout << std::format("Main thread continues while other threads_2 are running...") << std::endl;
	for (int i = 0; i < num_threads; ++i) {
		threads_2[i].detach(); // ���̵߳���join()�ȴ�����threads�߳�ִ����ɣ�������threadsִ����֮ǰ���̱߳�������
		std::lock_guard Lock{ s_Mutex };
		std::cout << "Thread " << i + 3 << " detached." << std::endl;
	}

	std::cout << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(5)); // �ȴ�һ��ʱ��۲��߳�ִ�����,�����ȴ��ᱨ��
	//������߳��ڷ������������ʹ���ѷ�����̶߳��󣬻ᵼ��δ������Ϊ�����

	std::cout << "All threads_2 have finished execution." << std::endl;
}