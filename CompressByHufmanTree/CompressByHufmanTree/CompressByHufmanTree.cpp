// CompressByHufmanTree.cpp : �������̨Ӧ�ó������ڵ㡣
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
	string finName;//�����ļ�����
	string foutName;//����ļ� ����
	string fileStr;//�����ļ����ַ���
	string codeStr;//�������ַ���
	cout << "�����������ļ�����:";
	cin >> finName;
	cout << "����������ļ�����:";
	cin >> foutName;
	fstream fin(finName.c_str(), ios::in);
	fstream fout(foutName.c_str(), ios::out);
	if (fin.fail())
	{
		cout << "�������ļ�ʧ��";
		return 0;
	}
	if (fout.fail())
	{
		cout << "������ļ�ʧ��";
		return 0;
	}
	fin >> fileStr;

	//�ַ���ʼ��
	getWord(count, weight, ch, fileStr);

	//����
	HuffmanTree tree(ch, weight, count);

	//����
	for (int i = 0; i < fileStr.size(); i++)
	{
		codeStr += tree.Encode(fileStr[i]);
	}

	//����ַ�����������ÿ���ַ�Ȩֵ���ַ���Ϣ���ַ�������Ϣ
	fout << count;
	for (int i = 0; i < count; i++)
	{
		fout << weight[i];
	}
	for (int i = 0; i < count; i++)
	{
		fout << ch[i];
	}
	fout << codeStr;//���������ļ�


	//�ر���������ļ�
	fin.close();
	fout.close();
}

int main()
{
	int count = 0;//�����ַ�����������
	int weight[256] = {};//�ַ�Ȩֵ
	char ch[256] = {};//�ַ���Ϣ
	int option;//�������
	cout << "1.ѹ���ļ�" << endl << "2.��ѹ�ļ�" << endl;
	cout << "��������Ҫ�Ľ��еĲ����:";
	cin >> option;
	while (option != 1 && option != 2)
	{
		cout << "�������,����������:";
	}
	if (option == 1)
		if (compress(count, weight, ch) == 0)
		{
			cout << "���ļ�����" << endl;
		}
	else if (option == 2)
	{

	}
    return 0;
}



//�������
//�����ַ������Ϣ�ĳ�ʼ��
int count = 0;//�����ַ�����������
int weight[256] = {};//�ַ�Ȩֵ
char ch[256] = {};//�ַ���Ϣ

//����
