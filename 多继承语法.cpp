#include<iostream>
using namespace std;
class Base5 {
public:
	Base5()
	{
		m_A = 100;
	}
public:
	int m_A;
};

class Base6 {
public:
	Base6()
	{
		m_A = 200;  //��ʼ��m_B ��������⣬���Ǹ�ΪmA�ͻ���ֲ���ȷ
	}
public:
	int m_A;
};

//�﷨��class ���ࣺ�̳з�ʽ ����1 ���̳з�ʽ ����2 
class Son5 : public Base5, public Base6
{
public:
	Son5()
	{
		m_C = 300;
		m_D = 400;
	}
public:
	int m_C;
	int m_D;
};

//��̳����ײ�����Աͬ�������
//ͨ��ʹ������������������ֵ�����һ������ĳ�Ա
void test31()
{
	Son5 s;
	cout << "sizeof Son = " << sizeof(s) << endl;
	cout << s.Base5::m_A << endl;
	cout << s.Base6::m_A << endl;
}

int main27() {
	test31();
	system("pause");
	return 0;
}