//@CodesUp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
int N = 200005;

int n;

void solve()
{
    int i, j, k, m;

    cin >> n >> m;
    int mn = (n + 1) / 2, mm = (m + 1) / 2;
    vector<vector<int>> a(n, vector<int>(m));
    f(i, n) f(j, m) cin >> a[i][j];
    //f(i, n) f(j, m) cout<< a[i][j]<<" ";
    int ans = 0;
    for (i = 0; i < mn; i++)
    {
        for (j = 0; j < mm; j++)
        {
            
            vector<int> ele;

            ele.push_back(a[i][j]);
            ele.push_back(a[n - i - 1][j]);
            ele.push_back(a[i][m - j - 1]);
            ele.push_back(a[n - i - 1][m - j - 1]);
            //cout << ele.size();
            sort(ele.begin(), ele.end());
            ans = ans + (abs(a[i][j] - ele[1]));
            if(i!=n-i-1)
                ans = ans + (abs(a[n-i-1][j] - ele[1]));
            if (j != m -j - 1)
                ans = ans + (abs(a[i][m-j-1] - ele[1]));
            if (i != n - i - 1 && j != m - j - 1)
                ans = ans + (abs(a[n - i - 1][m - j - 1] - ele[1]));
        }
    }
    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}