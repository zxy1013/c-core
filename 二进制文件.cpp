#include <fstream>
#include <string>
#include<iostream>
using namespace std;

class Personf
{
public:
	char m_Name[64];
	int m_Age;
};

//�������ļ�  д�ļ�
void test42(){
	//2���������������{
	//ofstream ofs;
	//3�����ļ�
	//ofs.open("person.txt", ios::out | ios::binary);
	//��
	ofstream ofs("person.txt", ios::out | ios::binary);
	Personf p = { "����"  , 18 };
	//4��д�ļ�
	ofs.write((const char*)&p, sizeof(p));
	//5���ر��ļ�
	ofs.close();
}

void test43()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	Personf p;
	ifs.read((char*)&p, sizeof(p));
	cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
}
int main() {
	test42();
	test43();
	system("pause");
	return 0;
}