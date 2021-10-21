#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
int main()
{
    long int t,n,j,i,m,element,min;
    vector<pair<long int,long int>> cpy;
     cin>>t;
     while(t--)
    {
       min=1000000000;
        cin>>n>>m;
        j=1;
        for(i=0;i<n;i++)
        {
            cin>>element;
            cpy.push_back(make_pair(element,j));
            if(j==m)
            j=0;
            j++;
        }
        sort(cpy.begin(),cpy.end());
        for(int i=m-1;i<n;i++)
        {
        	long int m_sum=0;
        	for(int j=i-m+1;j<=i;j++)
        	{
        		m_sum+=cpy[j].second;
			}
			if(m_sum==(m*(m+1)/2))
			{
				if(min>=cpy[i].first-cpy[i-m+1].first)
				min=cpy[i].first-cpy[i-m+1].first;
			}
		}	   
        cout<<min<<endl;
        cpy.clear();
    }    

    return 0;
}
