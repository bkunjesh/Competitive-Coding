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

//     cin >> n;
//     int cnt = 10, cur = n + 1;
//     vector<int> ans;
//     ans.push_back(1);
//     while (cnt--)
//     {
//         for (j = 2; j * j <= cur; j++)
//         {
//             if (cur % j == 0)
//             {
//                 //j,cur/j;
//                 if (j != cur / j)
//                 {
//                     if (j < n && (cur / j) < n)
//                     {
//                         ans.push_back(j);
//                         ans.push_back(cur / j);
//                     }
//                 }
//             }
//         }
//         cur += n;
//     }
//     sort(ans.begin(), ans.end());
//     cout << ans.size() << endl;
//     for (auto it : ans)
//         cout << it << " ";
//     cout << endl;

//     return;
// }

// signed main()
// {
//     fast int t = 1, i, j, k;
//     //cin >> t;
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

    cin >> n;
    vector<int> ans;
    int pro = 1;
    rep(i, n - 1)
    {
        if (__gcd(i, n) == 1)
        {
            ans.push_back(i);
            pro = (pro * i) % n;
        }
    }

    // https://codeforces.com/blog/entry/89810?#comment-781966
    if (pro != 1)
        cout << ans.size() - 1 << endl;
    else
        cout << ans.size() << endl;

    for (auto it : ans)
    {
        // cout << it << " ";
        if (pro != 1 && it == pro)
            continue;
        cout << it << " ";
    }

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