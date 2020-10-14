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
        ll m,k;
        cin>>n>>m>>k;
        vector<ll> p(m);
        for(i=0;i<m;i++) cin>>p[i];
        ll grp=0,shift=0,op=0,grplastind=0;
        for(i=0;i<m;)
        {
            grplastind=((p[i]-shift-1)/k+1)*k+shift;
            op++;
            //shift=0;
            while(i<m&&(p[i])<=grplastind)
            {
                i++;
                shift++;
            }


        }
        cout<<op<<endl;

    }
return 0;
}