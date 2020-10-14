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
    ll t = 1, i, j;
    cin >> t;
    while (t--)
    {
        cin>>n;
        vector<ll> a(n);
        for(i=0;i<n;i++) cin>>a[i];

        ll cnt=0;

        for(i=0;i<n-1;i++)
        {
            if(a[i]<=a[i+1])
            {
                break;
            }
        }
        if(i==n-1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
    }
return 0;
}