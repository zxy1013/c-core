#include<iostream>
using namespace std;

class Person9 {
};
class Person8 {
public:
	Person8() {
		mA = 0;
	}
	//非静态成员变量占对象空间
	int mA;
	//静态成员变量不占对象空间
	static int mB;
	//函数也不占对象空间，所有函数共享一个函数实例
	void func() {}
	//静态成员函数也不占对象空间
	static void sfunc() {
	}
};

//this指针概念
class Person10
{
public:
	Person10(int age)
	{
		//age = age;//p1.age = -858993460 由于编译器无法区分形参和成员变量
		//1、当形参和成员变量同名时，可用this指针来区分
		this->age = age;
	}
	//返回引用
	Person10& PersonAddPerson(Person10 p)
	{
		this->age += p.age;
		//返回对象本身，可以继续调用
		return *this;
	}
	int age;
};
void test12()
{
	Person10 p1(10);
	cout << "p1.age = " << p1.age << endl;

	Person10 p2(10);
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
	cout << "p2.age = " << p2.age << endl;
}

//空指针访问成员函数
class Person11 {
public:
	void ShowClassName() {
		cout << "我是Person类!" << endl;
	}
	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << mAge << endl; //mAge前默认添加了this->mAge
	}
public:
	int mAge;
};
void test13()
{
	Person11* p = NULL;
	p->ShowClassName(); //空指针，可以调用成员函数
	p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了 报错是因为传入的指针为空 加入if判断
}

//const修饰成员函数
class Person12 {
public:
	Person12() {
		//this指针的本质为指针常量，指向不可修改，值可以修改 Person12* const this
		m_A = 0;
		m_B = 0;
	}
	//如果想让指针指向的值也不可以修改，需要声明常函数 const Person12* const this
	void ShowPerson() const {
		//this->m_A = 100; //this指针指向对象的数据不可以修改
		//m_A = 10;
		//const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
		this->m_B = 100;
		m_B = 10;
	}
	void MyFunc(){
	}
public:
	int m_A;
	mutable int m_B; //使得在常函数中依然可以修改
};
//const修饰对象  常对象
void test14() {
	const Person12 person; //常量对象  
	cout << person.m_A << endl;
	//person.m_A = 100; //常对象不能修改成员变量的值，但是可以访问
	person.m_B = 100; //常对象可以修改mutable修饰成员变量
	//常对象只能调用常函数
	person.ShowPerson();//常对象只能调用const的函数
	//person.MyFunc(); //常对象不能调用非常函数
}

int main13() {
	Person8 p1;
	cout << sizeof(Person8) << endl;//4
	cout << sizeof(p1) << endl;//4
	
	//空对象占用内存空间为1字节
	//C++编译器会给每一个空对象分配一个字节的空间，是为了区分空对象占内存的位置
	//每个空对象也应该有一份独一无二的内存地址
	Person9 p;
	cout << sizeof(p) << endl;//1
	
	//this指针概念
	test12();

	//空指针访问成员函数
	test13();

	test14();
	system("pause");
	return 0;
}