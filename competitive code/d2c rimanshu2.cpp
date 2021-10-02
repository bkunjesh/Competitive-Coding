//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

void solve()
{
    int i, j, k;

    cin >> n >> k;
    unordered_map<int, int> m;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x % n]++;
    }

    for (i = 0; i < n; i++)
    {
        if (m[(i + n - k * i) % n] > 0)
        {
            m[(i + n - k * i) % n]--;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

    return;
}

signed main()
{
    int t = 1, i, j, k;
    //cin >> t;
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