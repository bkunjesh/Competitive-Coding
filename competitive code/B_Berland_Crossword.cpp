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
//      0  1  2  3
    int u, r, d, l, a[4];
    cin >> n >> a[0] >> a[1] >> a[2] >> a[3];
    if (a[0] < n - 1 && a[1] < n - 1 && a[2] < n - 1 && a[3] < n - 1)
    {
        cout << "YES" << endl;
        return;
    }

    auto isvalid = [&](int ul, int ur, int dl, int dr) {
        int b[4];
        for (i = 0; i < 4;i++)
            b[i] = a[i];

        if (ul)
            b[0]--, b[3]--;
        if (ur)
            b[0]--, b[1]--;
        if (dl)
            b[2]--, b[3]--;
        if (dr)
            b[2]--, b[1]--;

        if (b[0] < n - 1 && b[1] < n - 1 && b[2] < n - 1 && b[3] < n - 1 && b[0] >= 0 && b[1] >= 0 && b[2] >= 0 && b[3] >= 0)
            return 1;

        return 0;
    };

    f(ul, 2)
    {
        f(ur, 2)
        {
            f(dl, 2)
            {
                f(dr, 2)
                {
                    if (isvalid(ul, ur, dl, dr))
                    {
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;

    // if (u == 1 && r == n && d == n && l == 1)
    // {
    //     cout << "YES" << endl;
    //     return;
    // }
    // int mat[n][n];
    // memset(mat, 0, sizeof(mat));
    // if (l > 0)
    // {
    //     for (i = 0; i < n && u > 0; i++, u--)
    //     {
    //         if (mat[0][i] == 0)
    //         {
    //             mat[0][i] = 1;
    //         }
    //     }
    //     if (u > 0)
    //     {
    //         cout << "NO" << endl;
    //         return;
    //     }

    //     if ((mat[0][0] == 1 && l > 1) || (mat[0][0] == 0 && l > 0))
    //     {
    //         for (i = 0; i < n && d > 0; i++, d--)
    //         {
    //             if (mat[n - 1][i] == 0)
    //                 mat[n - 1][i] = 1;
    //         }
    //         if (d > 0)
    //         {
    //             cout << "NO" << endl;
    //             return;
    //         }
    //     }
    //     else
    //     {
    //         for (i = 1; i < n && d > 0; i++, d--)
    //         {
    //             if (mat[n - 1][i] == 0)
    //                 mat[n - 1][i] = 1;
    //         }
    //         if (d > 0)
    //         {
    //             cout << "NO" << endl;
    //             return;
    //         }
    //     }
    // }
    // else
    // {
    //     for (i = 1; i < n && u > 0; i++, u--)
    //     {
    //         if (mat[0][i] == 0)
    //             mat[0][i] = 1;
    //     }
    //     if (u > 0)
    //     {
    //         cout << "NO" << endl;
    //         return;
    //     }
    //     for (i = 1; i < n && d > 0; i++, d--)
    //     {
    //         if (mat[n - 1][i] == 0)
    //             mat[n - 1][i] = 1;
    //     }
    //     if (d > 0)
    //     {
    //         cout << "NO" << endl;
    //         return;
    //     }
    // }

    // int cntr = 0;
    // f(i, n) cntr += mat[i][n - 1];

    // if (r < cntr)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }

    // int cntl = 0;
    // f(i, n) cntl += mat[i][0];
    // if (l - cntl > n - 2)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }
    // if (r == cntr)
    // {
    //     cout << "YES" << endl;
    //     return;
    // }
    // if (mat[0][n - 1] == 1)
    // {
    //     r--;
    // }
    // else
    // {
    //     if (mat[0][1] == 1)
    //     {
    //         r--;
    //     }
    // }
    // for (i = 1; i < n - 1 && r > 0; i++, r--)
    // {
    //     if (mat[i][n - 1] == 0)
    //         mat[i][n - 1] = 1;
    // }
    // if (r == 0)
    // {
    //     cout << "YES" << endl;
    //     return;
    // }
    // if (r > 1)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }

    // if (r == 1)
    // {
    //     if (mat[n - 1][n - 1] == 1)
    //     {
    //         cout << "YES" << endl;
    //         return;
    //     }
    //     else
    //     {

    //         if (mat[n - 1][1] == 1)
    //         {
    //             cout << "YES" << endl;
    //             return;
    //         }
    //         else
    //         {

    //             if (mat[n - 1][0] == 0)
    //             {
    //                 cout << "NO" << endl;
    //                 return;
    //             }
    //             else
    //             {

    //                 if (l < n - 1 - mat[0][0])
    //                 {
    //                     cout << "YES" << endl;
    //                     return;
    //                 }
    //                 else
    //                 {
    //                     cout << "NO" << endl;
    //                     return;
    //                 }
    //             }
    //         }
    //     }
    // }

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