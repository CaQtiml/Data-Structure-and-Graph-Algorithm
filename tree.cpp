#include "bits/stdc++.h"
using namespace std;
#define godkhing printf("\n");
typedef struct node{
	int data;
	node *l , *r ;
}node;

node *newnode(int x)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->data = x;
	tmp->l = NULL;
	tmp->r = NULL;
	return tmp ;
}

// Depth First Transversal
void printpreorder(node *n)
{
	if(n==NULL) return;
	cout << n->data << " " ;
	printpreorder(n->l);
	printpreorder(n->r);
}

void printinorder(node *n)
{
	if(n==NULL) return;
	printinorder(n->l);
	cout << n->data << " " ;
	printinorder(n->r);
}

void printpostorder(node *n)
{
	if(n==NULL) return;
	printpostorder(n->l);
	printpostorder(n->r);
	cout << n->data << " ";
}
//The end of Depth First Transversal

//Breadth First Transversal
void printlevelorder(node *root)
{
	queue<node*> q;
	if(root==NULL) return;
	q.emplace(root);
	while(!q.empty())
	{
		node *n = q.front() ;
		cout << n->data <<" " ;
		q.pop();
		if(n->l != NULL)
		{
			q.push(n->l);
		}
		if(n->r != NULL)
		{
			q.push(n->r);
		}
	}
}
//The end of Breadth First Transversal

int main()
{
	node *root = newnode(1) ;
	root->l = newnode(2);
	root->r = newnode(3);
	root->l->l = newnode(4);
	root->l->r = newnode(5);
	printpreorder(root); //root left right
	godkhing
	printinorder(root); //left root right
	godkhing
	printpostorder(root); //left right root
	godkhing
	printlevelorder(root);
}