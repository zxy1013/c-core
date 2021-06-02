#include<iostream>
using namespace std;
class Person15
{
public:
	Person15(int age)
	{
		//将年龄数据开辟到堆区
		m_Age = new int(age);
	}
	//重载赋值运算符 
	Person15& operator=(Person15& p)
	{
		if (m_Age != NULL)//先判断是否有属性在堆区，如果有先释放
		{
			delete m_Age;
			m_Age = NULL;
		}
		//编译器提供的代码是浅拷贝 m_Age = p.m_Age;会造成指针重复释放的问题
		//提供深拷贝 解决浅拷贝的问题
		m_Age = new int(*p.m_Age);
		//返回自身
		return *this;
	}
	~Person15()//将堆区数据释放
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	//年龄的指针
	int* m_Age;
};

void test21()
{
	Person15 p1(18);
	Person15 p2(20);
	Person15 p3(30);
	p3 = p2 = p1; //赋值操作
	cout << "p1的年龄为：" << *p1.m_Age << endl;//18
	cout << "p2的年龄为：" << *p2.m_Age << endl;//18
	cout << "p3的年龄为：" << *p3.m_Age << endl;//18
}

int main18() {
	int a = 10;
	int b = 20;
	int c = 30;
	c = b = a;
	cout << "a = " << a << endl;//10
	cout << "b = " << b << endl;//10
	cout << "c = " << c << endl;//10
	test21();
	system("pause");
	return 0;
}