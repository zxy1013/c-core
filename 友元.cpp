#include<iostream>
using namespace std;

//全局函数做友元
class Building
{
	//告诉编译器goodGay全局函数是Building类的好朋友，可以访问类中的私有内容
	friend void goodGay(Building* building);
public:
	Building()//构造函数
	{
		this->m_SittingRoom = "客厅";
		this->m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom; //卧室
};
//全局函数
void goodGay(Building* building)
{
	cout << "好基友正在访问： " << building->m_SittingRoom << endl;
	cout << "好基友正在访问： " << building->m_BedRoom << endl;
}
void test15()
{
	Building b;
	goodGay(&b);
}

//类做友元
class Building1;//告诉building后面会写这个类
class goodGay1
{
public:
	goodGay1();
	void visit();//参观函数访问building1中的属性
private:
	Building1* building;
};
class Building1
{
	//告诉编译器goodGay类是Building类的好朋友，可以访问到Building类中私有内容
	friend class goodGay1;
public:
	Building1();//声明
public:
	string m_SittingRoom1; //客厅
private:
	string m_BedRoom1;//卧室
};
Building1::Building1()//实现
{
	this->m_SittingRoom1 = "客厅";
	this->m_BedRoom1 = "卧室";
}
goodGay1::goodGay1()
{
	building = new Building1;
}
void goodGay1::visit()
{
	cout << "好基友正在访问" << building->m_SittingRoom1 << endl;
	cout << "好基友正在访问" << building->m_BedRoom1 << endl;
}
void test16()
{
	goodGay1 gg;
	gg.visit();

}

//成员函数做友元
class Building2;
class goodGay2
{
public:
	goodGay2();
	void visit(); //只让visit函数作为Building的好朋友，可以访问Building中私有内容
	void visit2();
private:
	Building2* building1;
};
class Building2
{
	//告诉编译器goodGay类中的visit成员函数是Building好朋友，可以访问私有内容
	friend void goodGay2::visit();
public:
	Building2();
public:
	string m_SittingRoom2; //客厅
private:
	string m_BedRoom2;//卧室
};
Building2::Building2()
{
	this->m_SittingRoom2 = "客厅";
	this->m_BedRoom2 = "卧室";
}
goodGay2::goodGay2()
{
	building1 = new Building2;
}
void goodGay2::visit()
{
	cout << "好基友1正在访问" << building1->m_SittingRoom2 << endl;
	cout << "好基友1正在访问" << building1->m_BedRoom2 << endl;
}
void goodGay2::visit2()
{
	cout << "好基友2正在访问" << building1->m_SittingRoom2 << endl;
	//cout << "好基友2正在访问" << building1->m_BedRoom2 << endl;//
}
void test17()
{
	goodGay2  gg;
	gg.visit();
	gg.visit2();
}

int main14() {
	test15();
	test16();
	test17();
	system("pause");
	return 0;
}