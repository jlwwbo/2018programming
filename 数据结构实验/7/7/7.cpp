#include "pch.h"
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
class extendedNode
{
	friend class huffmanTree;
	int key;
	extendedNode *left,*right;
public:
	extendedNode(int key,extendedNode* left,extendedNode* right):key(key),left(left),right(right){}
	int key(){ return key; }
	bool operator<(extendedNode &another);
};

class huffmanTree
{
	priority_queue<extendedNode,vector<extendedNode>,greater<extendedNode>> tree;
public:
	void operator>>(extendedNode &node);
	extendedNode& getHuffmanTree();
	int operator<<();
};
bool extendedNode::operator<(extendedNode &another)
{
	return this->key<another.key;
}
void huffmanTree::operator>>(extendedNode &node)
{
	tree.enqueue(node);
}
extendedNode& huffmanTree::getHuffmanTree()
{
	int first,second;
	while(tree.size()>1)
	{
		first=tree.dequeue();
		second=tree.dequeue();
		extendedNode newnode(first.key()+seconde.key(),first,second);
		tree.enqueue(newNode);
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
}