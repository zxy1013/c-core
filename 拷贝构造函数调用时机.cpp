#include<iostream>
using namespace std;

class Person4 {
public:
	Person4() {
		cout << "无参构造函数!" << endl;
		mAge = 0;
	}
	Person4(int age) {
		cout << "有参构造函数!" << endl;
		mAge = age;
	}
	Person4(const Person4& p) {
		cout << "拷贝构造函数!" << endl;
		mAge = p.mAge;
	}
	//析构函数在释放内存之前调用
	~Person4() {
		cout << "析构函数!" << endl;
	}
public:
	int mAge;
};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test03() {
	Person4 man(20); //man对象已经创建完毕
	Person4 newman(man); //调用拷贝构造函数
	Person4 newman2 = man; //拷贝构造
}

//2. 值传递的方式给函数参数传值
//相当于Person p1 = p;
void doWork(Person4 p1) {}
void test04() {
	Person4 p; //无参构造函数
	doWork(p);//拷贝构造函数! Person4 p1 = p
}

//3. 以值方式返回局部对象
Person4 doWork2()
{
	Person4 p1;
	cout << (int*)&p1 << endl; //对象地址 001EF740
	return p1; //拷贝构造函数!
}
void test05()
{
	Person4 p = doWork2();
	cout << (int*)&p << endl; //对象地址 001EF838 
}

//构造函数调用规则
void test06()
{
	Person4 p1(18);
	//如果不写拷贝构造Person4(const Person4& p)函数 编译器会自动添加拷贝构造，并且做浅拷贝操作
	Person4 p2(p1);
	cout << "p2的年龄为： " << p2.mAge << endl;
}

void test07()
{
	//如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造
	Person4 p1; //此时如果用户自己没有提供默认构造，会出错：不存在默认构造函数
	Person4 p2(10); //用户提供的有参
	Person4 p3(p2); //此时如果用户没有提供拷贝构造，编译器会提供

	//如果用户提供拷贝构造，编译器不会提供其他构造函数
	Person4 p4; //此时如果用户自己没有提供默认构造，会出错
	Person4 p5(10); //此时如果用户自己没有提供有参构造，会出错
	Person4 p6(p5); //用户自己提供拷贝构造
}
int main8() {
	test03();
	test04();
	test05();
	test06();
	test07();

	system("pause");
	return 0;
}