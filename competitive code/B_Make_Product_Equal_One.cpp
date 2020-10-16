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
        ll pcnt=0,ncnt=0,zcnt=0,ans=0;
        vector<ll> a(n);
        f(i,n) cin>>a[i];
        f(i,n)
        {
            if(a[i]>0)
            {
                ans=ans+abs(a[i]-1);
                pcnt++;
            }
            else if(a[i]<0)
            {
                ans=ans+(-1-a[i]);
                ncnt++;
            }
            else if(a[i]==0)
            {
                zcnt++;
            }
        }
        if(ncnt%2==1&&zcnt==0) ans+=2;
        ans+=zcnt;
        cout<<ans<<endl;
    }
return 0;
}