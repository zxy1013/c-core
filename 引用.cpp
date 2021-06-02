#include<iostream>
using namespace std;

//1. ֵ����
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. ��ַ����
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. ���ô���
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//4. ��������������ֵ
//��Ҫ���ؾֲ��������� &��ʾ�����÷�ʽ����
int& test01() {
	int a = 10; //�ֲ����� ջ��
	return a;
}
//���Է��ؾ�̬��������
int& test02() {
	static int a = 20;//ȫ����������ϵͳ�������ͷ�
	return a;
}

//5. ���õı���
//���������ã�ת��Ϊ int* const ref = &a;
void func(int& ref) {
	ref = 100; // ref�����ã�ת��Ϊ*ref = 100
}

//6. ����ʹ�õĳ�����ͨ�����������β�
void showValue(const int& v) {
	//v += 10;//�����޸�
	cout << v << endl;
}

int main2() {
	// ���õĻ����﷨
	int a = 10;//����һ���ڴ棬�ĸ��ֽڣ����ֵΪ10����a��������

	// ��������& ���� = ԭ��
	//int& b = 10;//���ñ�����һ��Ϸ����ڴ�ռ�
	int& b = a;//���û����������b�������ڴ棬b��a�����ڴ���ͬ
	cout << "a = " << a <<" "<<&a << endl;//10 00BBF7A4
	cout << "b = " << b << " "<< &b << endl;//10 00BBF7A4
	b = 100;
	cout << "a = " << a << endl;//100
	cout << "b = " << b << endl;//100

	// ����ע������
	int a1 = 10;
	int b1 = 20;
	//int &c; //�������ñ����ʼ��
	int& c1 = a1; //һ����ʼ���󣬾Ͳ����Ը���Ϊ���������ı���
	c1 = b1; //���Ǹ�ֵ���������Ǹ�������
	cout << "a = " << a1 << " " << &a1 << endl;//20 0055F85C
	cout << "b = " << b1 << " " << &b1 << endl;//20 0055F850
	cout << "c = " << c1 << " " << &c1 << endl;//20 0055F85C


	//��������������
	int a2 = 10;
	int b2 = 20;
	mySwap01(a2, b2);
	cout << "a:" << a2 << " b:" << b2 << endl;//10 20
	mySwap02(&a2, &b2);
	cout << "a:" << a2 << " b:" << b2 << endl;//20 10
	a2 = 10;
	b2 = 20;
	mySwap03(a2, b2);
	cout << "a:" << a2 << " b:" << b2 << endl;//20 10


	//���ܷ��ؾֲ�����������
	int& ref = test01();
	cout << "ref = " << ref << endl;//10
	cout << "ref = " << ref << endl;//a���ڴ��Ѿ��ͷţ�����ָ��
	//���ؾ�̬����������
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;
	//���������������ֵ����ô���뷵������
	//�������������ֵΪ���ã��������ÿ�����Ϊ��ֵ
	test02() = 1000;//�൱��a=1000 ref2��a�ı���
	cout << "ref2 = " << ref2 << endl;//1000
	cout << "ref2 = " << ref2 << endl;//1000

	//���ñ���
	int a3 = 10;
	//�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
	int& ref1 = a3;
	ref1 = 20; //�ڲ�����ref�����ã��Զ�������ת��Ϊ: *ref = 20;
	cout << "a:" << a3 << endl;//20
	cout << "ref:" << ref1 << endl;//20
	func(a3);
	cout << "ref:" << ref1 << endl;//100


	//��������
	//int& ref2 = 10;  //���ñ�����Ҫһ���Ϸ����ڴ�ռ䣬������д���
	//����const�Ϳ����ˣ��������Ż����룬int temp = 10; const int& ref = temp;
	const int& ref3 = 10;
	//ref3 = 100;  //����const�󲻿����޸ı���
	//���������ó������÷�ֹ������޸�ʵ��
	int a4 = 10;
	showValue(a4);

	system("pause");
	return 0;
}
