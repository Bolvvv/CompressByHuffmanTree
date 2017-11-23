#pragma once
#include "stdafx.h"
#include "node.h"
using namespace std;

class HuffmanTree
{
protected:
	HuffmanTreeNode *nodes;  //结点信息
	char * LeafChars;  //叶结点信息
	string *LeafCharCodes;  //叶节点字符编码信息
	int curPos;  //译码时从根结点到叶结点路径的当前结点
	int num;     //叶结点个数


//辅助函数
	void Select(int cur, int &r1, int &r2);
	//nodes[1-cur]中选择双亲为0，权值最小的两个结点r1,r2
	void CreatHuffmanTree(char ch[], int w[], int n);
	//由字符，权值和字符个数构造哈夫曼树
public:
	HuffmanTree(char ch[], int w[], int n);
	virtual~HuffmanTree();
	string Encode(char ch);  //编码
	string DeCode(string strCode);  //译码
};