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
        ll x,p;
        cin>>n>>x>>p>>k;        
        vector<ll> a(n+1);
        rep(i,n) cin>>a[i];
        sort(a.begin()+1,a.end());
        if(a[p]==x) 
        {
            cout<<0<<endl;
            continue;
        }
        if((k<p&&x<a[p])||(p<k&&x>a[p]))
        {
            cout<<-1<<endl;
            continue;
        }
        for(i=1;i<=n;i++) 
        {
            if(a[i]>=x) break;
        }
        if(i<=p) 
        {
            while(a[i]<=x) i++;
            i--;
        }
        ll ind=i;
        ll ans=abs(p-ind);
        cout<<ans<<endl;
    }
return 0;
}