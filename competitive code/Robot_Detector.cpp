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
        ll r,c;cin>>r>>c;
        string ans="";
        
        for(i=0;i<=c;) 
        {
            for(j=0;j<r;j++) ans+='R';
            i+=2;
            if(i>c) break;
            ans+="UU";
            for(j=0;j<r&&i<=c;j++) ans+='L';
            i+=2;
            if(i>c) break;
            ans+="UU";
            
        }
        cout<<ans<<endl;
        
    }
return 0;
}