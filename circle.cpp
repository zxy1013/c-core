#include"circle.h"

//设置半径R
void Circle::setR(int r)
{
	R = r;
}
//获取半径R
int Circle::getR()
{
	return R;
}
//设置圆心
void Circle::setCenter(Point center)
{
	c_center = center;
}
//获取圆心
Point Circle::getCenter()//c_center是Piont类的数据
{
	return c_center;
}