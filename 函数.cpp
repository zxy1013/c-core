#include<iostream>
using namespace std;

//1. ���ĳ��λ�ò�����Ĭ��ֵ����ô�����λ�����󣬴������ң����붼Ҫ��Ĭ��ֵ
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}
//2. �������������Ĭ��ֵ������ʵ�ֵ�ʱ��Ͳ�����Ĭ�ϲ���
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

//����ռλ������ռλ����Ҳ������Ĭ�ϲ���
//���ں������н��ղ�������Ĳ���������Ŀǰ�γ̻��ò����������ὲ
void func1(int a, int) {
	cout << "this is func1" << endl;
}
void func3(int a, int = 10) {
	cout << "this is func3" << endl;
}

//��������
//����������Ҫ��������ͬһ���������£�ȫ��������
//����������ͬ
//�������� ���� ˳��ͬ
void func4()
{
	cout << "func4 �ĵ��ã�" << endl;
}
void func4(int a)
{
	cout << "func4 (int a) �ĵ��ã�" << endl;
}
void func4(double a)
{
	cout << "func4 (double a)�ĵ��ã�" << endl;
}
//˳��ͬ
void func4(int a, double b)
{
	cout << "func4 (int a ,double b) �ĵ��ã�" << endl;
}
void func4(double a, int b)
{
	cout << "func4 (double a ,int b)�ĵ��ã�" << endl;
}
//��������ֵ��������Ϊ������������
//int func4(double a, int b)
//{
//	cout << "func4 (double a ,int b)�ĵ��ã�" << endl;
//}

//��������ע������
//1��������Ϊ�������� �����������Ͳ�ͬ
void func5(int& a)
{
	cout << "func5 (int &a) ���� " << endl;
}
void func5(const int& a)
{
	cout << "func5 (const int &a) ���� " << endl;
}
//2������������������Ĭ�ϲ���
void func6(int a, int b = 10)
{
	cout << "func6(int a, int b = 10) ����" << endl;
}
void func6(int a)
{
	cout << "func6(int a) ����" << endl;
}
int main3() {
	cout << "ret = " << func(20, 20) << endl;//50
	cout << "ret = " << func(100) << endl;//120
	cout << "ret = " << func2() << endl;//20

	func1(10, 10); //ռλ���������
	func3(10); //��Ĭ��ֵ�����Կ��Բ����

	func4();
	func4(10);
	func4(3.14);
	func4(10, 3.14);
	func4(3.14, 10);

	int a = 10;
	func5(a); //Ĭ���ȵ�����const
	func5(10);//������const ����int& a=10���Ϸ�
	//func6(10); //����Ĭ�ϲ����������壬��Ҫ���⣬���������أ�����������ʱ��������func6(int a, int b = 10)����

	system("pause");
	return 0;
}