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
    int i, j, k, a, b, c, p, ans = 0;
    string s;
    cin >> a >> b >> p;
    cin >> s;
    n = s.size();
    vector<int> cost(n, 0);
    c = (s[0] == 'A') ? a : b;
    i = 1;
    cost[1] = c;
    for (i = 2; i < n; i++)
    {
        if (s[i - 1] != s[i - 2])
        {
            if (s[i - 1] == 'A')
                cost[i] = cost[i - 1] + a;
            if (s[i - 1] == 'B')
                cost[i] = cost[i - 1] + b;
        }
        else
            cost[i] = cost[i - 1];
    }

    // for (auto co : cost) cout << co << " ";
    // cout << endl;
    if ((cost[n - 1] - cost[0] <= p))
    {
        cout << 1 << endl;
        return;
    }
    for (i = 0; i < n; i++)
    {
        if ( (cost[n - 1] - cost[i] <= p))
        {
            k = cost[i];
            while(cost[i+1]==k)
                i++;
            cout << i + 1 << endl;
            return;
        }
    }
    cout << n << endl;

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