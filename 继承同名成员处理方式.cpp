#include<iostream>
using namespace std;

class Base3 {
public:
	Base3()
	{
		m_A = 100;
	}
	void func()
	{
		cout << "Base - func()调用" << endl;
	}
	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
	}
public:
	int m_A;
};

class Son3 : public Base3 {
public:
	Son3()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son - func()调用" << endl;
	}
public:
	int m_A;
};

void test28()
{
	Son3 s;
	cout << "Son下的m_A = " << s.m_A << endl;
	//如果想访问父类中被隐藏的同名成员、函数，需要加父类的作用域
	cout << "Base下的m_A = " << s.Base3::m_A << endl;
	s.func();
	s.Base3::func();
	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	//s.func(10);//必须使用作用域访问
	s.Base3::func(10);
}
int main25() {
	test28();
	system("pause");
	return EXIT_SUCCESS;
}