#include<iostream>
using namespace std;

class Base4 {
public:
	static void func()
	{
		cout << "Base - static void func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base - static void func(int a)" << endl;
	}
	static int m_A;
};
//类外初始化
int Base4::m_A = 100;
class Son4 : public Base4 {
public:
	static void func()
	{
		cout << "Son - static void func()" << endl;
	}
	static int m_A;
};
//类外初始化
int Son4::m_A = 200;

//同名成员属性
void test29()
{
	//通过对象访问
	cout << "通过对象访问： " << endl;
	Son4 s;
	cout << "Son  下 m_A =  " << s.m_A << endl;
	cout << "Base 下 m_A =  " << s.Base4::m_A << endl;

	//通过类名访问
	cout << "通过类名访问： " << endl;
	cout << "Son  下 m_A =  " << Son4::m_A << endl;
	cout << "Base 下 m_A =  " << Son4::Base4::m_A << endl;//通过类名的方式访问父类作用域下的m_A
	cout << "Base 下 m_A =  " << Base4::m_A << endl;
}

//同名成员函数
void test30()
{
	//通过对象访问
	cout << "通过对象访问： " << endl;
	Son4 s;
	s.func();
	s.Base4::func();

	cout << "通过类名访问： " << endl;
	Son4::func();
	Son4::Base4::func();
	//出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
	Son4::Base4::func(100);
}
int main26() {
	test29();
	test30();
	system("pause");
	return 0;
}