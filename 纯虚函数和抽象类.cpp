#include<iostream>
using namespace std;

class Base7
{
public:
	//���麯��
	//����ֻҪ��һ�����麯���ͳ�Ϊ������
	//�������޷�ʵ��������
	//���������д�����еĴ��麯��������Ҳ���ڳ�����
	virtual void func() = 0;
};
class Son7 :public Base7
{
public:
	virtual void func()
	{
		cout << "func����" << endl;
	};
};
void test36()
{
	Base7* base = NULL;
	//base = new Base7; // ���󣬳������޷�ʵ��������
	base = new Son7;
	base->func();
	delete base;//�ǵ�����
}
int main31() {
	test36();
	system("pause");
	return 0;
}