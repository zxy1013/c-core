#include<iostream>
using namespace std;
class Person1 {
public:
	//��ͳ��ʽ��ʼ��
	/*Person1(int a, int b, int c) {
		m_A = a;
		m_B = b;
		m_C = c;
	}*/
	//��ʼ���б�ʽ��ʼ��
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