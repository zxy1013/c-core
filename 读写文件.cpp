#include <fstream>
#include<iostream>
#include <string>
using namespace std;

void test40()
{
	ofstream ofs;//����������
	ofs.open("test.txt", ios::out);//���ļ� ��ĿĿ¼
	ofs << "����������" << endl;//д�ļ�
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
	ofs.close();//�ر��ļ�
}

void test41()
{
	ifstream ifs;//����������
	ifs.open("test.txt", ios::in);//�ж��ļ��Ƿ�򿪳ɹ�
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	////��һ�ֶ�ȡ��ʽ
	//char buf[1024] = { 0 };
	//while (ifs >> buf)//����ͷ���ؼ�
	//{
	//	cout << buf << endl;
	//}

	////�ڶ���
	//char buf1[1024] = { 0 };
	//while (ifs.getline(buf1,sizeof(buf1)))//���ݷ����ַ����飬����ȡsizeof(buf)��
	//{
	//	cout << buf1 << endl;
	//}

	////������
	//string buf2;
	//while (getline(ifs, buf2))
	//{
	//	cout << buf2 << endl;
	//}

	//������ ̫��
	char c;
	while ((c = ifs.get()) != EOF)//û�ж����ļ�β
	{
		cout << c;
	}
	ifs.close();//�ر��ļ�
}
int main35() {
	//test40();
	test41();
	system("pause");
	return 0;
}