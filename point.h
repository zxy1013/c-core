#pragma once
#include<iostream>
#include<string>
using namespace std;

//声明
class Point
{
public:
	//设置x坐标
	void setX(int x);
	//获取x坐标
	int getX();
	//设置y坐标
	void setY(int y);
	//获取y坐标
	int getY();
private:
	int p_x;
	int p_y;
};