#include<iostream>
using namespace std;

class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}
};
void test23()
{
	//����()������ Ҳ��Ϊ�º���
	MyPrint myFunc;
	myFunc.operator()("hello world");
	myFunc("hello world");
}

class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
void test24()
{
	MyAdd add;
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;
	//������������MyAdd()(100, 100) ��������MyAdd()
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100)<< endl;
}

int main20() {
	test23();
	test24();
	system("pause");
	return 0;
}