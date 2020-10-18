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
        string s;cin>>s;
        vector<ll> a(s.size());
        ll mx=0;
        i=0;
        for(auto it:s)
        {
            a[i]=it-'0';
            mx=max(mx,a[i++]);
        }
        cout<<mx<<endl;
        while(mx--)
        {
            ll flag=0;
            for(i=0;i<a.size();i++)
            {
                if(a[i]>0) flag=1;
                if(flag)
                {
                    cout<<(a[i]>0);
                    a[i]--;
                }
            }
            cout<<" ";
        }

    }
return 0;
}