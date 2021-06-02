#include<iostream>
using namespace std;

const double PI = 3.14;//圆周率
//封装的意义
//将属性和行为作为一个整体，用来表现生活中的事物。封装一个圆类，求圆的周长
//class代表设计一个类，后面跟着的是类名
class Circle
{
public:  //访问权限  公共的权限
	int m_r;//属性 变量 半径
	//行为 函数 获取到圆的周长
	double calculateZC()
	{
		//2 * pi  * r
		//获取圆的周长
		return  2 * PI * m_r;
	}
};

//学生类
class Student {
public:
	void setName(string name) {//用行为给属性赋值
		m_name = name;
	}
	void setID(int id) {
		m_id = id;
	}
	void showStudent() {
		cout << "name:" << m_name << " ID:" << m_id << endl;
	}
public:
	string m_name;
	int m_id;
};

//三种权限
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问 子类也可以访问父类中的保护内容
//私有权限  private    类内可以访问  类外不可以访问 子类也不可以访问
class Person
{
//姓名  公共权限
public:
	string m_Name;
//汽车  保护权限
protected:
	string m_Car;
//银行卡密码  私有权限
private:
	int m_Password;
public:
	void func()
	{
		m_Name = "张三"; //类内访问
		m_Car = "ro";
		m_Password = 123456;
	}
};

//struct和class区别
class C3
{
	int  m_A; //class默认是私有权限
};
struct C4
{
	int m_A;  //struct默认是公共权限
};

//成员属性设置为私有
class Person1 {
public:
	//姓名设置可读可写 对于写权限，可以检测数据的有效性
	void setName(string name) {
		//名字必须是zz
		if (name == "zz") {
			m_Name = name;
		}
		else {
			return;
		}
	}
	string getName()
	{
		return m_Name;
	}
	//获取年龄 
	int getAge() {
		m_Age = 0;
		return m_Age;
	}
	//设置hobby
	void sethobby(string hobby) {
		m_hobby = hobby;
	}
private:
	string m_Name; //可读可写 姓名
	int m_Age; //只读 年龄
	string m_hobby; //只写 hobby
};

int main4() {
	//通过圆类创建圆的对象。c1就是一个具体的圆。实例化
	Circle c1;
	c1.m_r = 10; //给圆对象的属性 进行赋值操作
	//2 * pi * 10 = = 62.8
	cout << "圆的周长为： " << c1.calculateZC() << endl;

	Student stu;
	stu.setName("zz");
	stu.setID(333);
	stu.showStudent();

	Person p;
	p.m_Name = "李四";
	//p.m_Car = "奔驰";  //保护权限类外访问不到
	//p.m_Password = 123; //私有权限类外访问不到
	p.func();

	//struct和class区别
	C3 c3;
	//c3.m_A = 10; //错误，class访问权限是私有
	C4 c4;
	c4.m_A = 10; //正确，struct访问权限是公共

	Person1 p1;
	//姓名设置
	p1.setName("zz");
	cout << "姓名： " << p1.getName() << endl;
	//年龄设置
	p1.getAge();
	cout << "年龄： " << p1.getAge() << endl;
	//情人设置
	p1.sethobby("tea");

	system("pause");
	return 0;
}