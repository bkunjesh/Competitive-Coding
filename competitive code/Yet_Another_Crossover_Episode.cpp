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
void printans(vector<ll> ans)
{
    cout<<ans.size()<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
void solve()
{
    ll d;
    cin>>d;
    vector<ll> ans;
    ans.push_back(1);
    ll p=1e5-2;
    while(d>0)
    {
        p=min(d,p);
        ans.push_back(p+2);
        ans.push_back(p+1);
        ans.push_back(1);
        d-=p;
    }
    printans(ans);
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
