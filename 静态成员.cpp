#include<iostream>
using namespace std;

class Person7{
public:
	static int m_A; //静态成员变量
	//静态成员变量特点：
	//1 在编译阶段分配内存
	//2 类内声明，类外初始化
	//3 所有对象共享同一份数据
private:
	static int m_B; //静态成员变量也是有访问权限的
};
//类外初始化
int Person7::m_A = 10;//person作用域下的静态变量
int Person7::m_B = 10;

void test10()
{
	//静态成员变量两种访问方式
	//1、通过对象
	Person7 p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;
	Person7 p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl; //共享同一份数据
	cout << "p2.m_A = " << p2.m_A << endl;
	//cout << "m_B = " << p1.m_B << endl;//私有权限访问不到

	//2、通过类名
	cout << "m_A = " << Person7::m_A << endl;
	//cout << "m_B = " << Person7::m_B << endl; //私有权限访问不到
}

//静态成员函数
class Person8
{
public:
	//静态成员函数特点：
	//1 程序共享一个函数
	//2 静态成员函数只能访问静态成员变量
	static void func()
	{
		cout << "func调用" << endl;
		m_A = 100;//静态成员函数可以访问静态成员变量
		//m_B = 100; //错误，不可以访问非静态成员变量
	}
	static int m_A; //静态成员变量
	int m_B; //非静态成员变量 
private:
	//静态成员函数也是有访问权限的
	static void func2()
	{
		cout << "func2调用" << endl;
	}
};
int Person8::m_A = 10;//类外初始化
void test11()
{
	//静态成员变量两种访问方式
	//1、通过对象
	Person8 p1;
	p1.func();
	//2、通过类名
	Person8::func();
	//Person8::func2(); //私有权限访问不到
}
int main12() {
	test10();
	test11();
	system("pause");
	return 0;
}