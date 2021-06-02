#include<iostream>
using namespace std;

class MyInteger {//自定义整型
	friend ostream& operator<<(ostream& out, MyInteger myint);//友元
public:
	MyInteger() {
		m_Num = 0;
	}
	//重载前置++ 返回引用是为了一直对一个数据进行操作
	MyInteger& operator++() {
		//先++
		m_Num++;
		//再返回
		return *this;
	}
	//重载后置++ ：int代表占位参数，可以用于区分前置和后置递增 返回值：因为局部变量会释放，防止非法操作，所以不可以链式操作
	MyInteger operator++(int) {
		//先返回
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		return temp;
	}
private:
	int m_Num;
};
//自定义左移运算符
ostream& operator<<(ostream& out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}
void test20() {
	MyInteger myInt;
	cout << ++(++myInt) << endl;
	cout << myInt << endl;
	MyInteger myInt1;
	cout << myInt1++ << endl;
	cout << myInt1 << endl;
}

int main17() {
	int a = 1;
	test20();
	system("pause");
	return 0;
}