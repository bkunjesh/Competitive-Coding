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

ll n,m;
struct celeb
{
    ll t;
    ll x;
    ll y;
};
bool comp(celeb &a,celeb &b)
{
    return a.t<b.t;
}
ll dist(celeb a,celeb b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        cin>>m>>n;
        
        celeb a[n+1];
        vector<ll> dp(n+1,-1),prefix(n+1);

        a[0].t=0,a[0].x=1,a[0].y=1,dp[0]=0;

        rep(i,n)
        {
            cin>>a[i].t>>a[i].x>>a[i].y;
        }

        sort(a,a+n+1,comp);

        //rep(i,n) cout<<a[i].t<<a[i].x<<a[i].y<<endl;

        rep(i,n)
        {
            for(j=i-1;j>=0;j--)
            {

                if(a[i].t-a[j].t>=m+m)
                {
                    dp[i]=max(dp[i],prefix[j]+1);
                    break;
                }

                if(dp[j]!=-1&&a[i].t-a[j].t>=dist(a[i],a[j]))
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }

            }

            prefix[i]=max(prefix[i-1],dp[i]);

        }

        cout<<prefix[n]<<endl;
   
    }
return 0;
}