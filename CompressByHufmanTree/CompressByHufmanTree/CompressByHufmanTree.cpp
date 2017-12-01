// CompressByHufmanTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "HuffmanTree.h"
#include <string>



int main()
{
	string str;
	cout << "������һ���ַ�����";
	getline(cin, str);
	void getWord(int &count, int weight[], char ch[],string str);
	//�����ַ������Ϣ�ĳ�ʼ��
	int count = 0;//�����ַ�����������
	int weight[256] = {};//�ַ�Ȩֵ
	char ch[256] = {};//�ַ���Ϣ
	getWord(count, weight, ch,str);

	//����
	HuffmanTree tree(ch, weight, count);


	//����
	char a;
	string test;
	for (int i = 0; i < str.size(); i++)
	{
		a = str[i];
		test = test+tree.Encode(a);
	}
	cout << test << endl;
	system("PAUSE");
    return 0;
}

void getWord(int &count,int weight[],char ch[],string str)
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