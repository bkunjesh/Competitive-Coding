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
        ll m;cin>>n>>m;
        vector<ll> a(n+1),prefsum(n+1,0);
       // vector<vector<ll>> g(n+1);
       vector<ll> freq(102,0);
        rep(i,n) 
        {
            cin>>a[i],prefsum[i]=prefsum[i-1]+a[i];
            // for(j=i+1;j<=n;j++)
            // {
            //     g[j].push_back(a[i]);
            // }
        }
        // rep(i,n)
        // {
        //     sort(g[i].begin(),g[i].end(),greater<ll>());
        //     for(j=1;j<g[i].size();j++)
        //     {
        //         g[i][j]+=g[i][j-1];
        //     }
        // }
        multiset<ll,greater<ll>> s;
        vector<ll> ans(n+1,0);
        for(i=1;i<=n;i++)
        {
            
            
            if(prefsum[i]>m)
            {
                ll minus=prefsum[i]-m;
                // auto it=lower_bound(g[i].begin(),g[i].end(),minus);
                // ans[i]=it-g[i].begin()+1;
                //sort(a.begin()+1,a.begin()+i);
                /*auto it=s.begin();
                ll sum=0,cnt=0;
                while(sum<minus)
                {
                    sum+=(*it);
                    it++;
                    cnt++;
                }
                ans[i]=cnt;*/
                ll cnt=0;
                for(j=100;j>0;j--)
                {
                    if(freq[j]*j>minus)
                    {
                        cnt+=(minus+j-1)/j;
                        break;
                    }
                    else
                    {
                        minus-=freq[j]*j;
                        cnt+=freq[j];
                    }
                    
                }
                ans[i]=cnt;
            }
            freq[a[i]]++;
            s.insert(a[i]);
        }
        rep(i,n) cout<<ans[i]<<" ";

    }
return 0;
}