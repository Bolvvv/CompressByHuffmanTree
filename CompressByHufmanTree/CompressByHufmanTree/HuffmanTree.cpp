#include "stdafx.h"
#include "HuffmanTree.h"

void HuffmanTree::Select(int cur, int & r1, int & r2)
{
	int max1, max2;
	//初始化max1,max2
	for (int i = 1; i <= cur; i++)
	{
		if (nodes[i].parent == 0)
		{
			max1 = nodes[i].weight;
			max2 = nodes[i].weight;
			r1 = i;
			r2 = i;
			break;
		}
	}
	//找到最大值，并将其标号赋值给r1
	for (int i = 1; i <= cur; i++)
	{
		if(nodes[i].parent == 0)
		{
			if (max1 >= nodes[i].weight)
			{
				max1 = nodes[i].weight;
				r1 = i;
			}
		}
	}
	//找到次大或最大值，将其标号赋值给r2
	for (int i = 1; i <= cur; i++)
	{
		if (nodes[i].parent == 0)
		{
			if (i == r1)
			{
				continue;
			}
			if (max2 >= nodes[i].weight)
			{
				max2 = nodes[i].weight;
				r2 = i;
			}
		}
	}
}

void HuffmanTree::CreatHuffmanTree(char ch[], int w[], int n)
{
	num = n;   //叶结点个数
	int m = 2 * n - 1;  //结点个数
	nodes = new HuffmanTreeNode [m + 1];  //申请空间
	LeafChars = new char [n + 1];
	LeafCharCodes = new string[n + 1];

	for (int pos = 1; pos <= n; pos++)
	{   //将叶子结点信息存储
		nodes[pos].weight = w[pos - 1];  //权值
		LeafChars[pos] = ch[pos - 1];   //字符
	}

	for (int pos = n + 1; pos <= m; pos++)
	{   //建立哈夫曼树
		int r1, r2;
		Select(pos - 1, r1, r2);  //从1到pos-1中选择双亲为0，权值最小的两个结点
		nodes[r1].parent = nodes[r2].parent = pos;  //把结点r1,r2的双亲都设为pos
		nodes[pos].leftChild = r1;  //把pos的左孩子设为r1
		nodes[pos].rightChild = r2;  //把pos的右孩子设为r2
		nodes[pos].weight = nodes[r1].weight + nodes[r2].weight;  //将双亲的权值设为俩孩子的权值之和
	}

	for (int pos = 1; pos <= n; pos++)
	{  //求n个叶节点字符的编码
		string charCode;  //暂存叶结点字符编码信息
		for (unsigned int child = pos, parent = nodes[child].parent; parent != 0; child = parent, parent = nodes[child].parent)
		{
			//从叶子结点到根结点逆向求编码
			if (nodes[parent].leftChild == child)
				charCode.insert(1, "0");  //设置起始点为1的目的是为了将“倒叙编码”改为“逆序编码”
			else charCode.insert(1, "1");
		}
		LeafCharCodes[pos] = charCode;  //charCode中存储字符编码

	}
	curPos = m;        //译码时从根结点开始,m为根
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
		//查找字符的位置
		if (LeafChars[pos] == ch) return LeafCharCodes[pos];
	}
	return "wrong";
}

string HuffmanTree::DeCode(string strCode)
{
	string charlist;  //编码前的字符序列
	int strCodeLength = strCode.length();
	for (int pos = 0; pos < strCodeLength; pos++)
	{
		if (strCode[pos] == '0') curPos = nodes[curPos].leftChild;
		else curPos = nodes[curPos].rightChild;
		if (nodes[curPos].leftChild == 0 && nodes[curPos].rightChild == 0)
		{
			int len = charlist.length() + 1;
			charlist.insert(len, (const char*) LeafChars[curPos]);   //出现一个莫名的问题...
		}
	}
	return charlist;
}
