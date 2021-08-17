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
vector<int> temp;
map<int, int> m;
int getans(int x)
{
    if (x == 0)
        return 1;
    if (x < 0)
        return 0;

    if (m[x] != 0)
        return m[x];
    f(i, n)
    {
        m[x] = (m[x] | getans(x - temp[i]));
    }
    return m[x];
}
void solve()
{
    int i, j, k;
    // m.clear();
    cin >> n;
    n = 2047;
    // string s;
    // while (n >= 10)
    // {

    //     s = to_string(n);
    //     int sz = s.size();
    //     // cout << n << " " << temp[sz - 1] << " " << n - temp[sz - 1] << endl;
    //     if (n >= temp[sz - 1])
    //         n -= temp[sz - 1];
    //     else
    //         n -= temp[sz - 2];
    // }
    // if (n == 0)
    // {
    //     cout << "YES" << endl;
    // }
    // else
    // {
    //     cout << "NO" << endl;
    // }
    for (i = 0; i < 200; i++)
    {
        if ((n - 11 * i)<0)
            break;
        if ((n - 11 * i) >= 0 && (n - 11 * i) % 111 == 0)
        {
            // cout << i << " ";
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

    // if (n == 1)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }
    // // if (s[n - 1]  s[n - 2])
    // // {
    // //     cout << "NO" << endl;
    // //     return;
    // // }

    // int a[n + 1];
    // memset(a, 0, sizeof(a));

    // a[n - 1] = s[n - 1] - '0';
    // // a[n - 2] = a[n - 1];
    // int mx = a[n - 1];
    // for (i = n - 3; i >= 0; i--)
    // {
    //     if (s[i] > s[i + 1])
    //     {
    //         // cout << s[i] << " " << s[i + 1];
    //         cout << "NO" << endl;
    //         return;
    //     }
    // }
    // cout << "YES" << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    int p = 0;
    f(i, 11)
    {
        p = p * 10 + 1;
        temp.push_back(p);
    }
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