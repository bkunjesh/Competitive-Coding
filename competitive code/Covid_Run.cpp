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
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        ll x,y;cin>>n>>k>>x>>y;
        ll lp=0;
        while(lp<10000)
        {
            if(x==y) break;
            x=(x+k)%n;
            lp++;
        }
        if(lp>=1000)
        cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
        }
        
        
    }
return 0;
}