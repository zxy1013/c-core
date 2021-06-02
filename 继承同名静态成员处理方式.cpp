#include<iostream>
using namespace std;

class Base4 {
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}
	static int m_A;
};
//�����ʼ��
int Base4::m_A = 100;
class Son4 : public Base4 {
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};
//�����ʼ��
int Son4::m_A = 200;

//ͬ����Ա����
void test29()
{
	//ͨ���������
	cout << "ͨ��������ʣ� " << endl;
	Son4 s;
	cout << "Son  �� m_A =  " << s.m_A << endl;
	cout << "Base �� m_A =  " << s.Base4::m_A << endl;

	//ͨ����������
	cout << "ͨ���������ʣ� " << endl;
	cout << "Son  �� m_A =  " << Son4::m_A << endl;
	cout << "Base �� m_A =  " << Son4::Base4::m_A << endl;//ͨ�������ķ�ʽ���ʸ����������µ�m_A
	cout << "Base �� m_A =  " << Base4::m_A << endl;
}

//ͬ����Ա����
void test30()
{
	//ͨ���������
	cout << "ͨ��������ʣ� " << endl;
	Son4 s;
	s.func();
	s.Base4::func();

	cout << "ͨ���������ʣ� " << endl;
	Son4::func();
	Son4::Base4::func();
	//����ͬ������������ص�����������ͬ����Ա��������Ҫ�������������
	Son4::Base4::func(100);
}
int main26() {
	test29();
	test30();
	system("pause");
	return 0;
}