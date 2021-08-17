//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;

void solve()
{
    int i, j, k;

    int q;
    cin>>n>>q;
    string s;
    cin>>s;
    int dp[n + 2][26];
    memset(dp, 0, sizeof(dp));
    for (i = 0;i<n;i++)
    {
        f(j, 26) dp[i+1][j] = dp[i][j];
        dp[i + 1][s[i] - 'a']++;
    }
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        int ans = 0;
        f(i,26)
        {
            ans=ans+(dp[r][i] - dp[l][i]) * (i + 1);
        }
        cout << ans << endl;
    }

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif