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
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        ll ans=0;
        ans+=abs(x2-x1);
        if(ans!=0&&abs(y1-y2)!=0) ans+=2;
        ans+=abs(y1-y2);
        cout<<ans<<endl;
        
    }
return 0;
}