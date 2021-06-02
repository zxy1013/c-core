#include<iostream>
using namespace std;

//1. 值传递
void mySwap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. 引用传递
void mySwap03(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//4. 引用做函数返回值
//不要返回局部变量引用 &表示以引用方式返回
int& test01() {
	int a = 10; //局部变量 栈区
	return a;
}
//可以返回静态变量引用
int& test02() {
	static int a = 20;//全局区数据在系统结束后释放
	return a;
}

//5. 引用的本质
//发现是引用，转换为 int* const ref = &a;
void func(int& ref) {
	ref = 100; // ref是引用，转换为*ref = 100
}

//6. 引用使用的场景，通常用来修饰形参
void showValue(const int& v) {
	//v += 10;//不可修改
	cout << v << endl;
}

int main2() {
	// 引用的基本语法
	int a = 10;//开辟一块内存，四个字节，存的值为10，用a操作数据

	// 数据类型& 别名 = 原名
	//int& b = 10;//引用必须引一块合法的内存空间
	int& b = a;//给用户起别名，用b来操作内存，b和a访问内存相同
	cout << "a = " << a <<" "<<&a << endl;//10 00BBF7A4
	cout << "b = " << b << " "<< &b << endl;//10 00BBF7A4
	b = 100;
	cout << "a = " << a << endl;//100
	cout << "b = " << b << endl;//100

	// 引用注意事项
	int a1 = 10;
	int b1 = 20;
	//int &c; //错误，引用必须初始化
	int& c1 = a1; //一旦初始化后，就不可以更改为其他变量的别名
	c1 = b1; //这是赋值操作，不是更改引用
	cout << "a = " << a1 << " " << &a1 << endl;//20 0055F85C
	cout << "b = " << b1 << " " << &b1 << endl;//20 0055F850
	cout << "c = " << c1 << " " << &c1 << endl;//20 0055F85C


	//引用做函数参数
	int a2 = 10;
	int b2 = 20;
	mySwap01(a2, b2);
	cout << "a:" << a2 << " b:" << b2 << endl;//10 20
	mySwap02(&a2, &b2);
	cout << "a:" << a2 << " b:" << b2 << endl;//20 10
	a2 = 10;
	b2 = 20;
	mySwap03(a2, b2);
	cout << "a:" << a2 << " b:" << b2 << endl;//20 10


	//不能返回局部变量的引用
	int& ref = test01();
	cout << "ref = " << ref << endl;//10
	cout << "ref = " << ref << endl;//a的内存已经释放，类似指针
	//返回静态变量的引用
	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	cout << "ref2 = " << ref2 << endl;
	//如果函数调用做左值，那么必须返回引用
	//即如果函数返回值为引用，函数调用可以作为左值
	test02() = 1000;//相当于a=1000 ref2是a的别名
	cout << "ref2 = " << ref2 << endl;//1000
	cout << "ref2 = " << ref2 << endl;//1000

	//引用本质
	int a3 = 10;
	//自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	int& ref1 = a3;
	ref1 = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;
	cout << "a:" << a3 << endl;//20
	cout << "ref:" << ref1 << endl;//20
	func(a3);
	cout << "ref:" << ref1 << endl;//100


	//常量引用
	//int& ref2 = 10;  //引用本身需要一个合法的内存空间，因此这行错误
	//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
	const int& ref3 = 10;
	//ref3 = 100;  //加入const后不可以修改变量
	//函数中利用常量引用防止误操作修改实参
	int a4 = 10;
	showValue(a4);

	system("pause");
	return 0;
}
