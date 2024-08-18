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
	MyString& C = A;         // 左值
	cout << C << "\n";
	cout << "-------------------" << "\n";
	MyString&& D = move(A);  // 右值（其本质依然是左值，只不过强制要求move，并且默认A不再使用）
	cout << D << "\n";
	cout << "-------------------" << "\n";
	A.setBuffer("I am the new A"s);
	cout << A << "\n";
	cout << C << "\n";
	cout << D << "\n";       // 这里其实你还是可以改变A，因为右值是一个弱约束，正常下你应该在move后将A设置为空

	cout << "-------------------" << "\n";
	MyString E(D);           // D虽然是右值但是调用的却是Copy ctor,右值其实本质是一个左值！
	cout << "-------------------" << "\n";
	MyString F(move(D));     // 右值引用只有显示调用move时才会真正调用拷贝构造函数
	cout << "-------------------" << "\n";
	MyString G(createMyString("I am G !"));       // 由于C++返回值优化RVO这里临时值直接构造到G中而不会调用移动构造函数
	cout << "-------------------" << "\n";
	MyString H(move(createMyString("I am H !"))); // 显示调用move将禁止RVO直接构造G，从而调用移动构造函数
}