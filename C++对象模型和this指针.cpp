#include<iostream>
using namespace std;

class Person9 {
};
class Person8 {
public:
	Person8() {
		mA = 0;
	}
	//�Ǿ�̬��Ա����ռ����ռ�
	int mA;
	//��̬��Ա������ռ����ռ�
	static int mB;
	//����Ҳ��ռ����ռ䣬���к�������һ������ʵ��
	void func() {}
	//��̬��Ա����Ҳ��ռ����ռ�
	static void sfunc() {
	}
};

//thisָ�����
class Person10
{
public:
	Person10(int age)
	{
		//age = age;//p1.age = -858993460 ���ڱ������޷������βκͳ�Ա����
		//1�����βκͳ�Ա����ͬ��ʱ������thisָ��������
		this->age = age;
	}
	//��������
	Person10& PersonAddPerson(Person10 p)
	{
		this->age += p.age;
		//���ض��������Լ�������
		return *this;
	}
	int age;
};
void test12()
{
	Person10 p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person10 p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
	cout << "p2.age = " << p2.age << endl;
}

//��ָ����ʳ�Ա����
class Person11 {
public:
	void ShowClassName() {
		cout << "����Person��!" << endl;
	}
	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << mAge << endl; //mAgeǰĬ�������this->mAge
	}
public:
	int mAge;
};
void test13()
{
	Person11* p = NULL;
	p->ShowClassName(); //��ָ�룬���Ե��ó�Ա����
	p->ShowPerson();  //���������Ա�������õ���thisָ�룬�Ͳ������� ��������Ϊ�����ָ��Ϊ�� ����if�ж�
}

//const���γ�Ա����
class Person12 {
public:
	Person12() {
		//thisָ��ı���Ϊָ�볣����ָ�򲻿��޸ģ�ֵ�����޸� Person12* const this
		m_A = 0;
		m_B = 0;
	}
	//�������ָ��ָ���ֵҲ�������޸ģ���Ҫ���������� const Person12* const this
	void ShowPerson() const {
		//this->m_A = 100; //thisָ��ָ���������ݲ������޸�
		//m_A = 10;
		//const���γ�Ա��������ʾָ��ָ����ڴ�ռ�����ݲ����޸ģ�����mutable���εı���
		this->m_B = 100;
		m_B = 10;
	}
	void MyFunc(){
	}
public:
	int m_A;
	mutable int m_B; //ʹ���ڳ���������Ȼ�����޸�
};
//const���ζ���  ������
void test14() {
	const Person12 person; //��������  
	cout << person.m_A << endl;
	//person.m_A = 100; //���������޸ĳ�Ա������ֵ�����ǿ��Է���
	person.m_B = 100; //����������޸�mutable���γ�Ա����
	//������ֻ�ܵ��ó�����
	person.ShowPerson();//������ֻ�ܵ���const�ĺ���
	//person.MyFunc(); //�������ܵ��÷ǳ�����
}

int main13() {
	Person8 p1;
	cout << sizeof(Person8) << endl;//4
	cout << sizeof(p1) << endl;//4
	
	//�ն���ռ���ڴ�ռ�Ϊ1�ֽ�
	//C++���������ÿһ���ն������һ���ֽڵĿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ�ݶ�һ�޶����ڴ��ַ
	Person9 p;
	cout << sizeof(p) << endl;//1
	
	//thisָ�����
	test12();

	//��ָ����ʳ�Ա����
	test13();

	test14();
	system("pause");
	return 0;
}