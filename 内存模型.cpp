#include<iostream>
using namespace std;

//ȫ�ֱ���:���ں������ڵı���
int g_a = 10;
int g_b = 10;

//ȫ�ֳ���
const int c_g_a = 10;
const int c_g_b = 10;

//ջ����
int* func(int b)//�β�����Ҳ�����ջ��
{
	b = 100;
	int a = 10; //�����ֲ�����
	return &a; //���ؾֲ������ĵ�ַ�������ԣ�����
	//return &b; //�����βεĵ�ַ�������ԣ�����
}

//���� ����new�ڶ��������ڴ�
int* func1()
{
	//ָ�뱾��Ϊ�ֲ����� ����ջ����ָ�뱣������ݷ����˶���
	int* a = new int(10); //�������½�int=10  ��������* a = new ��������(ֵ)
	cout << "*****�� " << &a << endl; //005EFB58 //ָ���ջ����ַ
	cout << "*****�� " << a << endl; //0099B650 //ָ��Ķ�����ַ
	cout << "*****�� " << *a << endl; //10 //����������
	return a; //���ض����ĵ�ַ
}

int main1() {
	
	//�����ֲ�����
	int a = 10;
	int b = 10;
	cout << "�ֲ�����a��ַΪ�� " << &a << endl; //003EFD9C
	cout << "�ֲ�����b��ַΪ�� " << &b << endl;
	cout << "ȫ�ֱ���g_a��ַΪ�� " << &g_a << endl;//004AC000
	cout << "ȫ�ֱ���g_b��ַΪ�� " << &g_b << endl;
	
	//��̬���� ����ͨ����ǰ���static
	static int s_a = 10;
	static int s_b = 10;
	cout << "��̬����s_a��ַΪ�� " << &s_a << endl; //004AC008
	cout << "��̬����s_b��ַΪ�� " << &s_b << endl;
	cout << "�ַ���������ַΪ�� " << &"hello world" << endl;//004A9BF4
	cout << "�ַ���������ַΪ�� " << &"hello world1" << endl;
	cout << "ȫ�ֳ���c_g_a��ַΪ�� " << &c_g_a << endl;//004A9B30
	cout << "ȫ�ֳ���c_g_b��ַΪ�� " << &c_g_b << endl;
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "�ֲ�����c_l_a��ַΪ�� " << &c_l_a << endl;//003EFD84
	cout << "�ֲ�����c_l_b��ַΪ�� " << &c_l_b << endl;


	//ջ�����ٵ������ɱ������Զ��ͷ�
	int a1 = 1;
	int* p = func(a1);
	cout << *p << endl; //��һ�ο��Դ�ӡ��ȷ�����ݣ�����Ϊ����������һ�α���
	cout << *p << endl; //������룬��Ϊ���������ٱ���


	//���� �������ʱ�ɲ���ϵͳ���ա�
	int* p1 = func1();
	cout << *p1 << endl; //��һ�ο��Դ�ӡ��ȷ�����ݣ�����Ϊ����������һ�α���
	cout << *p1 << endl; //������룬��Ϊ���������ٱ���
	//����delete �������ͷŶ�������
	delete p1;
	//cout << *p1 << endl; //�����ͷŵĿռ䲻�ɷ��ʡ���ȡ����Ȩ�޳�ͻ
	

	//���� ����new�ڶ����������� 10����������10��Ԫ�� ���������ַ
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100; //�������
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;//��ӡ����
	}
	//�ͷ����� delete[] ���������
	delete[] arr;
	/*for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;//��ӡ����
	}*/

	system("pause");
	return 0;
}