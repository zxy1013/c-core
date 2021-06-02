#include<iostream>
using namespace std;
class Person16
{
public:
	Person16(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	};
	bool operator==(Person16& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(Person16& p)
	{
		if (this->m_Age >= p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};

void test22()
{
	Person16 a("孙悟空", 17);
	Person16 b("孙悟空", 18);
	if (a == b)
	{
		cout << "a和b相等" << endl;
	}
	else
	{
		cout << "a和b不相等" << endl;
	}
	if (a >= b)
	{
		cout << "a的年纪大于等于b" << endl;
	}
	else
	{
		cout << "a的年纪小于b" << endl;
	}
}
int main19() {
	test22();
	system("pause");
	return 0;
}