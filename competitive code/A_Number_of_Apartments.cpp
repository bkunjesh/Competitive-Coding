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

int main()
{
    fast
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        cin>>n;
        ll no=0,flag=0,x,y,z;
        for(x=0;3*x<=n;x++)
        {
            no=3*x;
            for(y=0;3*x+5*y<=n;y++)
            {
                no=3*x+5*y;
                for(z=0;no<=n;z++)
                {
                    no=3*x+5*y+7*z;
                   // cout<<no<<" ";
                    if(no==n)
                    {
                        flag=1;
                        break;
                    }
                }
                //no=0;
                if(flag) break;
            }
           // no=0;
            if(flag) break;
        }
        if(flag)
        cout<<x<<" "<<y<<" "<<z<<endl;
        else cout<<-1<<endl;
    }
return 0;
}