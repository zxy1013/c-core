#include<iostream>
#include<string>
using namespace std;

//������������
class Cube
{
private:
	//���� һ������Ϊ˽�� �����
	int m_L;
	int m_W;
	int m_H;
public:
	//���ó�
	void setL(int L)
	{
		m_L = L;
	}
	//��ȡ��
	int getL()
	{
		return m_L;
	}
	//���ÿ�
	void setW(int W)
	{
		m_W = W;
	}
	//��ȡ��
	int getW()
	{
		return m_W;
	}
	//���ø�
	void setH(int H)
	{
		m_H = H;
	}
	//��ȡ��
	int getH()
	{
		return m_H;
	}

	//��Ϊ 1����ȡ���������
	int getS()
	{
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}
	//��Ϊ 2����ȡ���������	
	int getV()
	{
		return m_L * m_W * m_H;
	}
	//��Ϊ 3�����ó�Ա�����ж������������Ƿ����
	bool isSame01(Cube& b)//ֻ��Ҫ����һ����������������ڵ���������бȽ�
	{
		if (m_L == b.getL() && m_W == b.getW() && m_H == b.getH())
			return true;
		else
			return false;
	}
};

//ȫ�ֺ���
bool isSame02(Cube a, Cube b)
{
	if (a.getL() == b.getL() && a.getW() == b.getW() && a.getH() == b.getH())
		return true;
	return false;
}

int main5()
{
	//����һ�����������
	Cube a1;
	a1.setL(10);
	a1.setW(10);
	a1.setH(10);
	cout << "������a1�����Ϊ��" << a1.getS() << endl;
	cout << "������a1�����Ϊ��" << a1.getV() << endl;
	Cube a2;
	a2.setL(10);
	a2.setW(10);
	a2.setH(12);
	cout << "������a1�����Ϊ��" << a2.getS() << endl;
	cout << "������a1�����Ϊ��" << a2.getV() << endl;

	//���ó�Ա�����ж������������Ƿ����
	bool flag = a2.isSame01(a1);
	if (flag)
		cout << "��Ա�����ж�:������a1��������a2���" << endl;
	else
		cout << "��Ա�����ж�:������a1��������a2�����" << endl;
	//����ȫ�ֺ����ж������������Ƿ����
	bool ret = isSame02(a1, a2);
	if (ret)
		cout << "ȫ�ֺ����ж�:������a1��������a2���" << endl;
	else
		cout << "ȫ�ֺ����ж�:������a1��������a2�����" << endl;

	system("pause");
	return 0;
}