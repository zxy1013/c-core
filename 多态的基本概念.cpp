#include<iostream>
using namespace std;

class Animal1
{
public:
	//����ǰ�����virtual�ؼ��֣�����麯������ô�������ڱ����ʱ��Ͳ���ȷ�����������ˡ�
	//���û���麯������һֱֻ�����������˵��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};
class Cat :public Animal1
{
public:
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};
class Dog :public Animal1
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;
	}
};
//����ϣ������ʲô������ô�͵���ʲô����ĺ���
//���������ַ�ڱ���׶ξ���ȷ������ô��̬����
//���������ַ�����н׶β���ȷ�������Ƕ�̬����
void DoSpeak(Animal1& animal)//�������ý�������������û���麯������һֱֻ�����������˵��
{
	animal.speak();
}
//��̬��̬���������� 
//1���м̳й�ϵ
//2��������д�����е��麯��
//��̬ʹ�ã�
//����ָ�������ָ��������� �������ý����������
void test33()
{
	Cat cat;
	DoSpeak(cat);//�������ý����������
	Dog dog;
	DoSpeak(dog);
}
int main29() {
	test33();
	system("pause");
	return 0;
}