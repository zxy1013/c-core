#include"circle.h"

//���ð뾶R
void Circle::setR(int r)
{
	R = r;
}
//��ȡ�뾶R
int Circle::getR()
{
	return R;
}
//����Բ��
void Circle::setCenter(Point center)
{
	c_center = center;
}
//��ȡԲ��
Point Circle::getCenter()//c_center��Piont�������
{
	return c_center;
}