// CompressByHufmanTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "HuffmanTree.h"
#include <string>



int main()
{
	void getWord(int &count, int weight[], char ch[]);
	//进行字符相关信息的初始化
	int count = 0;//输入字符的种类数量
	int weight[256] = {};//字符权值
	char ch[256] = {};//字符信息
	getWord(count, weight, ch);

	//建树
	HuffmanTree tree(ch, weight, count);


	//测试
	cout << "请输入要编码的字符:" << endl;
	char a;
	string test;
	cin >> a;
	test = tree.Encode(a);
	cout << test << endl;
	system("PAUSE");
    return 0;
}

void getWord(int &count,int weight[],char ch[])
{
	string str;
	int ascii[256] = {};
	cout << "请输入一个字符串：";
	getline(cin, str);
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