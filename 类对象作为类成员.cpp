#include<iostream>
using namespace std;
class Phone
{
public:
	Phone(string name)
	{
		m_PhoneName = name;
		cout << "Phone����" << endl;
	}
	~Phone()
	{
		cout << "Phone����" << endl;
	}
	string m_PhoneName;
};

class Person6
{
public:
	//��ʼ���б���Ը��߱�����������һ�����캯��
	Person6(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person����" << endl;
	}
	~Person6()
	{
		cout << "Person����" << endl;
	}
	void playGame()
	{
		cout << m_Name << " ʹ��" << m_Phone.m_PhoneName << " ���ֻ�! " << endl;
	}
	string m_Name;
	//�����г�Ա�����������ʱ�����ǳƸó�ԱΪ�����Ա
	Phone m_Phone;
};
void test09()
{
	//�����˳���� ���ȵ��ö����Ա�Ĺ��죬�ٵ��ñ��๹��
	//����˳���빹���෴ Person����-->Phone����
	Person6 p("����", "ƻ��X");//Phone����-->Person����
	p.playGame();
}

int main11() {
	test09();
	system("pause");
	return 0;
}