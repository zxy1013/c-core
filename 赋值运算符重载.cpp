#include<iostream>
using namespace std;
class Person15
{
public:
	Person15(int age)
	{
		//���������ݿ��ٵ�����
		m_Age = new int(age);
	}
	//���ظ�ֵ����� 
	Person15& operator=(Person15& p)
	{
		if (m_Age != NULL)//���ж��Ƿ��������ڶ�������������ͷ�
		{
			delete m_Age;
			m_Age = NULL;
		}
		//�������ṩ�Ĵ�����ǳ���� m_Age = p.m_Age;�����ָ���ظ��ͷŵ�����
		//�ṩ��� ���ǳ����������
		m_Age = new int(*p.m_Age);
		//��������
		return *this;
	}
	~Person15()//�����������ͷ�
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	//�����ָ��
	int* m_Age;
};

void test21()
{
	Person15 p1(18);
	Person15 p2(20);
	Person15 p3(30);
	p3 = p2 = p1; //��ֵ����
	cout << "p1������Ϊ��" << *p1.m_Age << endl;//18
	cout << "p2������Ϊ��" << *p2.m_Age << endl;//18
	cout << "p3������Ϊ��" << *p3.m_Age << endl;//18
}

int main18() {
	int a = 10;
	int b = 20;
	int c = 30;
	c = b = a;
	cout << "a = " << a << endl;//10
	cout << "b = " << b << endl;//10
	cout << "c = " << c << endl;//10
	test21();
	system("pause");
	return 0;
}