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

    int d;
    cin >> d;
    // d *= 1e6;

    // auto Check = [&](int x) {
    //     if (x * x == d * (x - 1))
    //         return 1;
    //     else if (x * x < d * (x - 1))
    //         return 2;
    //     else
    //         return 0;
    // };

    // int l = 0,h = 1e10;
    // while(l<h)
    // {
    //     int mid = l + (h - l) / 2;
    //     int p = Check(mid);
    //     if (p == 1)
    //     {
    //         if(mid==1e6)
    //         {
    //             break;
    //         }
    //         cout << "Y ";
    //         double a = (mid * mid) / (mid - 1),b=d/a;

    // cout << fixed << setprecision(9);
    //         cout << a / 1e6 << " " << b / 1e6 << endl;

    //     }
    //     else if(p==2)
    //     {
    //         l = mid + 1;
    //     }
    //     else
    //     {
    //         h = mid - 1;
    //     }
    // }

    // cout << "N" << endl;
    cout << fixed << setprecision(9);
    if (d == 0)
    {
        cout << "Y " << 0.0 << " " << 0.0 << endl;
        return;
    }
    if (d < 4)
    {
        cout << "N" << endl;
        return;
    }

    double D = sqrt(d * (d - 4));
    double a = (d + D) / 2.0;
    double b = (d - D) / 2.0;

    cout << "Y " << a << " " << b << endl;

    // take help of editorial...

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