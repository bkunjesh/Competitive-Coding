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
        cin>>n;
        vector<ll> a(2*n+1,0);
        ll cnt=1;
        rep(i,n)
        {
            ll fst=cnt++;
            ll scd=cnt++;
            if(i%2==0) swap(fst,scd);
            a[i]=fst;
            a[n+i]=scd;
        }
        
        //rep(i,2*n) cout<<a[i]<<" ";
        //check
        ll sum=0;
        map<ll,ll> m;
        rep(i,n) sum+=a[i],a.push_back(a[i]);
        m[sum]++;
        for(i=2;i<=2*n;i++)
        {
            sum-=a[i-1];
            sum+=a[i+n-1];
            m[sum]++;
        }
        if(m.size()>2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        cout<<"YES"<<endl;
        rep(i,2*n) cout<<a[i]<<" ";
        cout<<endl;
        
        
        

    }
return 0;
}