#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
#define ull unsigned long long
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
int main()
{
	fast
	int n=4;//cin>>n;
	set< string > s;
	s.insert("yes");
	s.insert("abcd");
	s.insert("kunjesh");
	s.insert("abcz");
	sort(s.begin(),s.end());
	cout<<*(--s.end());

	
	return 0;
}
