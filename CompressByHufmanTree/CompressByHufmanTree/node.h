#pragma once
#include "stdafx.h"



struct HuffmanTreeNode
{
	int weight;   //Ȩ������
	int parent, leftChild, rightChild;  //˫�ס����Һ�����
	HuffmanTreeNode();
	HuffmanTreeNode(int w, int p =0 , int lChild = 0, int rChild = 0);
};