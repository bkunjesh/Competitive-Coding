// //@ikung
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define fast                      \
//     ios_base::sync_with_stdio(0); \
//     cin.tie(0);
// #define f(i, k) for (int i = 0; i < k; i++)
// #define F first
// #define dbg(x) cout << #x << " " << x << endl;
// #define S second
// #define endl "\n"
// #define rep(i, n) for (int i = 1; i <= n; i++)
// #define rew(i, a, b) for (int i = a; i <= b; i++)
// #define mod 1000000007
// const int inf = 1e18;
// const int N = 200005;

// int n;

// void solve()
// {
//     int i, j, k;

//     cin >> n >> k;
//     vector<int> a(n), pref(n + 1, 0);
//     f(i, n) cin >> a[i];
//     pref[0] = a[0];
//     rep(i, n - 1) pref[i] = pref[i - 1] + a[i];

//     auto check = [&](int x) {
//         for (i = 1; i < n; i++)
//         {
//             if ((a[i] * 100 )  > k * (pref[i - 1] + x))
//             {
//                 return 0;
//             }
//         }
//         return 1;
//     };
//     int ans = 1e18;
//     int l = 0, r = 1e11;
//     while (l <= r)
//     {
//         int mid = l + (r - l) / 2;
//         if (check(mid))
//         {
//             ans = (mid);
//             r = mid - 1;
//         }
//         else
//             l = mid + 1;
//     }
//     cout << ans << endl;

//     return;
// }

// signed main()
// {
//     fast int t = 1, i, j, k;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

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
    vector<int> a(n), pref(n + 1, 0);
    f(i, n) cin >> a[i];
    pref[0] = a[0];
    rep(i, n - 1) pref[i] = pref[i - 1] + a[i];

    // if (k == 100)
    // {
    //     cout << 0 << endl;
    //     return;
    // }

    int ans = 0;
    for (i = 1; i < n; i++)
    {
        int tmp = ((a[i] * 100 + pref[i - 1] - 1) / pref[i - 1]);
        //cout << tmp << " ";
        if (tmp > k)
        {
            // cout << "YES";
            int val = 100 * a[i] - k * pref[i - 1];

            if (val > 0)
            {
                val = (val + k - 1) / (k);
                ans = max(ans, val);
            }
        }
    }
    cout << ans << endl;

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