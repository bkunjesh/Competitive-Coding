#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
struct bstnode{
	int data;
	bstnode* left;
	bstnode* right;
};

struct bstnode* root=NULL;

bstnode* getnewnode(int data)
{
	bstnode* newnode=new bstnode();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
bstnode* insert(struct bstnode* root,int data)
{
	if(root==NULL)
	{
		root=getnewnode(data);   //getnewnode return address of newnode
	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else if(data>root->data)
	{
		root->right=insert(root->right,data);
	}
	return root;
}
void levelorder(bstnode* root)  // breadth order traversal
{
	if(root==NULL)
	return;
	
	queue<bstnode*> q;
	q.push(root);
	while(!q.empty()){
		bstnode* current=q.front();
		if(current->left!=NULL)
		q.push(current->left);
		if(current->right!=NULL)
		q.push(current->right);
		cout<<current->data<<" ";
		q.pop();		
	}
}
void preorder(bstnode* root)  // <root> <left> <right>
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(bstnode* root)   //<left> <data> <right> *****for incresing sequnce use inorder traversal*****
{
	if(root==NULL)
	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(bstnode* root) //<left> <right> <data>
{
	if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
bstnode* findmin(bstnode* root)
{
	if(root->left==NULL)
	{
		//cout<<endl<<" min : "<<root->data;
		return root;
	}
	findmin(root->left);
}
bstnode* findmax(bstnode* root)
{
	if(root->right==NULL)
	{
		//cout<<endl<<" max : "<<root->data;
		return root;
	}
	findmax(root->right);
}
int height(bstnode* root)
{
	if(root==NULL)
	return -1;
	return max(height(root->left),height(root->right))+1;
}
bool search(bstnode* root,int data)
{
	if(root==NULL)	
	{
		cout<<endl<<data<<" not found";
		return 0;		
	}    
	else if(root->data==data)
	{
		cout<<endl<<data<<" found";	
		return 1;
	}
	else if(data<=root->data)
	search(root->left,data);
	else if(data>root->data)
	search(root->right,data);	
}
bstnode* datadelete(bstnode* root,int data)
{
	if(root==NULL)
	return root;
	else if(data>root->data)
	root->right=datadelete(root->right,data);
	else if(data<root->data)
	root->left =datadelete(root->left,data);
	else
	{
		//no child
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		//1 child
		else if(root->left==NULL)
		{
			bstnode* temp=root;
			root=root->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
			bstnode* temp=root;
			root=root->left;
			delete temp;
		}
		//2 child
		else
		{
				bstnode* temp=findmax(root->left);
				root->data=temp->data;
				root->left=datadelete(root->left,temp->data);
		}
	}
	return root;
}

int main()
{
	root=insert(root,7);
	insert(root,0);
	insert(root,9);
	insert(root,5);
	insert(root,2);
	insert(root,6);
	insert(root,4);
	cout<<"levelorder: ";
	levelorder(root);
	    cout<<endl<<"preorder: ";
	preorder(root);
		cout<<endl<<"inorder: ";
	inorder(root);
		cout<<endl<<"postorder: ";
	postorder(root);
	cout<<endl<<"min is : "<<findmin(root)->data;
	cout<<endl<<"max is : "<<findmax(root)->data;
	cout<<endl<<"height of tree : "<<height(root)<<endl;
	
	search(root,9);
	search(root,10);
	
	datadelete(root,7);
	
	cout<<endl<<endl<<"levelorder: ";
	levelorder(root);
	    cout<<endl<<"preorder: ";
	preorder(root);
		cout<<endl<<"inorder: ";
	inorder(root);
		cout<<endl<<"postorder: ";
	postorder(root);
	cout<<endl<<"min is : "<<findmin(root)->data;
	cout<<endl<<"max is : "<<findmax(root)->data;
	cout<<endl<<"height of tree : "<<height(root)<<endl;
	
	
    return 0;
}
