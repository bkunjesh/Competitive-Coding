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
    if (n == 1)
    {
        cout << s << endl;
        return;
    }

    int ans =pow(9, (n - 1) ), pro[n + 1];

    if (s[0] - '0' != 1)
        ans *= (s[0] - '0' - 1);

    pro[0] = s[0] - '0';

    int flag = 1;
    for (i = 1; i < n; i++)
    {
        int temp = s[i] - '0';
        if (temp == 0 && temp == 1)
        {
            // int x = s[i - 1] - '0';
            // int y = x - 1;
            // if (y == 0)
            //     y++;

            // ans = max(ans, (pro[i - 1] / x) * (y)*9 * (n - 1 - i));
            cout << ans << endl;
            return;
        }
        int z = pow(9,n-i-1);
        ans = max(ans, pro[i - 1] * z * (temp - 1));
        pro[i] = pro[i-1] * temp;
    }

    ans = max(ans, pro[i - 1]);
    // for (i = 0; i < n; i++)
    // {
    //     int temp = s[i] - '0';
    //     if (temp == 0)
    //     {
    //         flag = 0;
    //         temp = 10;
    //         ans = max(ans, pro * (temp - 1) * ((n - i - 1) * 9));
    //         break;
    //     }
    //     if (i == 0 && temp == 1)
    //         temp = 2;
    //     {

    //         ans = max(ans, pro * (temp - 1) * ((n - i - 1) * 9));
    //         if (s[i] - '0' != 0)
    //             pro *= (s[i] - '0');
    //         else
    //             pro *= (9);
    //     }
    // }
    // if (flag)
    //     ans = max(ans, pro);
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