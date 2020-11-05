//@CodesUp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (i = 1; i <= n; i++)
#define rew(i, a, b) for (i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
int N = 200005;
int n, m;
char g[1001][1001];
int flag = 0;
pair<int, int> start;
pair<int, int> dest;
string answer;
string solve(int i, int j, string ans)
{
    g[i][j] = '#';
    //cout << i << " " << j << endl;
    if (i == dest.F && j == dest.S)
    {
        flag = 1;
        answer = ans;
        return ans;
    }
    if (j + 1 < m && g[i][j + 1] == '.')
    {
        //ans += "R";
        solve(i, j + 1, ans + "R");
    }
    if (i + 1 < n && g[i + 1][j] == '.')
    {
        //ans += "D";
        solve(i + 1, j, ans + "D");
    }
    if (j - 1 >= 0 && g[i][j - 1] == '.')
    {
        //ans += "L";
        solve(i, j - 1, ans + "L");
    }
    if (i - 1 >= 0 && g[i - 1][j] == '.')
    {
        //ans += "U";
        solve(i - 1, j, ans + "U");
    }

    return ans;
}
void sol()
{
    int i, j, k;
    cin >> n >> m;
    int cnt = 0;
    f(i, n)
    {
        f(j, m)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
            {
                start = {i, j};
            }
            if (g[i][j] == 'B')
            {
                dest = {i, j};
                g[i][j] = '.';
            }
        }
    }
    string ans = "";
    ans = solve(start.F, start.S, ans);
    if (flag)
    {
        cout << "YES" << endl;
        cout << answer.size() << endl;
        cout << answer << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        sol();
    }
    return 0;
}