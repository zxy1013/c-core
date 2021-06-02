#include<iostream>
using namespace std;
class Phone
{
public:
	Phone(string name)
	{
		m_PhoneName = name;
		cout << "Phone构造" << endl;
	}
	~Phone()
	{
		cout << "Phone析构" << endl;
	}
	string m_PhoneName;
};

class Person6
{
public:
	//初始化列表可以告诉编译器调用哪一个构造函数
	Person6(string name, string pName) :m_Name(name), m_Phone(pName)
	{
		cout << "Person构造" << endl;
	}
	~Person6()
	{
		cout << "Person析构" << endl;
	}
	void playGame()
	{
		cout << m_Name << " 使用" << m_Phone.m_PhoneName << " 牌手机! " << endl;
	}
	string m_Name;
	//当类中成员是其他类对象时，我们称该成员为对象成员
	Phone m_Phone;
};
void test09()
{
	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反 Person析构-->Phone析构
	Person6 p("张三", "苹果X");//Phone构造-->Person构造
	p.playGame();
}

int main11() {
	test09();
	system("pause");
	return 0;
}