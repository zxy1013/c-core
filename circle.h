#pragma once //��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
#include"point.h" //�������������point����
using namespace std;

//���һ��Բ��Circle
class Circle
{
public:
	//���ð뾶R
	void setR(int r);
	//��ȡ�뾶R
	int getR();
	void setCenter(Point center);
	//��ȡԲ��
	Point getCenter();
private:
	int R;
	//�����п�������һ���� ��Ϊ�����еĳ�Ա--��ṹ������
	Point c_center;
};