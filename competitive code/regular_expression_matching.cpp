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
// eg:
// xaabyc
// xa *b.c

    bool
    REM(string pat, string s)
{
    int i, j;
    int n = s.size(), m = pat.size();
    pat = " " + pat;
    s = " " + s;
    bool mat[s.size()][pat.size()];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            mat[i][j] = false;
        }
    }

    mat[0][0] = true;

    for (i = 1; i <= m; i++)
    {
        if (pat[i] == '*')
            mat[0][i] = mat[0][i - 2];
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (s[i] == pat[j] || pat[j] == '.')
            {
                mat[i][j] = mat[i - 1][j - 1];
            }
            else if (pat[j] == '*')
            {
                mat[i][j] = mat[i][j - 2];
                if (pat[j-1]=='.'||s[i] == pat[j - 1])
                    mat[i][j] |= mat[i - 1][j];
            }
            else
                mat[i][j] = false;
        }
    }
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return mat[n][m];
}
void solve()
{
    int i, j, k;

    string s, pat;
    cin >> s >> pat;
    cout << REM(pat, s);

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}