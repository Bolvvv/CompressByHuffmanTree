#include "stdafx.h"
#include "HuffmanTree.h"

void HuffmanTree::Select(int cur, int & r1, int & r2)
{

}

void HuffmanTree::CreatHuffmanTree(char ch[], int w[], int n)
{
	num = n;   //Ҷ������
	int m = 2 * n - 1;  //������
	nodes = new HuffmanTreeNode [m + 1];  //����ռ�
	LeafChars = new char [n + 1];
	LeafCharCodes = new string[n + 1];

	for (int pos = 1; pos <= n; pos++)
	{   //��Ҷ�ӽ����Ϣ�洢
		nodes[pos].weight = w[pos - 1];  //Ȩֵ
		LeafChars[pos] = ch[pos - 1];   //�ַ�
	}

	for (int pos = n + 1; pos <= m; pos++)
	{   //������������
		int r1, r2;
		Select(pos - 1, r1, r2);  //��1��pos-1��ѡ��˫��Ϊ0��Ȩֵ��С���������
		nodes[r1].parent = nodes[r2].parent = pos;  //�ѽ��r1,r2��˫�׶���Ϊpos
		nodes[pos].leftChild = r1;  //��pos��������Ϊr1
		nodes[pos].rightChild = r2;  //��pos���Һ�����Ϊr2
		nodes[pos].weight = nodes[r1].weight + nodes[r2].weight;  //��˫�׵�Ȩֵ��Ϊ�����ӵ�Ȩֵ֮��
	}

	for (int pos = 1; pos <= n; pos++)
	{  //��n��Ҷ�ڵ��ַ��ı���
		string charCode;  //�ݴ�Ҷ����ַ�������Ϣ
		for (unsigned int child = pos, parent = nodes[child].parent; parent != 0; child = parent, parent = nodes[child].parent)
		{
			//��Ҷ�ӽ�㵽��������������
			if (nodes[parent].leftChild == child)
				charCode.insert(1, "0");  //������ʼ��Ϊ1��Ŀ����Ϊ�˽���������롱��Ϊ��������롱
			else charCode.insert(1, "1");
		}
		LeafCharCodes[pos] = charCode;  //charCode�д洢�ַ�����

	}
	curPos = m;        //����ʱ�Ӹ���㿪ʼ,mΪ��
}

HuffmanTree::HuffmanTree(char ch[], int w[], int n)
{
	CreatHuffmanTree(ch, w, n);
}

HuffmanTree::~HuffmanTree()
{

}

string HuffmanTree::Encode(char ch)
{
	for (int pos = 1; pos <= num; pos++)
	{
		//�����ַ���λ��
		if (LeafChars[pos] == ch) return LeafCharCodes[pos];
	}
	return "wrong";
}

string HuffmanTree::DeCode(string strCode)
{
	string charlist;  //����ǰ���ַ�����
	
	for (int pos = 0; pos < strCode.length(); pos++)
	{
		if (strCode[pos] == '0') curPos = nodes[curPos].leftChild;
		else curPos = nodes[curPos].rightChild;
		if (nodes[curPos].leftChild == 0 && nodes[curPos].rightChild == 0)
		{
			int len = charlist.length() + 1;
			charlist.insert(len, (char*) LeafChars[curPos]);   //����һ��Ī��������...
		}
	}
	return charlist;
}