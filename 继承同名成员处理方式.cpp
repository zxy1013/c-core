#include<iostream>
using namespace std;

class Base3 {
public:
	Base3()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base - func()����" << endl;
	}
	void func(int a)
	{
		cout << "Base - func(int a)����" << endl;
	}
public:
	int m_A;
};

class Son3 : public Base3 {
public:
	Son3()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son - func()����" << endl;
	}
public:
	int m_A;
};

void test28()
{
	Son3 s;
	cout << "Son�µ�m_A = " << s.m_A << endl;
	//�������ʸ����б����ص�ͬ����Ա����������Ҫ�Ӹ����������
	cout << "Base�µ�m_A = " << s.Base3::m_A << endl;
	s.func();
	s.Base3::func();
	//�������븸��ӵ��ͬ���ĳ�Ա��������������ظ��������а汾��ͬ����Ա����
	//s.func(10);//����ʹ�����������
	s.Base3::func(10);
}
int main25() {
	test28();
	system("pause");
	return EXIT_SUCCESS;
}