#include"point.h"

//ֻ��Ҫ����������ʵ��
//����x���� 
//setX�Ⱥ���д��cpp�ļ��ڱ�ʾȫ�ֺ���������ʵ����Ϊ��Ա������������Ҫ���������� Point::setX��ʾpoint�������µĳ�Ա����
void Point::setX(int x)
{
	p_x = x;
}
//��ȡx����
int Point::getX()
{
	return p_x;
}
//����y����
void Point::setY(int y)
{
	p_y = y;
}
//��ȡy����
int Point::getY()
{
	return p_y;
}