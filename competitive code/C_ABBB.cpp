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
void solve()
{
    ll i,j,k;
    string s;cin>>s;
    n=s.size();
    vector<ll> bsuf(n+2,0);
    for(i=n-1;i>=0;i--)
    {
        if(s[i]=='B'&&bsuf[i+1]>=0) 
        {            
            bsuf[i]=bsuf[i+1]+1;
        }
        else if(s[i]=='B'&&bsuf[i+1]<0) bsuf[i]=1;
        else if(s[i]=='A') bsuf[i]=bsuf[i+1]-1;
    }
    ll ans=0;
    for(i=0;i<n;i++)
    {
        //cout<<bsuf[i]<<" ";
        if(bsuf[i]<0) ans++;
    }
    if(bsuf[0]>0&&bsuf[0]%2==1) ans++;
    cout<<ans<<endl;




}

int main()
{
    fast
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
return 0;
}