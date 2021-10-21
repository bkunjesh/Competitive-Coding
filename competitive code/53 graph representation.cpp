#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void addeddge(vector<int> a[],int n,int m)
{
	a[n].push_back(m);
	a[m].push_back(n);
}
void print(vector<int> a[],int v)
{
	
	for(int i=0;i<v;i++)
	{
		cout<<i;
		 for (vector<int>::iterator x =a[i].begin();x!=a[i].end();x++) 
           cout << "-> " << *x; 
        printf("\n");
	}
}
int main()
{
	int v=5;
	vector<int> a[v];
	addeddge(a,0,1);
	addeddge(a,1,3);
	addeddge(a,0,4);
	addeddge(a,1,4);
	addeddge(a,3,0);
	addeddge(a,2,4);
	addeddge(a,2,3);
	print(a,v);
}
