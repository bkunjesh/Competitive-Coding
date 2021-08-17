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
int getsum(int x)
{
    if (x < 0)
        return 0;
    return x * (x + 1) / 2;
}
void solve()
{
    int i, j, k;

    string s;
    cin >> n >> s;
    int indsum = 0, ans = 1e18;
    vector<int> star, pref(n, 0);
    f(i, n)
    {
        if (s[i] == '*')
            indsum += i, star.push_back(i);
    }
    int cursum = 0, starcnt = 0, totstar = star.size();

    for (i = 0; i < n; i++)
    {

        if (s[i] == '*')
            starcnt++, cursum += i;

        int l = (i + 1 - starcnt);
        int c = i;
        int h = (totstar - starcnt) + c;

        int temp;
        temp = ((getsum(c) - getsum(l - 1)) - cursum);
        temp += ((indsum - cursum) - (getsum(h) - getsum(c)));

        if (temp >= 0)
            ans = min(ans, temp);
    }

    if (ans == 1e18)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
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