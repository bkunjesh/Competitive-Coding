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
const int inf = 1e18;
int N=200005;

int n;

void solve()
{
    int i, j, k;

    string s;
    cin >> s;
    n = s.size();
    vector<vector<int>> dp(26, vector<int>(n+1, 0));
    dp[s[0] - 'a'][0] = 1;
    for (i = 0; i < 26;i++)
    {
        for (j = 1; j <= n;j++)
        {
            dp[i][j] = dp[i][j - 1];
            if(j<n&&s[j]-'a'==i)
                dp[i][j]++;
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        int l, r, mid,flag=0;
        cin >> l >> r;
        mid = (l + r) / 2;
        for (i = 0; i < 26;i++)
        {
            int left = (l>0)?dp[i][l - 1]:0;
            int middle = (mid>0)?dp[i][mid - 1]:0;
            if (dp[i][mid] - left != dp[i][r] -middle)
            {

                flag = 1;
                break;
            }
        }
        if(flag)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
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