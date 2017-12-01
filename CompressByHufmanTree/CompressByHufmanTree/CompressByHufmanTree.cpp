// CompressByHufmanTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "HuffmanTree.h"
#include <string>
#include <fstream>


void getWord(int &count, int weight[], char ch[], string str)
{
	int ascii[256] = {};
	for (int i = 0; i<str.size(); i++) {
		ascii[(int)str[i]]++;
	}
	for (int i = 0; i<256; i++)
		if (ascii[i] != 0) {
			weight[count] = ascii[i];
			ch[count] = (char)i;
			count++;
		}
}

int compress(int count, int weight[], char ch[])
{
	string finName;//输入文件名字
	string foutName;//输出文件 名字
	string fileStr;//输入文件的字符串
	string codeStr;//编码后的字符串
	cout << "请输入输入文件名字:";
	cin >> finName;
	cout << "请输入输出文件名字:";
	cin >> foutName;
	fstream fin(finName.c_str(), ios::in);
	fstream fout(foutName.c_str(), ios::out);
	if (fin.fail())
	{
		cout << "打开输入文件失败";
		return 0;
	}
	if (fout.fail())
	{
		cout << "打开输出文件失败";
		return 0;
	}
	fin >> fileStr;

	//字符初始化
	getWord(count, weight, ch, fileStr);

	//建树
	HuffmanTree tree(ch, weight, count);

	//编码
	for (int i = 0; i < fileStr.size(); i++)
	{
		codeStr += tree.Encode(fileStr[i]);
	}

	//输出字符种类数量、每个字符权值、字符信息、字符编码信息
	fout << count;
	for (int i = 0; i < count; i++)
	{
		fout << weight[i];
	}
	for (int i = 0; i < count; i++)
	{
		fout << ch[i];
	}
	fout << codeStr;//输出到输出文件


	//关闭输入输出文件
	fin.close();
	fout.close();
}

int main()
{
	int count = 0;//输入字符的种类数量
	int weight[256] = {};//字符权值
	char ch[256] = {};//字符信息
	int option;//操作序号
	cout << "1.压缩文件" << endl << "2.解压文件" << endl;
	cout << "请输入需要的进行的操序号:";
	cin >> option;
	while (option != 1 && option != 2)
	{
		cout << "输入错误,请重新输入:";
	}
	if (option == 1)
		if (compress(count, weight, ch) == 0)
		{
			cout << "打开文件出错" << endl;
		}
	else if (option == 2)
	{

	}
    return 0;
}



//多余代码
//进行字符相关信息的初始化
int count = 0;//输入字符的种类数量
int weight[256] = {};//字符权值
char ch[256] = {};//字符信息

//建树
