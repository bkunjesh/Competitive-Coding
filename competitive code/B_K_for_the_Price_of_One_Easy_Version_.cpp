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
const int N=200005;

int n;

void solve()
{
    int i, j, k,h=-1;
    
    int p;
    cin>>n>>p>>k;
    vector<int> a(n);
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    f(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    dp[0][0]=a[0],dp[1][0]=a[1];
    if(n>2) dp[1][1]=dp[0][0]+a[2];
    if(dp[0][0]<=p) h=0;
    if(dp[1][0]<=p) h=1;
    for(i=2;i<n;i++)
    {
        dp[i][0]=dp[i-2][0]+a[i];
        if(i+1<n) dp[i][1]=dp[i-1][0]+a[i+1];
        if(dp[i][0]<=p) h=max(h,i);
        else if(i!=n-1&&dp[i][1]<=p) h=max(h,i+1);
    }
    // f(i,n) cout<<dp[i][0]<<" ";
    // cout<<endl;
    // f(i,n) cout<<dp[i][1]<<" ";
    // cout<<endl;
    if(h!=-1)
    cout<<h+1<<endl;
    else cout<<0<<endl;



    // int h=n;

    // for(i=n-k;i>=0;i-=k)
    // {
    //     if(p-a[i]>=0)
    //     {
    //         h=i;
    //         p-=a[i];
    //     }
    //     else
    //     {
    //         j=i;
    //         while(j<h)
    //         {
    //             if(p-a[j]>=0)
    //             {
    //                 h=j;
    //                 break;
    //             }
    //             j++;
    //         }
    //     }
    // }
    // if(i<0)
    // {
    //     j=0;
    //         while(j<h)
    //         {
    //             if(p-a[j]>=0)
    //             {
    //                 h=j;
    //                 break;
    //             }
    //             j++;
    //         }
    // }

    // cout<<n-h<<endl;
    
    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif