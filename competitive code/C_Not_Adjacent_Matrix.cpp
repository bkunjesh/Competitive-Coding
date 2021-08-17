//@ikung
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
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    
    int cnt = 1;

    i = 0, j = 0;

    for (int line = 1; line <= (n + n - 1); line++)
    {
        int start_col = max(0ll, line - n);

        int count = min({line, (n - start_col), n});

        for (j = 0; j < count; j++)
        {
            int x = min(n, line);
            a[x - j - 1][start_col + j] = cnt++;
        }
    }

    if (n > 1)
    {
        swap(a[0][0], a[n - 1][n - 1]);
    }

    //check

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((j + 1 < n && abs(a[i][j + 1] - a[i][j]) == 1) || (j - 1 >= 0 && abs(a[i][j - 1] - a[i][j]) == 1) || (i + 1 < n && abs(a[i + 1][j] - a[i][j]) == 1) || (i - 1 >= 0 && abs(a[i - 1][j] - a[i][j]) == 1))
            {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif