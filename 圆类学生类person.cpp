#include<iostream>
using namespace std;

const double PI = 3.14;//Բ����
//��װ������
//�����Ժ���Ϊ��Ϊһ�����壬�������������е������װһ��Բ�࣬��Բ���ܳ�
//class�������һ���࣬������ŵ�������
class Circle
{
public:  //����Ȩ��  ������Ȩ��
	int m_r;//���� ���� �뾶
	//��Ϊ ���� ��ȡ��Բ���ܳ�
	double calculateZC()
	{
		//2 * pi  * r
		//��ȡԲ���ܳ�
		return  2 * PI * m_r;
	}
};

//ѧ����
class Student {
public:
	void setName(string name) {//����Ϊ�����Ը�ֵ
		m_name = name;
	}
	void setID(int id) {
		m_id = id;
	}
	void showStudent() {
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
public:
	string m_name;
	int m_id;
};

//����Ȩ��
//����Ȩ��  public     ���ڿ��Է���  ������Է���
//����Ȩ��  protected  ���ڿ��Է���  ���ⲻ���Է��� ����Ҳ���Է��ʸ����еı�������
//˽��Ȩ��  private    ���ڿ��Է���  ���ⲻ���Է��� ����Ҳ�����Է���
class Person
{
//����  ����Ȩ��
public:
	string m_Name;
//����  ����Ȩ��
protected:
	string m_Car;
//���п�����  ˽��Ȩ��
private:
	int m_Password;
public:
	void func()
	{
		m_Name = "����"; //���ڷ���
		m_Car = "ro";
		m_Password = 123456;
	}
};

//struct��class����
class C3
{
	int  m_A; //classĬ����˽��Ȩ��
};
struct C4
{
	int m_A;  //structĬ���ǹ���Ȩ��
};

//��Ա��������Ϊ˽��
class Person1 {
public:
	//�������ÿɶ���д ����дȨ�ޣ����Լ�����ݵ���Ч��
	void setName(string name) {
		//���ֱ�����zz
		if (name == "zz") {
			m_Name = name;
		}
		else {
			return;
		}
	}
	string getName()
	{
		return m_Name;
	}
	//��ȡ���� 
	int getAge() {
		m_Age = 0;
		return m_Age;
	}
	//����hobby
	void sethobby(string hobby) {
		m_hobby = hobby;
	}
private:
	string m_Name; //�ɶ���д ����
	int m_Age; //ֻ�� ����
	string m_hobby; //ֻд hobby
};

int main4() {
	//ͨ��Բ�ഴ��Բ�Ķ���c1����һ�������Բ��ʵ����
	Circle c1;
	c1.m_r = 10; //��Բ��������� ���и�ֵ����
	//2 * pi * 10 = = 62.8
	cout << "Բ���ܳ�Ϊ�� " << c1.calculateZC() << endl;

	Student stu;
	stu.setName("zz");
	stu.setID(333);
	stu.showStudent();

	Person p;
	p.m_Name = "����";
	//p.m_Car = "����";  //����Ȩ��������ʲ���
	//p.m_Password = 123; //˽��Ȩ��������ʲ���
	p.func();

	//struct��class����
	C3 c3;
	//c3.m_A = 10; //����class����Ȩ����˽��
	C4 c4;
	c4.m_A = 10; //��ȷ��struct����Ȩ���ǹ���

	Person1 p1;
	//��������
	p1.setName("zz");
	cout << "������ " << p1.getName() << endl;
	//��������
	p1.getAge();
	cout << "���䣺 " << p1.getAge() << endl;
	//��������
	p1.sethobby("tea");

	system("pause");
	return 0;
}