#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyString
{
public:
	MyString() = default;
	MyString(const string& vString)
		: m_Buffer{ vString }, m_Length{ vString.length() } { 
		cout << "ctor !" << "\n";
	}
	MyString(const MyString& vOther) {
		cout << "Copy ctor !" << "\n";
		m_Buffer = vOther.m_Buffer;
		m_Length = vOther.m_Length;
	}
	MyString& operator=(const MyString& vOther) {
		if (this == &vOther)
			return *this;
		cout << "Copy = !" << "\n";
		m_Buffer = vOther.m_Buffer;
		m_Length = vOther.m_Length;
		return *this;
	}
	MyString(MyString&& vOther) noexcept {
		cout << "Move ctor !" << "\n";
		m_Buffer = vOther.m_Buffer;
		m_Length = vOther.m_Length;
		vOther.m_Buffer = ""s;
		vOther.m_Length = 0;
	}
	MyString& operator=(MyString&& vOther) noexcept { 
		if (this == &vOther)
			return *this;
		cout << "Move = !" << "\n"; 
		m_Buffer = vOther.m_Buffer;
		m_Length = vOther.m_Length;
		vOther.m_Buffer = ""s;
		vOther.m_Length = 0;
		return *this;
	}
	inline void setBuffer(const string& vString) { m_Buffer = vString; }
private:
	string m_Buffer = "";
	size_t m_Length = 0;

	friend ostream& operator<<(ostream& vOStream, const MyString& vMyString);
};

ostream& operator<<(ostream& vOStream, const MyString& vMyString) {
	return vOStream << vMyString.m_Buffer;
}

MyString createMyString(const string& vString) {
	return MyString(vString);
}

int main() {
	string s{ "Hello!" };
	cout << "-------------------" << "\n";
	MyString A{ "I am A"s };
	MyString B{ "I am B"s };
	cout << A << "\n";
	cout << B << "\n";
	cout << "-------------------" << "\n";
	MyString& C = A;         // ��ֵ
	cout << C << "\n";
	cout << "-------------------" << "\n";
	MyString&& D = move(A);  // ��ֵ���䱾����Ȼ����ֵ��ֻ����ǿ��Ҫ��move������Ĭ��A����ʹ�ã�
	cout << D << "\n";
	cout << "-------------------" << "\n";
	A.setBuffer("I am the new A"s);
	cout << A << "\n";
	cout << C << "\n";
	cout << D << "\n";       // ������ʵ�㻹�ǿ��Ըı�A����Ϊ��ֵ��һ����Լ������������Ӧ����move��A����Ϊ��

	cout << "-------------------" << "\n";
	MyString E(D);           // D��Ȼ����ֵ���ǵ��õ�ȴ��Copy ctor,��ֵ��ʵ������һ����ֵ��
	cout << "-------------------" << "\n";
	MyString F(move(D));     // ��ֵ����ֻ����ʾ����moveʱ�Ż��������ÿ������캯��
	cout << "-------------------" << "\n";
	MyString G(createMyString("I am G !"));       // ����C++����ֵ�Ż�RVO������ʱֱֵ�ӹ��쵽G�ж���������ƶ����캯��
	cout << "-------------------" << "\n";
	MyString H(move(createMyString("I am H !"))); // ��ʾ����move����ֹRVOֱ�ӹ���G���Ӷ������ƶ����캯��
}