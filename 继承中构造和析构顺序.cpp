#include<iostream>
using namespace std;

class Base2
{
public:
	Base2()
	{
		cout << "Base���캯��!" << endl;
	}
	~Base2()
	{
		cout << "Base��������!" << endl;
	}
};

class Son2 : public Base2
{
public:
	Son2()
	{
		cout << "Son���캯��!" << endl;
	}
	~Son2()
	{
		cout << "Son��������!" << endl;
	}
};

void test27()
{
	//�̳����ȵ��ø��๹�캯�����ٵ������๹�캯��������˳���빹���෴
	Son2 s;
}

int main24() {
	test27();//Base���캯��! Son���캯��! Son��������! Base��������!
	system("pause");
	return 0;
}