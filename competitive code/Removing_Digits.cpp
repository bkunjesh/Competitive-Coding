//@CodesUp
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
const int inf = 1e9;
int N=200005;

int n;
vector<int> dp(1000005, inf);
int remove_digit(int p,int cnt)
{
    if(p==0)
    {
        return cnt;
    }
    if(dp[p]!=inf)
        return dp[p];
    int temp = p;
    int ans = INT_MAX;
    while(temp)
    {
        while(temp%10==0)
            temp /= 10;
        dp[temp]= min(dp[temp], remove_digit(p - temp % 10, cnt + 1));
        temp /= 10;
    }
    return dp[p];
}

void solve()
{
    int i, j, k;

    cin >> n;
    int ans = remove_digit(n, 0);
    cout << ans << endl;
    // vector<int> dp(n + 1, inf);
    // dp[0] = 0;
    // for (i = 1; i <= n; i++)
    // {    for (char c: to_string(i)) 
    //     {
    //         dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
    //     }
    // }
    // cout << dp[n] << endl;

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}