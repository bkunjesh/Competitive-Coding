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
    int i, j, k;
    cin >> n;
    vector<int> a(2 * n + 1), onesuff(2 * n + 1, 0), chef(2 * n + 1, 0);
    a[0] = 0;
    rep(i, n) cin >> a[i], a[n + i] = a[i];
    //onesuff[2 * n] = (a[2 * n] == 1) ? 1 : 0;
    for (i = 2 * n - 1; i > 0; i--)
    {
        if (i == n)
            continue;
        if (a[i] == 1)
        {
            if (a[i + 1] == 1)
                onesuff[i] = onesuff[i + 1] + 1;
            else
                onesuff[i] = 1;
        }
        //cout << onesuff[i] << " ";
    }
    //cout << endl;

    int turn = 0;
    for (i = 1; i <= 2 * n; i++)
    {
        if (i == n || i == 2 * n)
        {
            if (turn == 0)
                chef[i] = (a[i] % 2 == 0) ? a[i] - 1 : a[i];
            continue;
        }
        if (a[i] == 1)
        {
            if (a[i - 1] != 1 && onesuff[i] % 2 == 1)
            {
                if (i == 1)
                {
                    chef[i] = a[i];
                    turn = !turn;
                }
                if (turn == 0)
                {
                    (a[i - 1] % 2 == 0) ? chef[i - 1]-- : chef[i - 1]++;
                }

                continue;
            }
            else
            {
                if (turn == 0)
                {
                    chef[i] = a[i];
                }

                turn = !turn;
            }
        }
        if (turn == 0)
        {
            chef[i] = (a[i] % 2 == 0) ? a[i] : a[i] - 1;
        }
    }
    for (i = 1; i <= 2 * n; i++)
        chef[i] = (chef[i] % mod + chef[i - 1] % mod) % mod;

    // for (auto it : chef)
    //     cout << it << " ";
    // cout << endl;

    int q;
    cin >> q;
    while (q--)
    {
        int r;
        cin >> r;
        k = r % (2 * n);
        int ans = 0;
        if (k > 0)
            ans = chef[k - 1];
        if(chef[k]!=chef[k-1])
        ans = (ans + a[k])%mod;
        // if (a[k] != 1 && a[k + 1] == 1 && onesuff[k + 1] % 2 == 1)
        //     ans++;

        int p = (r / (2 * n));
        ans = ans % mod + ((p % mod) * (chef[2 * n] % mod)) % mod;
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