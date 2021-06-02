#include <fstream>
#include<iostream>
#include <string>
using namespace std;

void test40()
{
	ofstream ofs;//创建流对象
	ofs.open("test.txt", ios::out);//打开文件 项目目录
	ofs << "姓名：张三" << endl;//写文件
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	ofs.close();//关闭文件
}

void test41()
{
	ifstream ifs;//创建流对象
	ifs.open("test.txt", ios::in);//判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	////第一种读取方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf)//读到头返回假
	//{
	//	cout << buf << endl;
	//}

	////第二种
	//char buf1[1024] = { 0 };
	//while (ifs.getline(buf1,sizeof(buf1)))//数据放入字符数组，最大读取sizeof(buf)长
	//{
	//	cout << buf1 << endl;
	//}

	////第三种
	//string buf2;
	//while (getline(ifs, buf2))
	//{
	//	cout << buf2 << endl;
	//}

	//第四种 太慢
	char c;
	while ((c = ifs.get()) != EOF)//没有读到文件尾
	{
		cout << c;
	}
	ifs.close();//关闭文件
}
int main35() {
	//test40();
	test41();
	system("pause");
	return 0;
}