#pragma once
#include "stdafx.h"



struct HuffmanTreeNode
{
	int weight;   //Ȩ������
	int parent, leftChild, rightChild;  //˫�ס����Һ�����
	HuffmanTreeNode();
};