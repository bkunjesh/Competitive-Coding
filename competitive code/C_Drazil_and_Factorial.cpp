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
        string s;
        cin>>n>>s;
        vector<ll> ans,cnt(10,0);
        for(auto it:s) cnt[it-'0']++;
        for(i=8;i>=0;i--) cnt[i]+=cnt[i+1];
        for(i=9;i>=2;i--)
        if(cnt[i])
        {
           // for(k=2;k<10;k++) cout<<cnt[k]<<",";
           // cout<<endl;
            if(i==4||i==6||i==8||i==9)
            {
                if(i==4) cnt[2]+=2*cnt[4];
                if(i==6) cnt[2]+=cnt[6],cnt[3]+=cnt[6];
                if(i==8) cnt[2]+=3*cnt[8];
                if(i==9) cnt[3]+=2*cnt[9];
            }
            else
            {
                for(j=i-1;j>=2;j--) cnt[j]-=cnt[i];
                while(cnt[i]--) ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end(),greater<ll>());
        for(auto it:ans) cout<<it;
        cout<<endl;
    }
return 0;
}