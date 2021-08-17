//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n, m;

vector<vector<char>> make_grid(char even, char odd)
{
    int i, j, k;
    vector<vector<char>> g(n, vector<char>(m, even));
    f(i, n)
    {
        f(j, m)
        {
            if ((i + j) % 2)
                g[i][j] = odd;
        }
    }
    return g;
}

void solve()
{
    int i, j, k;

    cin >> n >> m;
    char a[n][m];
    vector<int> c, d;
    f(i, n)
    {
        f(j, m)
        {
            cin >> a[i][j];
            if (a[i][j] == 'R')
            {
                c.push_back(i + j);
            }
            else if (a[i][j] == 'W')
            {
                d.push_back(i + j);
            }
        }
    }
    for (i = 1; i < c.size(); i++)
    {
        if (c[i - 1] % 2 != c[i] % 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (i = 1; i < d.size(); i++)
    {
        if (d[i - 1] % 2 != d[i] % 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    if (c.size() > 0 && d.size() > 0 && (c[0] % 2 == d[0] % 2))
    {
        cout << "NO" << endl;
        return;
    }
    vector<vector<char>> g;
    if (c.size() > 0)
    {
        if (c[0] % 2 == 0)
        {
            char even = 'R';
            char odd = 'W';
            g = make_grid(even, odd);
        }
        else
        {
            char even = 'W';
            char odd = 'R';
            g = make_grid(even, odd);
        }
    }
    else if (d.size() > 0)
    {
        if (d[0] % 2 == 0)
        {
            char even = 'W';
            char odd = 'R';
            g = make_grid(even, odd);
        }
        else
        {
            char even = 'R';
            char odd = 'W';
            g = make_grid(even, odd);
        }
    }
    else
    {
        char even = 'R';
        char odd = 'W';
        g = make_grid(even, odd);
    }
    cout << "YES" << endl;
    f(i, n)
    {
        f(j, m)
        {
            cout << g[i][j];
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