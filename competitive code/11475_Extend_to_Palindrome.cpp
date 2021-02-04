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

    string s;
    cin >> s;
    n = s.size();
    vector<int> d1(n + 1, 0);

    int l = 0, r = -1;

    for (i = 0; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
            k++;
        d1[i] = k--;
        if (i + k > r)
        {
            r = i + k;
            l = i - k;
        }
    }

    int val = l;
    cout << l << " ";

    vector<int> d2(n + 1, 0);

    l = 0, r = -1;

    for (i = 0; i < n; i++)
    {
        int k = (i > r) ? 0 : min(d1[l + r - i + 1], r - i + 1);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
            k++;
        d2[i] = k--;
        if (i + k > r)
        {
            r = i + k;
            l = i - k - 1;
        }
    }
    val = min(val, l);
    cout << l << " ";
    string temp = s.substr(0, val + 1);
    //cout << temp << " ";
    reverse(temp.begin(), temp.end());
    cout << s + temp << endl;

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