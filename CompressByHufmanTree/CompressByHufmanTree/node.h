#pragma once
#include "stdafx.h"



struct HuffmanTreeNode
{
	int weight;   //权数据域
	int parent, leftChild, rightChild;  //双亲、左右孩子域
	HuffmanTreeNode();
	HuffmanTreeNode(int w, int p =0 , int lChild = 0, int rChild = 0);
};