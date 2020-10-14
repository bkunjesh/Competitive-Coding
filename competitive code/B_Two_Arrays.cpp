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
        cin>>n>>k;
        vector<ll> a(n);
        f(i,n) cin>>a[i];
        ll color[n+1];
        map<ll,ll> m;
        for(i=0;i<n;i++)
        {
            if(m.count(k-a[i]))
            {
                color[i]=!color[m[k-a[i]]];
                m[a[i]]=i;
            }
            else
            {
                m[a[i]]=i;
                color[i]=0;
            }            
        }
        f(i,n) cout<<color[i]<<" ";
        cout<<endl;
    }
return 0;
}