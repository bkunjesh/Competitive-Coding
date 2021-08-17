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

// int n;

void solve()
{
    int i, j, k;

    // string strArr[] = {"(0,1,1)", "(1,1,1)", "(1,1,1)"};
    // int arrLength = 3;
    vector<string> a;
    for (i = 0; i < arrLength; i++)
    {
        string temp = "";
        // cout << arr[i] << endl;
        for (auto x : strArr[i])
        {
            if (x >= '0' && x <= '1')
                temp += x;
        }
        //cout << temp << endl;
        a.push_back(temp);
    }
    int n = a.size();
    int m = a[0].size();
    int ans = 0;
    for (i = 0; i < m; i++)
    {
        if (a[0][i] == '0')
        {
            ans++;
            break;
        }
    }
    for (i = 0; i < m; i++)
    {
        if (a[n - 1][i] == '0')
        {
            ans++;
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[0][i] == '0')
        {
            ans++;
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[m - 1][i] == '0')
        {
            ans++;
            break;
        }
    }

    cout << ans << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif