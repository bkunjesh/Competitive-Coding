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
        ll m; cin>>n>>m;
        vector<string> a(n);
        f(i,n) cin>>a[i];
        ll X[4]={0,0,1,-1};
        ll Y[4]={1,-1,0,0};
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j]=='S')
                {
                    for(k=0;k<4;k++)
                    {
                        ll x=i+X[k],y=j+Y[k];
                        if(x<0||x>=n||y<0||y>=m) continue;
                        if(a[x][y]=='W')
                        {
                            cout<<"No"<<endl;
                            return 0;
                        }
                        if(a[x][y]=='.') a[x][y]='D';
                    }
                }
            }
        }
        cout<<"Yes"<<endl;
        f(i,n)
        {
            f(j,m) cout<<a[i][j];
            cout<<endl;
        }

    }
return 0;
}