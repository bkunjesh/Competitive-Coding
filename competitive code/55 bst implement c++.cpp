#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
		int data;
		node* left;
		node* right;
		node* createnewnode(int p)
		{
			node* newnode= new node;
			newnode->data=p;
			newnode->left=NULL;
			newnode->right=NULL;
			return newnode;			
		}
		
};
class bst
{
	public:
		node* root;
		bst()
		{
			root=NULL;
		}
		node* insert(node* root,int p)
		{
			
			if(root==NULL)
			{
				node t;
				root=t.createnewnode(p);
				return root;
			}
			if(root->data<p)
			root->right=insert(root->right,p);
			else
			root->left=insert(root->left,p);
		}
		void inorder(node* root)
		{
			if(root==NULL)
			return ;
			inorder(root->left);
			cout<<root->data<<" ";
			inorder(root->right);
		}
		bool search(node* root,int k)
		{
			if(root==NULL)
			return false;
			else if(root->data==k)
			return true;
			else if(root->data>k)
			return search(root->left,k);
			else 
			return search(root->right,k);
		}
		queue<int> kthsmall;
		void kthsmallestqueue(node* root)
		{
			if(root==NULL)
			return ;
			kthsmallestqueue(root->left);
			kthsmall.push(root->data);
			kthsmallestqueue(root->right); 			
		}
		void kthsmallest(int k)
		{
			kthsmallestqueue(root);
			for(int i=1;i<k;i++)
			{
				kthsmall.pop();
			}
			cout<<"kth smallest :"<<kthsmall.front()<<" ";
			while(!kthsmall.empty())
			{
				kthsmall.pop();
			}
		}
		node* lca(node* root,int a,int b)  // lowest common ancesstor
		{

			if(root==NULL)
			return root;
			else if((root->data<a&&root->data<b))
			    return lca(root->right,a,b);			
			else if((root->data>a&&root->data>b))
				return lca(root->left,a,b);			
			else return root;
			
			return root;			
		}
		int height(node* root)
		{
			if(root==NULL)			
			return -1;			
			else 
			return max(height(root->right),height(root->left))+1;
		}
		
};
int main()
{
	bst a;
	
	a.root=a.insert(a.root,10);
	a.insert(a.root,8);
	a.insert(a.root,12);
	a.insert(a.root,5);
	a.insert(a.root,9);
	a.insert(a.root,15);
	a.insert(a.root,3);
	a.inorder(a.root);
	cout<<endl;
	a.kthsmallest(3);
	cout<<endl;
	a.inorder(a.root);
	cout<<endl;
	a.kthsmallest(5);
	cout<<endl;
	cout<<"lca of a and b :"<<a.lca(a.root,5,3)->data<<" "<<endl;
	a.search(a.root,1)?cout<<"YES"<<endl:cout<<"NO"<<endl;
	cout<<a.height(a.root)<<endl;
}
