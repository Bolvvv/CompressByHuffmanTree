#include "stdafx.h"
#include "HuffmanTree.h"

void HuffmanTree::Select(int cur, int & r1, int & r2)
{
	int min1 = 99999999999;//�����ַ��������Ϊ��
	int	min2 = 99999999999;
	int middleVar = 0;
	int middleI = 0;
	for (int i = 1; i <= cur; i++)
	{
		if (nodes[i].parent == 0)
		{
			if (min1 >= nodes[i].weight)
			{
				min1 = nodes[i].weight;
				r1 = i;
				middleI = i;
			}
		}
	}
	middleVar = min1;
	nodes[middleI].weight = 99999999999;
	for (int i = 1; i <= cur; i++)
	{
		if (nodes[i].parent == 0)
		{
			if (min2 >= nodes[i].weight)
			{
				min2 = nodes[i].weight;
				r2 = i;
			}
		}
	}
	nodes[middleI].weight = middleVar;
}

void HuffmanTree::CreatHuffmanTree(char ch[], int w[], int n)
{
	num = n;   //Ҷ������
	int m = 2 * n - 1;  //������
	nodes = new HuffmanTreeNode [m + 1];  //����ռ�
	LeafChars = new char [num + 1];
	LeafCharCodes = new string[num + 1];

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
				charCode = charCode + "0";
			else charCode = charCode + "1";
		}
		int len = charCode.length();//��charCode�ĳ���
		string midChar = "00000000000000000000000000000000000000000000000";//��Ϊ�м��������תcharCode
		for (int i = 0,m = len-1; i < len,m>=0; i++,m--)
		{
			midChar[i] = charCode[m];
		}
		for (int i = 0; i < len; i++)
		{
			LeafCharCodes[pos] = LeafCharCodes[pos]+midChar[i];  
		}

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
	int strCodeLength = strCode.length();
	for (int pos = 0; pos < strCodeLength; pos++)
	{
		if (strCode[pos] == '0') curPos = nodes[curPos].leftChild;
		else curPos = nodes[curPos].rightChild;
		if (nodes[curPos].leftChild == 0 && nodes[curPos].rightChild == 0)
		{
			int len = charlist.length() + 1;
			char change = LeafChars[curPos];
			charlist = charlist + change;
			curPos = 2 * num - 1;
		}
	}
	return charlist;
}
