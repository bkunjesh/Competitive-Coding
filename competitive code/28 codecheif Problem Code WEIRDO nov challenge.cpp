#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include <iostream> 
#include <iterator> 
#include <map> 
#include<math.h>

using namespace std;

int checkper(string s)
{
    int vowel=0,consonant=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='a'||s[i]=='i'||s[i]=='e'||s[i]=='o'||s[i]=='u')
        vowel++;
        else
        consonant++;
    }
    // cout<<vowel<<" "<<consonant<<"   ";
    if(vowel>=consonant)
    return 1;
    else 
    return 0;
}
float score(vector<string> s,int n)
{
    map<char, int> m,x;
    map<char, int>::iterator it,it1;
    int k=0;    
    for(int i=0;i<n;i++)
    {
    	
        for(int j=0;s[i][j]!='\0';j++)
        {        
            for(it = m.begin();it != m.end();it++)
            {
            
                if(s[i][j]==it->first)
                {
                    it->second++;         //increment count of perticular or repeating element
                }
            }
            if(it==m.end())   //add new element map
            m.insert(pair<char,int>(s[i][j],1));
        
        }
    }
    for(it = m.begin();it !=m.end();it++)
    {
        for(int k=0;k<s.size();k++)
        {
        	//it1=s[k].find(it->first);
        	 size_t found = s[k].find(it->first);
            if(found !=string::npos)
            {
                it1=x.find(it->first);
                if(it1 !=x.end())
                it1->second++;
                else
                x.insert(pair<char,int>(it->first,1));
            }
            
        }
    }
    //for(it=x.begin();it!=x.end();it++)
    //cout<<it->first<<" "<<it->second<<endl;
    float numinator=1,denominator=1;
    it1 = x.begin();
    for(it = m.begin();it !=m.end();it++)
    {
        denominator*=pow(it->second,n);
        numinator*=it1->second;
        it1++;
    }
    
    return numinator/denominator;
}
int main()
{
    int t,l;
    bool person;
     cin>>t;
     while(t--)
    {
        cin>>l;
        cout<<std::fixed;
        cout<<std::setprecision(7);
        vector<string> s,alice,bob;
        string ele;
        long int product1=1,product2=1;
        for(int i=0;i<l;i++)
        {
            cin>>ele;
            s.push_back(ele);
      //      cout<<s[i]<<" ";
            person=checkper(s[i]);
            if(person)
            alice.push_back(ele);
            else
            bob.push_back(ele);
        }
        if(score(alice,alice.size())/score(bob,bob.size())>pow(10,7))
        cout<<"Infinity"<<endl;
        else
        cout<<score(alice,alice.size())/score(bob,bob.size())<<endl;
    }    

    return 0;
}
