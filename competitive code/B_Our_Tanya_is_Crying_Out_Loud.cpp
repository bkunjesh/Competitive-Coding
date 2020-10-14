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
    ll t = 1, i, j,k;
    //cin >> t;
    while (t--)
    {
        ll a,b; cin>>n>>k>>a>>b;
         ll ans=(n%k)*a;
         n-=(n%k);
        // if(k*a<b) ans+=n;
        // else ans+=(n/k)*b;
        // cout<<ans<<endl;
        if(k==1) 
        {
            ans+=a*(n-1);
            cout<<ans<<endl;
            return 0;
        }
        while(n>=k)
        {
            //cout<<n<<" "<<a*(n-1)<<" "<<(n/k)*b<<endl;
            //(n-n/k)*a <b
            if(n%k!=0) 
             {
                 if(n>k)
                  ans+=(n%k)*a;
                  else ans+=(n-1)*a;
 
                  n-=(n%k);
                  continue;
 
             }
            if((n-n/k)*a <b)
            {
                ans+=a*(n-n/k);
                n=n/k;
                continue;
            }
            ans+=b;
            n=n/k;
        }
        ans+=((n-1)%k)*a;

        cout<<ans<<endl;




    }
return 0;
}