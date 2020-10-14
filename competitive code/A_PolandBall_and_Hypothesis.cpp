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
        vector<ll> prime(1000005,0);
        for(i=2;i<1000005;i++)
        if(prime[i]==0)
        {
            for(j=i+i;j<1000005;j+=i) prime[j]=1;
        }

        for(i=1;i<=1000;i++)
        {
            if(prime[i*n+1]==1)
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
return 0;
}