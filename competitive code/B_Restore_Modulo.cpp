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
    vector<int> a(n);
    f(i, n) cin >> a[i];
    if (n == 1 || n == 2)
    {
        cout << 0 << endl;
        return;
    }
    int c, m = -inf, pos = -inf, neg = -inf;
    for (i = 0; i < n; i++)
        if (a[i] != a[0])
            break;
    if (i == n)
    {
        cout << 0 << endl;
        return;
    }
    f(i, n - 1)
    {
        if (a[i] < a[i + 1])
        {
            c = a[i + 1] - a[i];
        }
        if (a[i] == a[i + 1])
        {
            cout << -1 << endl;
            return;
        }
    }

    f(i, n - 1)
    {
        if (a[i] < a[i + 1])
        {
            if (pos == -inf)
            {
                pos = a[i + 1] - a[i];
            }
            else
            {
                if (pos != a[i + 1] - a[i])
                {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        else if (a[i] > a[i + 1])
        {
            if (neg == -inf)
            {
                neg = a[i + 1] - a[i];
                m = a[i] + c - a[i + 1];
            }
            else
            {
                if (neg != a[i + 1] - a[i] || (a[i] + c - a[i + 1] != m))
                {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    if (pos == -inf || neg == -inf)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        for (i = 0; i < n - 1;i++)
        {
            if(i==0&&a[i]!=(a[i]%m))
            {
                cout << -1 << endl;
                return;
            }
            if(a[i+1]!=(a[i]+c)%m)
            {
                cout << -1 << endl;
                return;
            }
        }
        cout << m << " " << c << endl;
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