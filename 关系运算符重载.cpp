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
	Person16 a("�����", 17);
	Person16 b("�����", 18);
	if (a == b)
	{
		cout << "a��b���" << endl;
	}
	else
	{
		cout << "a��b�����" << endl;
	}
	if (a >= b)
	{
		cout << "a����ʹ��ڵ���b" << endl;
	}
	else
	{
		cout << "a�����С��b" << endl;
	}
}
int main19() {
	test22();
	system("pause");
	return 0;
}