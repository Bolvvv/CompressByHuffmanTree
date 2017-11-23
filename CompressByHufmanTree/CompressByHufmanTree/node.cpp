#include "stdafx.h"
#include "node.h"

HuffmanTreeNode::HuffmanTreeNode()
{

}

HuffmanTreeNode::HuffmanTreeNode(int w, int p, int lChild, int rChild)
{
	weight = w;
	parent = p;
	leftChild = lChild;
	rightChild = rChild;
}
