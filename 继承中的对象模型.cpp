#include<iostream>
using namespace std;
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被编译器隐藏了，但是还是会被继承下去
};
//公共继承 父类中的所有非静态成员都会被子类继承下去
class Son :public Base
{
public:
	int m_D;
};
void test26()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;//16
}
int main23() {
	test26();
	system("pause");
	return 0;
}