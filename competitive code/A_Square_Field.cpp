#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;

int main()
{
    fast
    ll t = 1, i, j,k;
    //cin >> t;
    while (t--)
    {
        ll l,x,y;
        cin>>l>>x>>y;
        ll len=max(l-y,y-1),ht=max(l-x,x-1);

        cout<<max(len,ht)*max(len,ht)<<endl;
    }
return 0;
}