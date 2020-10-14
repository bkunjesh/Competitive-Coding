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
        ll ans;
        if(n%2==0)
        {
            ans=(n+2)/2;
        }
        else ans=(n+1)/2;

        cout<<ans<<endl;

        ll fst=1,scd=1,fcnt=0,scnt=1;
        while(n--)
        {
            cout<<fst<<" "<<scd<<endl;
            fcnt++,scnt++;
            if(fcnt==2) fcnt=0,fst++;
            if(scnt==2) scnt=0,scd++;
        }


    }
return 0;
}