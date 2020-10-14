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
    ll t = 1, i, j;
    //cin >> t;
    while (t--)
    {
        
        
        cout<<fixed << setprecision(7); 
        ll r;
        cin>>n>>r;
        double pi = 3.14159265359; 

        double sinx=sin(pi/n);
        double ans=(r*sinx)/(1-sinx);
        cout<<ans<<endl;
    }
return 0;
}