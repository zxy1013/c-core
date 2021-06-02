#include<iostream>
using namespace std;

class Person2
{
public:
	//构造函数 程序在调用对象时候会自动调用构造，无须手动调用，而且只会调用一次
	Person2()
	{
		cout << "Person的构造函数调用" << endl;
	}
	//析构函数 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次
	~Person2()
	{
		cout << "Person的析构函数调用" << endl;
	}
};
void test01()
{	//局部变量，出了作用域就销毁对象
	Person2 p; //创建对象自动调用构造函数，程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次
}

//1、构造函数分类
// 按照参数分类分为 有参和无参构造 无参又称为默认构造函数
// 按照类型分类分为 普通构造和拷贝构造
class Person3 {
public:
	//无参（默认）构造函数 普通构造
	Person3() {
		cout << "无参构造函数!" << endl;
	}
	//有参构造函数 普通构造
	Person3(int a) {
		age = a;
		cout << "有参构造函数!" << endl;
	}
	//拷贝构造函数 引用方法传参
	Person3(const Person3& p) {
		age = p.age;
		cout << "拷贝构造函数!" << endl;
	}
	//析构函数
	~Person3() {
		cout << "析构函数!" << endl;
	}
public:
	int age;
};

//2、构造函数的调用
void test02() {
	//默认构造函数调用
	//调用无参构造函数
	Person3 p1; 

	//调用有参的构造函数
	//括号法，常用
	Person3 p2(10);
	Person3 p3(p2); //p3.age=p2.age
	//调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明void func();
	//Person p4();

	//显式法
	Person3 p4 = Person3(10);//有参构造
	Person3 p5 = Person3(p2);//拷贝构造
	Person3(10);//单独写就是匿名对象 当前行执行结束之后，系统立即回收匿名对象，马上析构
	//Person3(p4);//不能利用拷贝构造函数 初始化匿名对象 编译器会认为是对象声明
	//Person3(p4) === Person3 p4 报错P4重定义
	
	// 隐式转换法
	Person3 p6 = 10; // 相当于Person3 p6 = Person(10); 
	Person3 p7 = p4; // 拷贝构造 相当于Person3 p7 = Person(p4); 
}

int main7() {
	test01();//Person的构造函数调用 Person的析构函数调用
	Person2 p;//Person的构造函数调用 请按任意键继续. . .Person的析构函数调用
	//由于全局变量程序运行完成后释放，即return0后。所以在最后进行析构函数的调用
	test02();

	system("pause");
	return 0;
}