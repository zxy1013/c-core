#include<iostream>
using namespace std;

class Person13 {
public:
	Person13() {};
	Person13(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//��Ա����ʵ�� + �����������
	//person13 p3 = p1.operator+(p2)==>���Լ�Ϊperson13 p3 = p1 + p2
	Person13 operator+(const Person13& p) {
		Person13 temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
public:
	int m_A;
	int m_B;
};
//ȫ�ֺ���ʵ�� + �����������
//person13 p3 = operator+(p1,p2)==>���Լ�Ϊperson13 p3 = p1 + p2
/*Person13 operator+(const Person13& p1, const Person13& p2) {
	Person13 temp(0, 0);
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}*/
//��������� Ҳ���Ժ������� 
Person13 operator+(const Person13& p2, int val)
{
	Person13 temp;
	temp.m_A = p2.m_A + val;
	temp.m_B = p2.m_B + val;
	return temp;
}
void test18() {
	Person13 p1(10, 10);
	Person13 p2(20, 20);
	//��Ա������ʽ
	Person13 p3 = p2 + p1;  //�൱�� p2.operaor+(p1)
	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;
	Person13 p4 = p3 + 10; //�൱�� operator+(p3,10)
	cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
}
int main15() {
	test18();

	system("pause");
	return 0;
}