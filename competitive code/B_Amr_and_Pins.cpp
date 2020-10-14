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
    //cin >> t;
    while (t--)
    {
        ll r,x,y,nx,ny;cin>>r>>x>>y>>nx>>ny;
        double dist=sqrt((x-nx)*(x-nx)+(y-ny)*(y-ny));
        //cout<<dist<<" ";
        if(dist==0) 
        {
            cout<<0<<endl;
            return 0;
        }
        if(dist>r)
        {
            cout<<ceil((dist)/(2*r))<<endl;
        }
        else cout<<1<<endl;
    }
return 0;
}