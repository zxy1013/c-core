#include<iostream>
using namespace std;

class Base7
{
public:
	//纯虚函数
	//类中只要有一个纯虚函数就称为抽象类
	//抽象类无法实例化对象
	//子类必须重写父类中的纯虚函数，否则也属于抽象类
	virtual void func() = 0;
};
class Son7 :public Base7
{
public:
	virtual void func()
	{
		cout << "func调用" << endl;
	};
};
void test36()
{
	Base7* base = NULL;
	//base = new Base7; // 错误，抽象类无法实例化对象
	base = new Son7;
	base->func();
	delete base;//记得销毁
}
int main31() {
	test36();
	system("pause");
	return 0;
}