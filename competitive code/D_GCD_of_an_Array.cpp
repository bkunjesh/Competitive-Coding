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

// int power(int a, int b)
// {
//     int res = 1;
//     while (b)
//     {
//         if (b % 2)
//             b--, res = (res%mod * a%mod)%mod;
//         else
//             b = b / 2, a =(a%mod*a%mod)%mod;
//     }
//     return res%mod;
// }

// void solve()
// {
//     int i, j, k, q;

//     cin >> n >> q;
//     vector<int> a(n + 1);
//     rep(i, n) cin >> a[i];
//     int ans = a[0];
//     f(i, n) ans = __gcd(ans, a[i]);

//     map<int, multiset<pair<int, int>>> m; //prime->{cnt,index}

//     rep(i, n)
//     {
//         int y = a[i];
//         for (j = 2; j * j <= a[i]; j++)
//         {
//             if (y % j == 0)
//             {
//                 int cnt = 0, div = 1;
//                 while (y % j == 0)
//                 {
//                     div *= j;
//                     y /= j;
//                     cnt++;
//                 }
//                 for (auto it : m[j])
//                 {
//                     if (it.S == i)
//                     {
//                         cnt += it.F;
//                         m[j].erase(it);
//                         break;
//                     }
//                 }
//                 m[j].insert({cnt, i});
//             }
//         }
//         if (y > 1)
//         {
//             j = y;
//             if (y % j == 0)
//             {
//                 int cnt = 0, div = 1;
//                 while (y % j == 0)
//                 {
//                     div *= j;
//                     y /= j;
//                     cnt++;
//                 }
//                 for (auto it : m[j])
//                 {
//                     if (it.S == i)
//                     {
//                         cnt += it.F;
//                         m[j].erase(it);
//                         break;
//                     }
//                 }
//                 m[j].insert({cnt, i});
//             }
//         }
//     }

//     while (q--)
//     {
//         int y, x, ind;
//         cin >> ind >> x;
//         y = x;
//         for (j = 2; j * j <= y; j++)
//         {
//             if (x % j == 0)
//             {
//                 int cnt = 0, div = 1;

//                 while (x % j == 0)
//                 {
//                     div *= j;
//                     x /= j;
//                     cnt++;
//                 }
//                 int prev = 0;

//                 for (auto it : m[j])
//                 {
//                     if (it.S == ind)
//                     {
//                         prev = it.F;
//                         m[j].erase(it);
//                         break;
//                     }
//                 }

//                 {
//                     m[j].insert({cnt + prev, ind});
//                     if (m[j].size() == n && m[j].begin()->F != prev)
//                     {
//                         int pw = power(j, (m[j].begin()->F));
//                         ans = ((ans % mod) * (pw % mod)) % mod;
//                     }
//                 }
//             }
//         }

//         if (x > 1)
//         {
//             j = x;
//             if (x % j == 0)
//             {
//                 int cnt = 0, div = 1;

//                 while (x % j == 0)
//                 {
//                     div *= j;
//                     x /= j;
//                     cnt++;
//                 }
//                 int prev = 0;

//                 for (auto it : m[j])
//                 {
//                     if (it.S == ind)
//                     {
//                         prev = it.F;
//                         m[j].erase(it);
//                         break;
//                     }
//                 }

//                 {
//                     m[j].insert({cnt + prev, ind});
//                     if (m[j].size() == n && m[j].begin()->F != prev)
//                     {
//                         int pw = power(j, (m[j].begin()->F));
//                         ans = ((ans % mod) * (pw % mod)) % mod;
//                     }
//                 }
//             }
//         }

//         // for (auto prime : m)
//         // {
//         //     cout << prime.F << ": ";
//         //     for (auto pr : prime.S)
//         //     {
//         //         cout << "{" << pr.F << "," << pr.S << "},";
//         //     }
//         //     cout << endl;
//         // }

//         cout << ans << endl;
//     }

//     return;
// }

// signed main()
// {
//     fast int t = 1, i, j, k;
//     // cin >> t;
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

typedef long long ll;

int const maxn = 2e5 + 5, max_val = 2e5 + 5;
ll mod = 1e9 + 7, ans = 1;
int nxt[max_val], n;
multiset<int> cnt[max_val];
map<int, int> cnt_divisor[maxn];

void add(int i, int x)
{
    while (x != 1)
    {
        int div = nxt[x], add = 0;
        while (nxt[x] == div)
            add++, x = x / nxt[x];

        int lst = cnt_divisor[i][div];
        cnt_divisor[i][div] += add;
        int lst_min = 0;
        if ((int)cnt[div].size() == n)
        {
            lst_min = (*cnt[div].begin());
        }
        if (lst != 0)
        {
            cnt[div].erase(cnt[div].find(lst));
        }
        cnt[div].insert(lst + add);
        if ((int)cnt[div].size() == n)
        {
            for (int j = lst_min + 1; j <= (*cnt[div].begin()); ++j)
            {
                ans = ans * (ll)div % mod;
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, l, x;
    cin >> n >> q;

    for (int i = 2; i < maxn; ++i)
    {
        if (nxt[i] == 0)
        {
            nxt[i] = i;
            if (i > 10000)
                continue;
            for (int j = i * i; j < maxn; j += i)
            {
                if (nxt[j] == 0)
                    nxt[j] = i;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        add(i, x);
    }

    for (int i = 1; i <= q; ++i)
    {
        cin >> l >> x;
        add(l, x);
        cout << ans << '\n';
    }

    return 0;
}
