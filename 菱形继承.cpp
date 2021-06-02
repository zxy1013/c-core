#include<iostream>
using namespace std;

class Animal
{
public:
	int m_Age;
};

//利用虚继承可以解决菱形继承，因为子类继承的不再是两份数据，而是两个指针，通过偏移量可以指向同一份数据，所以修改时以最后一次为准
//继承前加virtual关键字后，变为虚继承。此时公共的父类Animal称为虚基类
//羊类
class Sheep : virtual public Animal {};
//驼类
class Tuo : virtual public Animal {};
//羊驼类
class SheepTuo : public Sheep, public Tuo {};

void test32()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;//以最后一次为准，且可以不写作用域
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;//200
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;//200
	cout << "st.m_Age = " << st.m_Age << endl;//200
}

int main28() {
	test32();
	system("pause");
	return 0;
}