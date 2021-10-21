#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m,q,i,j,cnt=0,cnt1=0,cnt2=0,l,r;
        cin>>n>>m>>q;
        long long a[n]={0},b[m]={0};
        while(q--)
        {
            cin>>l>>r;
            a[l-1]+=1;
            b[r-1]+=1;
        }
        for(i=0;i<n;i++)
        {
            if(a[i]%2==0)
                cnt2=cnt2+1;
            else
                cnt1=cnt1+1;
        }
        for(i=0;i<m;i++)
        {
            if(b[i]%2==0)
                cnt=cnt+cnt1;
            else
                cnt=cnt+cnt2;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
