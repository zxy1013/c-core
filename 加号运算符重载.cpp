#include<iostream>
using namespace std;

class Person13 {
public:
	Person13() {};
	Person13(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//成员函数实现 + 号运算符重载
	//person13 p3 = p1.operator+(p2)==>可以简化为person13 p3 = p1 + p2
	Person13 operator+(const Person13& p) {
		Person13 temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
public:
	int m_A;
	int m_B;
};
//全局函数实现 + 号运算符重载
//person13 p3 = operator+(p1,p2)==>可以简化为person13 p3 = p1 + p2
/*Person13 operator+(const Person13& p1, const Person13& p2) {
	Person13 temp(0, 0);
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}*/
//运算符重载 也可以函数重载 
Person13 operator+(const Person13& p2, int val)
{
	Person13 temp;
	temp.m_A = p2.m_A + val;
	temp.m_B = p2.m_B + val;
	return temp;
}
void test18() {
	Person13 p1(10, 10);
	Person13 p2(20, 20);
	//成员函数方式
	Person13 p3 = p2 + p1;  //相当于 p2.operaor+(p1)
	cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;
	Person13 p4 = p3 + 10; //相当于 operator+(p3,10)
	cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
}
int main15() {
	test18();

	system("pause");
	return 0;
}