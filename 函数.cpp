#include<iostream>
using namespace std;

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}
//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

//函数占位参数，占位参数也可以有默认参数
//由于函数体中接收不到后面的参数，所以目前课程还用不到，后续会讲
void func1(int a, int) {
	cout << "this is func1" << endl;
}
void func3(int a, int = 10) {
	cout << "this is func3" << endl;
}

//函数重载
//函数重载需要函数都在同一个作用域下，全局作用域
//函数名称相同
//参数类型 个数 顺序不同
void func4()
{
	cout << "func4 的调用！" << endl;
}
void func4(int a)
{
	cout << "func4 (int a) 的调用！" << endl;
}
void func4(double a)
{
	cout << "func4 (double a)的调用！" << endl;
}
//顺序不同
void func4(int a, double b)
{
	cout << "func4 (int a ,double b) 的调用！" << endl;
}
void func4(double a, int b)
{
	cout << "func4 (double a ,int b)的调用！" << endl;
}
//函数返回值不可以作为函数重载条件
//int func4(double a, int b)
//{
//	cout << "func4 (double a ,int b)的调用！" << endl;
//}

//函数重载注意事项
//1、引用作为重载条件 两个属于类型不同
void func5(int& a)
{
	cout << "func5 (int &a) 调用 " << endl;
}
void func5(const int& a)
{
	cout << "func5 (const int &a) 调用 " << endl;
}
//2、函数重载碰到函数默认参数
void func6(int a, int b = 10)
{
	cout << "func6(int a, int b = 10) 调用" << endl;
}
void func6(int a)
{
	cout << "func6(int a) 调用" << endl;
}
int main3() {
	cout << "ret = " << func(20, 20) << endl;//50
	cout << "ret = " << func(100) << endl;//120
	cout << "ret = " << func2() << endl;//20

	func1(10, 10); //占位参数必须填补
	func3(10); //有默认值，所以可以不用填补

	func4();
	func4(10);
	func4(3.14);
	func4(10, 3.14);
	func4(3.14, 10);

	int a = 10;
	func5(a); //默认先调用无const
	func5(10);//调用有const 由于int& a=10不合法
	//func6(10); //碰到默认参数产生歧义，需要避免，有两个重载，传两个参数时编译器走func6(int a, int b = 10)调用

	system("pause");
	return 0;
}