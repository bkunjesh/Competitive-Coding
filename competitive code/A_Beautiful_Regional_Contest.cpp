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
    vector<int> a(n), b;
    f(i, n) cin >> a[i];
    j = 0;
    for (i = 0; i < n; i++)
    {
        while (i<n&&a[i] == a[j])
            i++;
        b.push_back(i - j);
        j = i;
    }
    int g = 0, s = 0, br = 0;
    g = b[0];
    for (i = 1; i < b.size(); i++)
    {
        if (s <= g)
            s += b[i];
        else
            break;
    }
    for (; i < b.size(); i++)
    {
        if (br <= g)
            br += b[i];
        else
            break;
    }

    if (g + s + br > n / 2)
    {
        cout << 0 << " " << 0 << " " << 0 << endl;
        return;
    }

    for (; i < b.size(); i++)
    {
        if (g + s + br + b[i] <= n / 2)
            br += b[i];
        else
            break;
    }
    if (g + s + br > n / 2||g>=s||g>=br)
    {
        cout << 0 << " " << 0 << " " << 0 << endl;
        return;
    }
    
    cout << g << " " << s << " " << br << endl;
    // for (auto it : b)
    //     cout << it << " ";
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