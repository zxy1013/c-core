#include<iostream>
using namespace std;
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //˽�г�Աֻ�Ǳ������������ˣ����ǻ��ǻᱻ�̳���ȥ
};
//�����̳� �����е����зǾ�̬��Ա���ᱻ����̳���ȥ
class Son :public Base
{
public:
	int m_D;
};
void test26()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;//16
}
int main23() {
	test26();
	system("pause");
	return 0;
}