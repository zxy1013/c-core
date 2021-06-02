#include<iostream>
using namespace std;

class Base2
{
public:
	Base2()
	{
		cout << "Base构造函数!" << endl;
	}
	~Base2()
	{
		cout << "Base析构函数!" << endl;
	}
};

class Son2 : public Base2
{
public:
	Son2()
	{
		cout << "Son构造函数!" << endl;
	}
	~Son2()
	{
		cout << "Son析构函数!" << endl;
	}
};

void test27()
{
	//继承中先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
	Son2 s;
}

int main24() {
	test27();//Base构造函数! Son构造函数! Son析构函数! Base析构函数!
	system("pause");
	return 0;
}