//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
const int N=100005;
int dp[N];
int n;

void solve()
{
    int i, j, k;
    
    string s;
    cin>>s;
    n=s.size();
    int cntu=0,cntn=0;
    int ans=1;
    f(i,n)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0<<endl;
            return;
        }
        if((i>0)&&(s[i-1]!=s[i]&&(s[i]!='u'||s[i]!='n')))
        {
            if(s[i]!='u')
            ans=(ans*dp[cntu])%mod,cntu=0;
            if(s[i]!='n')
            ans=(ans*dp[cntn])%mod,cntn=0;
            if(s[i]=='u') cntu++;
            if(s[i]=='n') cntn++;
            // cout<<cntu<<" "<<cntn<<endl;
            
        }
        else
        {
            if(s[i]=='u') cntu++;
            if(s[i]=='n') cntn++;
        }
    }
    ans=(ans*dp[cntu])%mod;
    ans=(ans*dp[cntn])%mod;
    cout<<ans%mod<<endl;
    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    
    dp[0]=1,dp[1]=1;
    for(i=2;i<N;i++) dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}