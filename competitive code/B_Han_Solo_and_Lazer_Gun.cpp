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
        ll x0,y0;
        cin>>n>>x0>>y0;
        set<double> s,ver;
        f(i,n)
        {
            cin>>j>>k;
            double slop;
            if(x0-j!=0)
            {
                slop=(double)(y0-k)/(x0-j);
                s.insert(slop);
            }
            else
            {
                s.insert(inf);
            }
        }
        ll ans=s.size();
        cout<<ans<<endl;
    }
return 0;
}