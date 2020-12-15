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
    vector<vector<int>> a(n, vector<int>(m, 0)), ans(n, vector<int>(m, 0));
    char ch;
    int val = 0;
    f(i, n) f(j, m) cin >> ch, a[i][j] = (ch == '*' ? 1 : 0);
    f(i, n)
    {
        f(j, m)
        {
            if (j == 0 || a[i][j] == 0)
                continue;
            else
            {
                a[i][j] += a[i][j - 1];
            }
        }
    }
    f(i, n)
    {
        f(j, m)
        {
            //cout << i << " " << j << endl;
            if (a[i][j] == 0)
                continue;
            k = 0;
            while ((j - k >= 0) && (j + k < m)&&(i+k)<n)
            {
                int diff = a[i + k][j + k] - a[i + k][j - k];

                if (diff == k * 2 && a[i + k][j + k] > 0 && a[i + k][j - k] > 0)
                {
                    ans[i][j]++;
                    k++;
                }
                else
                {
                    break;
                }
                
            }
        }
    }

    f(i, n)
    {
        f(j, m) val += ans[i][j];
        //, cout << ans[i][j] << " ";
        //cout << endl;
    }

    cout << val << endl;

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