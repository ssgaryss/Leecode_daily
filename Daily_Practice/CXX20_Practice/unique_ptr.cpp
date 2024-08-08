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
		//delete InsA;  // ����ᷢ��������ΪpA��Ȼ����ʵ��������ʵ����ɾ��������pAδ���屨��
	}
	if (pA == nullptr)
		cout << "pA = nullptr" << "\n";
	else
		cout << "pA = " << pA->getValue() << "\n";

	//shared_ptr<A> pB(pA.get()); // ����ᷢ������pB��û�л�öԸ�ʵ��������Ȩ��pA.reset(new A(10));�����ʵ���ᱻ�ͷţ�����pBδ����
	pA.reset(new A(10)); // �˴������µ�ʵ������ԭ��ʵ��û��ָ��ָ����������
	shared_ptr<A> pB(move(pA)); // pB�������Ȩ��pA��Ϊnullptr

	if (pA == nullptr)
		cout << "pA = nullptr" << "\n";
	else
		cout << "pA = " << pA->getValue() << "\n";
}