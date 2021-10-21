#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include <iostream> 
#include <iterator> 
#include <map> 

using namespace std;

int main()
{
	vector<string> s;
	string ele;
	cin>>ele;
	s.push_back(ele);
	cin>>ele;
	s.push_back(ele);
	cin>>ele;
	s.push_back(ele);
	/*vector<string>::iterator it;
	for(it=s.begin();it<s.end();it++)
	cout<<s[it-s.begin()][0]<<" "<<" "<<endl;*/
	cout<<&s[0]<<endl;
//	if(binary_search(&s[0],&s[0]+s[0].size(),'a'))
	cout<<s[0].size()<<endl;
	for(int i=0;i<s[0].size();i++)
	cout<<s[0][i]<<endl;
	
	
	/*map<char, int> m;
    map<char, int>::iterator it;
    for(int i=0;i<3;i++)
    {
        for(int j=0;s[i][j]!='\0';j++)
        {
            for(it = m.begin();it != m.end();it++)
            {
                if(s[i][j]==it->first)
                  it->second++;
                  //cout<<it->first<<" "<<it->second<<endl;
            }
            if(it==m.end())
            m.insert(pair<char,int>(s[i][j],1));
        
        }
    }
    for(it = m.begin();it != m.end();it++)
            {		
                  cout<<it->first<<" "<<it->second<<endl;
            }*/
}

