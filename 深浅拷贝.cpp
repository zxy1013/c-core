#include<iostream>
using namespace std;

class Person5 {
public:
	Person5() {
		cout << "�޲ι��캯��!" << endl;
	}
	Person5(int age, int height) {
		cout << "�вι��캯��!" << endl;
		m_age = age;
		m_height = new int(height);
	}
	//�������忽�����캯������������Զ���ǳ������
	//�������캯��  
	Person5(const Person5& p) {
		cout << "�������캯��!" << endl;
		//�������������ڶ����������ڴ棬�ᵼ��ǳ�����������ظ��ͷŶ�������
		m_age = p.m_age;
		//m_height = p.m_height; //������Ĭ��ʵ��Ϊ���д���
		m_height = new int(*p.m_height);//���� ���
	}
	//�������� ���������������ͷ�
	~Person5() {
		cout << "��������!" << endl;
		if (m_height != NULL)
		{
			delete m_height;//�ֶ��ͷŶ�������
			m_height = NULL;
		}
	}
public:
	int m_age;
	int* m_height;
};

void test08()
{
	Person5 p1(18, 180);
	Person5 p2(p1);
	cout << "p1�����䣺 " << p1.m_age << " ��ߣ� " << *p1.m_height << endl;
	cout << "p2�����䣺 " << p2.m_age << " ��ߣ� " << *p2.m_height << endl;
}

int main9() {
	test08();
	system("pause");
	return 0;
}