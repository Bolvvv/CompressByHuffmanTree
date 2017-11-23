#pragma once
#include "stdafx.h"



struct HuffmanTreeNode
{
	int weight;   //权数据域
	int parent, leftChild, rightChild;  //双亲、左右孩子域
	HuffmanTreeNode();
};