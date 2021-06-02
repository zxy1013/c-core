#pragma once //防止头文件重复包含
#include<iostream>
#include<string>
#include"point.h" //必须包含，否则point报错
using namespace std;

//设计一个圆类Circle
class Circle
{
public:
	//设置半径R
	void setR(int r);
	//获取半径R
	int getR();
	void setCenter(Point center);
	//获取圆心
	Point getCenter();
private:
	int R;
	//在类中可以让另一个类 作为本类中的成员--与结构体相似
	Point c_center;
};