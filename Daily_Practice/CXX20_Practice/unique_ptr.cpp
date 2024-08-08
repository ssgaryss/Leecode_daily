#include <memory>
#include <iostream>
using namespace std;

class A {
public:
	A() {
		cout << "construction" << "\n";
	};
	A(int vValue)
		:A() {
		m_Value = vValue;
	}
	~A() {
		cout << "destruction" << "\n";
	}
	inline int getValue() const { return m_Value; }
private:
	int m_Value = 0;
};

int main() {
	unique_ptr<A> pA = nullptr;
	{
		A* InsA = new A();
		pA.reset(InsA);
		//delete InsA;  // 这里会发生报错，因为pA仍然持有实例，但是实例被删除，导致pA未定义报错
	}
	if (pA == nullptr)
		cout << "pA = nullptr" << "\n";
	else
		cout << "pA = " << pA->getValue() << "\n";

	//shared_ptr<A> pB(pA.get()); // 这里会发生报错，pB并没有获得对该实例的所有权，pA.reset(new A(10));语句中实例会被释放，导致pB未定义
	pA.reset(new A(10)); // 此处创建新的实例，而原有实例没有指针指向则发生析构
	shared_ptr<A> pB(move(pA)); // pB获得所有权，pA变为nullptr

	if (pA == nullptr)
		cout << "pA = nullptr" << "\n";
	else
		cout << "pA = " << pA->getValue() << "\n";
}