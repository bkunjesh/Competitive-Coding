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
        cin>>n>>k;
        vector<ll> a(n+2);
        f(i,n) cin>>a[i];
        //sort(a.begin(),a.end());
        ll m=0;
        while(m<=100)
        {
            i=0;
            ll diffele=0;
            ll prevdifele=-1;
            if(a[i]==0) prevdifele=0,diffele++;
            while(a[i]==0&&i<n) i++;
            
            if(i>=n) break;
            while(diffele<=k&&i<n)
            {
                if(prevdifele==a[i]) 
                { 
                    a[i]-=prevdifele;
                    i++;
                    continue;
                }
                if(diffele==k) break;
                prevdifele=a[i];
                a[i]-=prevdifele;
                diffele++;
                i++;
            }
            //cout<<prevdifele<<",";
            for(;i<n;i++)
            {
                a[i]-=prevdifele;
            }
            m++;
        }
        if(m>100) cout<<-1<<endl;
        else cout<<m<<endl;
    }
return 0;
}