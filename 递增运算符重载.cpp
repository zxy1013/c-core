#include<iostream>
using namespace std;

class MyInteger {//�Զ�������
	friend ostream& operator<<(ostream& out, MyInteger myint);//��Ԫ
public:
	MyInteger() {
		m_Num = 0;
	}
	//����ǰ��++ ����������Ϊ��һֱ��һ�����ݽ��в���
	MyInteger& operator++() {
		//��++
		m_Num++;
		//�ٷ���
		return *this;
	}
	//���غ���++ ��int����ռλ������������������ǰ�úͺ��õ��� ����ֵ����Ϊ�ֲ��������ͷţ���ֹ�Ƿ����������Բ�������ʽ����
	MyInteger operator++(int) {
		//�ȷ���
		MyInteger temp = *this; //��¼��ǰ�����ֵ��Ȼ���ñ����ֵ��1�����Ƿ��ص�����ǰ��ֵ���ﵽ�ȷ��غ�++��
		m_Num++;
		return temp;
	}
private:
	int m_Num;
};
//�Զ������������
ostream& operator<<(ostream& out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}
void test20() {
	MyInteger myInt;
	cout << ++(++myInt) << endl;
	cout << myInt << endl;
	MyInteger myInt1;
	cout << myInt1++ << endl;
	cout << myInt1 << endl;
}

int main17() {
	int a = 1;
	test20();
	system("pause");
	return 0;
}