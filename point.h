#pragma once
#include<iostream>
#include<string>
using namespace std;

//����
class Point
{
public:
	//����x����
	void setX(int x);
	//��ȡx����
	int getX();
	//����y����
	void setY(int y);
	//��ȡy����
	int getY();
private:
	int p_x;
	int p_y;
};