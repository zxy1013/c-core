#include<iostream>
using namespace std;

//全局变量:不在函数体内的变量
int g_a = 10;
int g_b = 10;

//全局常量
const int c_g_a = 10;
const int c_g_b = 10;

//栈区：
int* func(int b)//形参数据也会放在栈区
{
	b = 100;
	int a = 10; //创建局部变量
	return &a; //返回局部变量的地址。不可以！！！
	//return &b; //返回形参的地址。不可以！！！
}

//堆区 利用new在堆区开辟内存
int* func1()
{
	//指针本质为局部变量 放在栈区，指针保存的数据放在了堆区
	int* a = new int(10); //堆区中新建int=10  数据类型* a = new 数据类型(值)
	cout << "*****： " << &a << endl; //005EFB58 //指针的栈区地址
	cout << "*****： " << a << endl; //0099B650 //指向的堆区地址
	cout << "*****： " << *a << endl; //10 //堆区的数据
	return a; //返回堆区的地址
}

int main1() {
	
	//创建局部变量
	int a = 10;
	int b = 10;
	cout << "局部变量a地址为： " << &a << endl; //003EFD9C
	cout << "局部变量b地址为： " << &b << endl;
	cout << "全局变量g_a地址为： " << &g_a << endl;//004AC000
	cout << "全局变量g_b地址为： " << &g_b << endl;
	
	//静态变量 在普通变量前面加static
	static int s_a = 10;
	static int s_b = 10;
	cout << "静态变量s_a地址为： " << &s_a << endl; //004AC008
	cout << "静态变量s_b地址为： " << &s_b << endl;
	cout << "字符串常量地址为： " << &"hello world" << endl;//004A9BF4
	cout << "字符串常量地址为： " << &"hello world1" << endl;
	cout << "全局常量c_g_a地址为： " << &c_g_a << endl;//004A9B30
	cout << "全局常量c_g_b地址为： " << &c_g_b << endl;
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "局部常量c_l_a地址为： " << &c_l_a << endl;//003EFD84
	cout << "局部常量c_l_b地址为： " << &c_l_b << endl;


	//栈区开辟的数据由编译器自动释放
	int a1 = 1;
	int* p = func(a1);
	cout << *p << endl; //第一次可以打印正确的数据，是因为编译器做了一次保留
	cout << *p << endl; //输出乱码，因为编译器不再保留


	//堆区 程序结束时由操作系统回收。
	int* p1 = func1();
	cout << *p1 << endl; //第一次可以打印正确的数据，是因为编译器做了一次保留
	cout << *p1 << endl; //输出乱码，因为编译器不再保留
	//利用delete 变量名释放堆区数据
	delete p1;
	//cout << *p1 << endl; //报错，释放的空间不可访问。读取访问权限冲突
	

	//堆区 利用new在堆区开辟数组 10代表数组有10个元素 返回数组地址
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100; //存放数据
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;//打印操作
	}
	//释放数组 delete[] 数组变量名
	delete[] arr;
	/*for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;//打印操作
	}*/

	system("pause");
	return 0;
}