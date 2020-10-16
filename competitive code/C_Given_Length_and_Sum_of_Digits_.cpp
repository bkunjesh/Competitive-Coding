//@bkunjesh
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;
bool can(ll m,ll s)
{
    return (s>=0&&s<=9*m);
}

int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        ll s,m;
        cin>>m>>s;
        
        string mn="",mx="";
        ll sum=s;
        // if(s>9*m||s<m)
        // {
        //     cout<<"-1 -1"<<endl;
        //     return 0;
        // }
        for(i=0;i<m;i++)
        {
            for(ll d=0;d<=9;d++)
            {
                if((i>0||d>0||(m==1&&d==0))&&can(m-i-1,sum-d))
                {
                    mn+=char('0'+d);
                    sum-=d;
                    break;
                }
            }
        }
        if(mn.size()!=m)
        {
            mn="-1";
        }
        sum=s;
        for(i=0;i<m;i++)
        {
            for(ll d=9;d>=0;d--)
            {
                if((i>0||d>0||(m==1&&d==0))&&can(m-i-1,sum-d))
                {
                    mx+=char('0'+d);
                    sum-=d;
                    break;
                }
            }
        }
        if(mx.size()!=m)
        {
            mx="-1";
        }

        cout<<mn<<" "<<mx<<endl;
        
    }
return 0;
}