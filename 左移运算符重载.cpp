#include<iostream>
using namespace std;

class Person14 {
	friend ostream& operator<<(ostream& out, Person14& p);//��Ԫ
public:
	Person14(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
private:
	int m_A;
	int m_B;
};
//ȫ�ֺ���ʵ����������
ostream& operator<<(ostream& out, Person14& p) {
	out << "a:" << p.m_A << " b:" << p.m_B;
	return out;
}
void test19() {
	Person14 p1(10, 20);
	cout << p1 << "hello world" << endl; //��ʽ��̣�cout << p1�����أ�����cout������� 
}
int main16() {
	test19();
	system("pause");
	return 0;
}