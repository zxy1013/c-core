#include<iostream>
using namespace std;

//ȫ�ֺ�������Ԫ
class Building
{
	//���߱�����goodGayȫ�ֺ�����Building��ĺ����ѣ����Է������е�˽������
	friend void goodGay(Building* building);
public:
	Building()//���캯��
	{
		this->m_SittingRoom = "����";
		this->m_BedRoom = "����";
	}
public:
	string m_SittingRoom; //����
private:
	string m_BedRoom; //����
};
//ȫ�ֺ���
void goodGay(Building* building)
{
	cout << "�û������ڷ��ʣ� " << building->m_SittingRoom << endl;
	cout << "�û������ڷ��ʣ� " << building->m_BedRoom << endl;
}
void test15()
{
	Building b;
	goodGay(&b);
}

//������Ԫ
class Building1;//����building�����д�����
class goodGay1
{
public:
	goodGay1();
	void visit();//�ιۺ�������building1�е�����
private:
	Building1* building;
};
class Building1
{
	//���߱�����goodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������
	friend class goodGay1;
public:
	Building1();//����
public:
	string m_SittingRoom1; //����
private:
	string m_BedRoom1;//����
};
Building1::Building1()//ʵ��
{
	this->m_SittingRoom1 = "����";
	this->m_BedRoom1 = "����";
}
goodGay1::goodGay1()
{
	building = new Building1;
}
void goodGay1::visit()
{
	cout << "�û������ڷ���" << building->m_SittingRoom1 << endl;
	cout << "�û������ڷ���" << building->m_BedRoom1 << endl;
}
void test16()
{
	goodGay1 gg;
	gg.visit();

}

//��Ա��������Ԫ
class Building2;
class goodGay2
{
public:
	goodGay2();
	void visit(); //ֻ��visit������ΪBuilding�ĺ����ѣ����Է���Building��˽������
	void visit2();
private:
	Building2* building1;
};
class Building2
{
	//���߱�����goodGay���е�visit��Ա������Building�����ѣ����Է���˽������
	friend void goodGay2::visit();
public:
	Building2();
public:
	string m_SittingRoom2; //����
private:
	string m_BedRoom2;//����
};
Building2::Building2()
{
	this->m_SittingRoom2 = "����";
	this->m_BedRoom2 = "����";
}
goodGay2::goodGay2()
{
	building1 = new Building2;
}
void goodGay2::visit()
{
	cout << "�û���1���ڷ���" << building1->m_SittingRoom2 << endl;
	cout << "�û���1���ڷ���" << building1->m_BedRoom2 << endl;
}
void goodGay2::visit2()
{
	cout << "�û���2���ڷ���" << building1->m_SittingRoom2 << endl;
	//cout << "�û���2���ڷ���" << building1->m_BedRoom2 << endl;//
}
void test17()
{
	goodGay2  gg;
	gg.visit();
	gg.visit2();
}

int main14() {
	test15();
	test16();
	test17();
	system("pause");
	return 0;
}