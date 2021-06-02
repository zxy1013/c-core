#include"point.h"

//只需要函数的所有实现
//设置x坐标 
//setX等函数写在cpp文件内表示全局函数，但事实上其为成员函数，所以需要定义作用域 Point::setX表示point作用域下的成员函数
void Point::setX(int x)
{
	p_x = x;
}
//获取x坐标
int Point::getX()
{
	return p_x;
}
//设置y坐标
void Point::setY(int y)
{
	p_y = y;
}
//获取y坐标
int Point::getY()
{
	return p_y;
}