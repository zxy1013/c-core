#include<iostream>
using namespace std;

class Person7{
public:
	static int m_A; //��̬��Ա����
	//��̬��Ա�����ص㣺
	//1 �ڱ���׶η����ڴ�
	//2 ���������������ʼ��
	//3 ���ж�����ͬһ������
private:
	static int m_B; //��̬��Ա����Ҳ���з���Ȩ�޵�
};
//�����ʼ��
int Person7::m_A = 10;//person�������µľ�̬����
int Person7::m_B = 10;

void test10()
{
	//��̬��Ա�������ַ��ʷ�ʽ
	//1��ͨ������
	Person7 p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;
	Person7 p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //����ͬһ������
	cout << "p2.m_A = " << p2.m_A << endl;
	//cout << "m_B = " << p1.m_B << endl;//˽��Ȩ�޷��ʲ���

	//2��ͨ������
	cout << "m_A = " << Person7::m_A << endl;
	//cout << "m_B = " << Person7::m_B << endl; //˽��Ȩ�޷��ʲ���
}

//��̬��Ա����
class Person8
{
public:
	//��̬��Ա�����ص㣺
	//1 ������һ������
	//2 ��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	static void func()
	{
		cout << "func����" << endl;
		m_A = 100;//��̬��Ա�������Է��ʾ�̬��Ա����
		//m_B = 100; //���󣬲����Է��ʷǾ�̬��Ա����
	}
	static int m_A; //��̬��Ա����
	int m_B; //�Ǿ�̬��Ա���� 
private:
	//��̬��Ա����Ҳ���з���Ȩ�޵�
	static void func2()
	{
		cout << "func2����" << endl;
	}
};
int Person8::m_A = 10;//�����ʼ��
void test11()
{
	//��̬��Ա�������ַ��ʷ�ʽ
	//1��ͨ������
	Person8 p1;
	p1.func();
	//2��ͨ������
	Person8::func();
	//Person8::func2(); //˽��Ȩ�޷��ʲ���
}
int main12() {
	test10();
	test11();
	system("pause");
	return 0;
}