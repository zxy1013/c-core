#include<iostream>
using namespace std;

class Animal
{
public:
	int m_Age;
};

//������̳п��Խ�����μ̳У���Ϊ����̳еĲ������������ݣ���������ָ�룬ͨ��ƫ��������ָ��ͬһ�����ݣ������޸�ʱ�����һ��Ϊ׼
//�̳�ǰ��virtual�ؼ��ֺ󣬱�Ϊ��̳С���ʱ�����ĸ���Animal��Ϊ�����
//����
class Sheep : virtual public Animal {};
//����
class Tuo : virtual public Animal {};
//������
class SheepTuo : public Sheep, public Tuo {};

void test32()
{
	SheepTuo st;
	st.Sheep::m_Age = 100;
	st.Tuo::m_Age = 200;//�����һ��Ϊ׼���ҿ��Բ�д������
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;//200
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;//200
	cout << "st.m_Age = " << st.m_Age << endl;//200
}

int main28() {
	test32();
	system("pause");
	return 0;
}