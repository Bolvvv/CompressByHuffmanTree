#pragma once
#include "stdafx.h"
#include "node.h"
using namespace std;

class HuffmanTree
{
protected:
	HuffmanTreeNode *nodes;  //�����Ϣ
	char * LeafChars;  //Ҷ�����Ϣ
	string *LeafCharCodes;  //Ҷ�ڵ��ַ�������Ϣ
	int curPos;  //����ʱ�Ӹ���㵽Ҷ���·���ĵ�ǰ���
	int num;     //Ҷ������


//��������
	void Select(int cur, int &r1, int &r2);
	//nodes[1-cur]��ѡ��˫��Ϊ0��Ȩֵ��С���������r1,r2
	void CreatHuffmanTree(char ch[], int w[], int n);
	//���ַ���Ȩֵ���ַ����������������
public:
	HuffmanTree(char ch[], int w[], int n);
	virtual~HuffmanTree();
	string Encode(char ch);  //����
	string DeCode(string strCode);  //����
};