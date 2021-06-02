#include<iostream>
using namespace std;

class Person4 {
public:
	Person4() {
		cout << "�޲ι��캯��!" << endl;
		mAge = 0;
	}
	Person4(int age) {
		cout << "�вι��캯��!" << endl;
		mAge = age;
	}
	Person4(const Person4& p) {
		cout << "�������캯��!" << endl;
		mAge = p.mAge;
	}
	//�����������ͷ��ڴ�֮ǰ����
	~Person4() {
		cout << "��������!" << endl;
	}
public:
	int mAge;
};

//1. ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test03() {
	Person4 man(20); //man�����Ѿ��������
	Person4 newman(man); //���ÿ������캯��
	Person4 newman2 = man; //��������
}

//2. ֵ���ݵķ�ʽ������������ֵ
//�൱��Person p1 = p;
void doWork(Person4 p1) {}
void test04() {
	Person4 p; //�޲ι��캯��
	doWork(p);//�������캯��! Person4 p1 = p
}

//3. ��ֵ��ʽ���ؾֲ�����
Person4 doWork2()
{
	Person4 p1;
	cout << (int*)&p1 << endl; //�����ַ 001EF740
	return p1; //�������캯��!
}
void test05()
{
	Person4 p = doWork2();
	cout << (int*)&p << endl; //�����ַ 001EF838 
}

//���캯�����ù���
void test06()
{
	Person4 p1(18);
	//�����д��������Person4(const Person4& p)���� ���������Զ���ӿ������죬������ǳ��������
	Person4 p2(p1);
	cout << "p2������Ϊ�� " << p2.mAge << endl;
}

void test07()
{
	//����û��ṩ�вι��죬�����������ṩĬ�Ϲ��죬���ṩ��������
	Person4 p1; //��ʱ����û��Լ�û���ṩĬ�Ϲ��죬�����������Ĭ�Ϲ��캯��
	Person4 p2(10); //�û��ṩ���в�
	Person4 p3(p2); //��ʱ����û�û���ṩ�������죬���������ṩ

	//����û��ṩ�������죬�����������ṩ�������캯��
	Person4 p4; //��ʱ����û��Լ�û���ṩĬ�Ϲ��죬�����
	Person4 p5(10); //��ʱ����û��Լ�û���ṩ�вι��죬�����
	Person4 p6(p5); //�û��Լ��ṩ��������
}
int main8() {
	test03();
	test04();
	test05();
	test06();
	test07();

	system("pause");
	return 0;
}