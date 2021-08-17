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

    cin >> n >> k;
    string s;
    cin >> s;

    auto check = [&](int w) {
        int acnt = 0, bcnt = 0;
        f(i, w)(s[i] == 'a') ? acnt++ : bcnt++;
        i = w, j = 0;
        for (; i < n; i++, j++)
        {
            if (max(acnt, bcnt) + min(k, min(acnt, bcnt)) >= w)
                return 1;
            (s[i] == 'a') ? acnt++ : bcnt++;
            (s[j] == 'a') ? acnt-- : bcnt--;
        }
        if (max(acnt, bcnt) + min(k, min(acnt, bcnt)) >= w)
            return 1;
        return 0;
    };

    int l = 0, h = n, ans;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        // cout << l << " " << h << " " << mid << endl;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
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