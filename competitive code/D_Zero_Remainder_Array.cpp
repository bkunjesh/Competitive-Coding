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
        f(i,n) 
        {
            cin>>a[i];
            if(a[i]%k!=0) a[i]=(k-a[i]%k);
            else a[i]=0;
        }
        sort(a.begin(),a.end());
        ll flag=1;
        map<ll,ll> m;
        f(i,n)
        {
            if(a[i]==0) continue;
            flag=0;
            if(!m.count(a[i]))
            {
                m[a[i]]++;
            }
            else
            {
                ll temp=a[i];
                a[i]=a[i]+k*m[a[i]];
                m[temp]++;
                m[a[i]]++;
            }
        }
        ll ans=*max_element(a.begin(),a.end())+1;
        if(flag) ans--;

        cout<<ans<<endl;
        
    }
return 0;
}