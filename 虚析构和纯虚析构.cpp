#include<iostream>
using namespace std;

class Animal2 {
public:
	Animal2()
	{
		cout << "Animal ���캯�����ã�" << endl;
	}
	virtual void Speak() = 0;

	//������������virtual�ؼ��֣��������������
	//virtual ~Animal()
	//{
	//	cout << "Animal�������������ã�" << endl;
	//}

	//����ָ�����ͷ�ʱ�޷����õ�������������룬�ᵼ�����������������ɾ�������ڴ�й©
	//��ô���������������һ�����������������������������������ͨ������ָ���ͷ��������
	//�������������д���ʵ�֣����麯������Ҫ
	virtual ~Animal2() = 0;
};

Animal2::~Animal2()
{
	cout << "Animal���������������ã�" << endl;
}

//�Ͱ�����ͨ���麯������һ���������˴���������������Ҳ��һ�������ࡣ���ܹ���ʵ������
class Cat : public Animal2 {
public:
	Cat(string name)//���캯��
	{
		m_Name = new string(name);//����������
		cout << *m_Name<<"Cat���캯�����ã�" << endl;
	}
	void Speak()
	{
		cout << *m_Name << "Сè��˵��!" << endl;
	}
	~Cat()//��������
	{
		cout << "Cat������������!" << endl;
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
Animal ���캯�����ã�
TomCat���캯�����ã�
TomСè��˵��!
Cat������������!
Animal���������������ã�*/