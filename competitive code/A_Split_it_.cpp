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
//     string s;
//     cin >> s;
//     // if (k == 0)
//     // {
//     //     cout << "YES" << endl;
//     //     return;
//     // }
//     if (n < (2 * k + 1))
//     {
//         cout << "NO" << endl;
//         return;
//     }
//     int l, r;

//     if (n % 2)
//         l = (n) / 2, r = (n) / 2;
//     else
//         l = (n / 2) - 1, r = (n) / 2;

//     // cout << l << " " << r << " ";
//     string left = s.substr(0, k), right = s.substr(n-k, k);
//     reverse(right.begin(), right.end());

//     if (left == right)
//     {
//         cout << "YES" << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }

//     // while (l >= 0 && r < n && s[l] == s[r])
//     // {
//     //     l--, r++;
//     // }
//     // if (l < 0 && r >= n)
//     // {
//     //     cout << "YES" << endl;
//     // }
//     // else
//     // {
//     //     cout << "NO" << endl;
//     // }

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
// //#ifndef ONLINE_JUDGE
// //freopen("input.txt", "r", stdin);
// //freopen("output.txt", "w", stdout);
// //#endif

#include <bits/stdc++.h>
using namespace std;
// #define int long long //delete if causing problems
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
// const int inf = 1e18;
int power(int a, int b);

void m(int *p)
{
    for (int i = 0; i < 4; i++)
        cout << p[i] << " ";
}

signed main()
{
    fast int t = 1;
    //cin >> t;
    while (t--)
    {
        int a[5] = {0, 2, 5};

        m(&a);
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