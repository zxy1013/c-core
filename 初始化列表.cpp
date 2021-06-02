#include<iostream>
using namespace std;
class Person1 {
public:
	//传统方式初始化
	/*Person1(int a, int b, int c) {
		m_A = a;
		m_B = b;
		m_C = c;
	}*/
	//初始化列表方式初始化
	Person1(int a, int b, int c):m_A(a), m_B(b), m_C(c) {
		cout << "mA:" << m_A << endl;
	}
	void PrintPerson() {
		cout << "mA:" << m_A << endl;
		cout << "mB:" << m_B << endl;
		cout << "mC:" << m_C << endl;
	}
private:
	int m_A;
	int m_B;
	int m_C;
};

int main10() {
	Person1 p(2, 3, 4);
	p.PrintPerson();

	system("pause");
	return 0;
}