#include<iostream>
using namespace std;
class Base5 {
public:
	Base5()
	{
		m_A = 100;
	}
public:
	int m_A;
};

class Base6 {
public:
	Base6()
	{
		m_A = 200;  //开始是m_B 不会出问题，但是改为mA就会出现不明确
	}
public:
	int m_A;
};

//语法：class 子类：继承方式 父类1 ，继承方式 父类2 
class Son5 : public Base5, public Base6
{
public:
	Son5()
	{
		m_C = 300;
		m_D = 400;
	}
public:
	int m_C;
	int m_D;
};

//多继承容易产生成员同名的情况
//通过使用类名作用域可以区分调用哪一个基类的成员
void test31()
{
	Son5 s;
	cout << "sizeof Son = " << sizeof(s) << endl;
	cout << s.Base5::m_A << endl;
	cout << s.Base6::m_A << endl;
}

int main27() {
	test31();
	system("pause");
	return 0;
}