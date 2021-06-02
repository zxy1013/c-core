#include<iostream>
using namespace std;

class Animal2 {
public:
	Animal2()
	{
		cout << "Animal 构造函数调用！" << endl;
	}
	virtual void Speak() = 0;

	//析构函数加上virtual关键字，变成虚析构函数
	//virtual ~Animal()
	//{
	//	cout << "Animal虚析构函数调用！" << endl;
	//}

	//父类指针在释放时无法调用到子类的析构代码，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数。虚析构函数就是用来解决通过父类指针释放子类对象
	//纯虚析构必须有代码实现，纯虚函数不需要
	virtual ~Animal2() = 0;
};

Animal2::~Animal2()
{
	cout << "Animal纯虚析构函数调用！" << endl;
}

//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
class Cat : public Animal2 {
public:
	Cat(string name)//构造函数
	{
		m_Name = new string(name);//创建到堆区
		cout << *m_Name<<"Cat构造函数调用！" << endl;
	}
	void Speak()
	{
		cout << *m_Name << "小猫在说话!" << endl;
	}
	~Cat()//析构函数
	{
		cout << "Cat析构函数调用!" << endl;
		if (this->m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}
public:
	string* m_Name;
};

void test38()
{
	Animal2* animal = new Cat("Tom");
	animal->Speak();
	delete animal;
}

int main33() {
	test38();
	system("pause");
	return 0;
}
/*
Animal 构造函数调用！
TomCat构造函数调用！
Tom小猫在说话!
Cat析构函数调用!
Animal纯虚析构函数调用！*/