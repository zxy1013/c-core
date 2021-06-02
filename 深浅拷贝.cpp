#include<iostream>
using namespace std;

class Person5 {
public:
	Person5() {
		cout << "无参构造函数!" << endl;
	}
	Person5(int age, int height) {
		cout << "有参构造函数!" << endl;
		m_age = age;
		m_height = new int(height);
	}
	//若不定义拷贝构造函数，则编译器自定义浅拷贝。
	//拷贝构造函数  
	Person5(const Person5& p) {
		cout << "拷贝构造函数!" << endl;
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
		m_age = p.m_age;
		//m_height = p.m_height; //编译器默认实现为此行代码
		m_height = new int(*p.m_height);//堆区 深拷贝
	}
	//析构函数 将堆区开辟数据释放
	~Person5() {
		cout << "析构函数!" << endl;
		if (m_height != NULL)
		{
			delete m_height;//手动释放堆区数据
			m_height = NULL;
		}
	}
public:
	int m_age;
	int* m_height;
};

void test08()
{
	Person5 p1(18, 180);
	Person5 p2(p1);
	cout << "p1的年龄： " << p1.m_age << " 身高： " << *p1.m_height << endl;
	cout << "p2的年龄： " << p2.m_age << " 身高： " << *p2.m_height << endl;
}

int main9() {
	test08();
	system("pause");
	return 0;
}