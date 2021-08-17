// //@ikung
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define fast                      \
//     ios_base::sync_with_stdio(0); \
//     cin.tie(0);
// #define f(i, k) for (int i = 0; i < k; i++)
// #define F first
// #define S second
// #define endl "\n"
// #define rep(i, n) for (int i = 1; i <= n; i++)
// #define rew(i, a, b) for (int i = a; i <= b; i++)
// #define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
// template <typename... Args>
// void logger(string vars, Args &&...values)
// {
//     cout << vars << " = ";
//     string delim = "";
//     (..., (cout << delim << values, delim = ","));
//     cout << endl;
// }

// #define mod 1000000007
// const int inf = 1e18;
// const int N = 200005;

// int n;

// void solve()
// {
//     int i, j, k;

//     int x;
//     cin >> n >> x;
//     if (n % 2 == 1 && x == 0)
//     {
//         cout << -1 << endl;
//         return;
//     }
//     int evensum = 0, oddbitcnt = 0;
//     for (i = 0; i < 31; i++)
//     {
//         if (i % 2)
//         {
//             if (n & (1 << i))
//                 oddbitcnt++;
//         }
//         else
//         {
//             evensum = evensum + (1 << i);
//         }
//     }

//     int ans = oddbitcnt;
//     cout << evensum << " ";
//     if (evensum <= x)
//     {
//         cout << ans + 1 << endl;
//         return;
//     }
//     else
//     {
//         cout << -1 << endl;
//         return;
//     }

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
#include <bits/stdc++.h>
using namespace std;
#define int long long //delete if causing problems
#define F first
#define S second
#define setbit(n) builtin_popcountll(n)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
const int inf = 1e18;
int power(int a, int b);


signed main()
{
    fast int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n, x;
        cin >> n >> x;
        int cnt = 0, temp = x;

        auto check = [&]()
        {
            for (int i = 0; i < 30; i += 2)
            {
                if ((1ll << i) & (n))
                {
                    if ((1ll << i) <= x)
                        x -= (1LL << i);
                    else
                        cnt += 2;
                }
            }
        };

        if (x >= n)
            cout << "1" << endl;
        else
        {

            if ((n % 2 == 1 && x == 0))
            {
                cout << "-1" << endl;
            }
            else
            {

                check();

                for (int i = 1; i < 30; i += 2)
                {

                    if ((1ll << i) & n)
                    {

                        if ((1ll << i) <= x)
                            x -= (1LL << i);
                        else
                            cnt++;
                    }
                }

                if (x == temp)
                    cnt--;

                cout << cnt + 1 << endl;
            }
        }
    }
    return 0;
}

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2)
            b--, res = res * a;
        else
            b = b / 2, a *= a;
    }
    return res;
}

/*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
*/