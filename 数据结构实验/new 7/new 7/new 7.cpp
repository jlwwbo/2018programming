#include "pch.h"
#include <iostream>
class node
{
	friend class huffmanTree;
	int length;
	int cost;
	node* next;
public:
	node(int length=0,int cost=0):length(length),cost(cost),next(0){}
};
class huffmanTree
{
	node *headNode;
public:
	huffmanTree(){ headNode=new node; }
	void addnode(node* mynode);
	node* delfirst();
	void getHuffmanTree();
	int getans();
};
void huffmanTree::addnode(node* mynode)
{
	node *now=headNode->next,*pre=headNode;
	while(now!=NULL)
	{
		if(now->cost+now->length<mynode->cost+mynode->length)
		{
			pre=now;
			now=now->next;
		}
		else break;
	}
	pre->next=mynode;
	mynode->next=now;
	headNode->cost++;
}
node* huffmanTree::delfirst()
{
	if(headNode->cost<=0)
		return 0;
	node *ans=headNode->next;
	headNode->next=ans->next;
	headNode->cost--;
	return ans;
}
void huffmanTree::getHuffmanTree()
{
	node *first,*second;
	while(headNode->cost>1)
	{
		first=delfirst();
		second=delfirst();
		int totLength=first->length+second->length;
		node *newNode=new node(totLength,first->cost+second->cost+totLength);
		addnode(newNode);
	}
}
int huffmanTree::getans()
{
	if(headNode->cost<=0)
		return -1;
	else
		return headNode->next->cost;
}
int main()
{
	huffmanTree tree;
	node *nowNode;
	int n,length;
	std::cin>>n;
	for(int i=0; i<n; i++)
	{
		std::cin>>length;
		nowNode=new node(length);
		tree.addnode(nowNode);
	}
	tree.getHuffmanTree();
	std::cout<<tree.getans();
}
/*
8
4 5 1 2 1 3 1 1

3
8 7 5


*/
