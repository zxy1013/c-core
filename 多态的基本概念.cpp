#include<iostream>
using namespace std;

class Animal1
{
public:
	//函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
	//如果没有虚函数，则一直只会输出动物在说话
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};
class Cat :public Animal1
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
class Dog :public Animal1
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};
//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编
void DoSpeak(Animal1& animal)//父类引用接收子类对象，如果没有虚函数，则一直只会输出动物在说话
{
	animal.speak();
}
//动态多态满足条件： 
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用：
//父类指针或引用指向子类对象 父类引用接收子类对象
void test33()
{
	Cat cat;
	DoSpeak(cat);//父类引用接收子类对象
	Dog dog;
	DoSpeak(dog);
}
int main29() {
	test33();
	system("pause");
	return 0;
}