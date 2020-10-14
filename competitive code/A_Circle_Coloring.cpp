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
    cin >> t;
    while (t--)
    {
        cin>>n;
        vector<ll> a(n+1),b(n+1),c(n+1),ans(n+1);
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
        f(i,n) cin>>c[i];
        ans[0]=a[0];
        for(i=1;i<n;i++)
        {
            if(a[i]!=ans[i-1])
            {
                ans[i]=a[i];
            }
            else if(b[i]!=ans[i-1])
            {
                ans[i]=b[i];
            }
            else
            {
                ans[i]=c[i];
            }
            
        }
        for(i=n-2;i>=0;i--)
        {
            if(a[i]!=ans[i+1]&&i>0&&a[i]!=ans[i-1])
            {
                ans[i]=a[i];
            }
            else if(b[i]!=ans[i+1]&&i>0&&b[i]!=ans[i-1]){
                ans[i]=b[i];
            }
            else ans[i]=c[i];
            
        }
         if(a[0]!=ans[1]&&a[0]!=ans[n-1])
            {
                ans[0]=a[0];
            }
            else if(b[0]!=ans[1]&&b[0]!=ans[n-1]){
                ans[0]=b[0];
            }
            else ans[0]=c[0];

        f(i,n) cout<<ans[i]<<" ";
        cout<<endl;

    }
return 0;
}