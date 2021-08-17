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

int n, k;
int getans(string s)
{
    // cout << s << endl;
    int i;
    int first = n + 1, last = -1;
    f(i, n) if (s[i] == '*') first = min(first, i), last = max(last, i);
    if (last == -1)
        return 0;
    int prevdonestar = first, recentproceedstar = first;
    // cout << first << " " << last << " ";
    s[first] = 'x';
    int cnt = 0, ans = 1;
    if (first == last)
        return 1;

    for (i = first + 1; i <= last; i++)
    {
        if (i - prevdonestar > k)
        {
            // cout << i << " ";
            s[recentproceedstar] = 'x';
            prevdonestar = recentproceedstar;
            ans++;
        }
        if (s[i] == '*')
            recentproceedstar = i;
    }
    if (s[last] != 'x')
    {
        s[last] = 'x';
        ans++;
    }
    // cout << endl;
    return ans;
}

void solve()
{
    int i, j;

    cin >> n >> k;
    string s;
    cin >> s;

    string s1 = s;
    int ans1 = getans(s1);
    reverse(s.begin(), s.end());
    int ans2 = getans(s);

    cout << min(ans1, ans2) << endl;
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