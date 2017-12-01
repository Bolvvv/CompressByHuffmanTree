// CompressByHufmanTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "HuffmanTree.h"
#include <string>



int main()
{
	void getWord(int &count, int weight[], char ch[]);
	//�����ַ������Ϣ�ĳ�ʼ��
	int count = 0;//�����ַ�����������
	int weight[256] = {};//�ַ�Ȩֵ
	char ch[256] = {};//�ַ���Ϣ
	getWord(count, weight, ch);

	//����
	HuffmanTree tree(ch, weight, count);


	//����
	cout << "������Ҫ������ַ�:" << endl;
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
	cout << "������һ���ַ�����";
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