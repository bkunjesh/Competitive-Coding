//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j = 0, k, q;

    cin >> n >> q;
    string s;
    cin >> s;
    j = 0;
    i = 1;
    int best = 0;

    f(i, n)
    {
        int oth = s[i % (best + 1)];
        int lkw = s[i];
        if (lkw > oth)
            break;
        if (lkw < oth)
            best = i;
    }

    f(i, q)
    {
        cout << s[i % (best + 1)];
    }
    // string str = s[0];

    // //while(i<n)
    // {
    //     for (; i < n - 1; i++)
    //     {
    //         if (s[i] >= s[0])
    //         {
    //             j = i;
    //             k = 0;
    //             int p = i;
    //             if (s[k] == s[p])
    //             {
    //                 while (p < n - 1 && s[k] >= s[p])
    //                 {
    //                     k++, p++;
    //                 }
    //                 if (p >= n - 1)
    //                 {
    //                     j = p + 1;
    //                 }
    //                 break;
    //             }
    //             if (s[i] > s[0])
    //                 break;
    //         }
    //     }
    //     // if (s[i] == s[0])
    //     // {
    //     //     k = 0;
    //     //     while (i < n && s[k] >= s[i])
    //     //     {
    //     //         i++, k++;
    //     //     }
    //     //     j = i;
    //     // }
    // }
    // // cout << j << " ";
    // string str = "";
    // str = s.substr(0, j);
    // if (j == 0)
    //     str = s;
    // for (i = 0; i < q; i++)
    // {
    //     cout << str[i % (str.size())];
    // }
    // cout << endl;
    // vector<string> ans;
    // for (i = 1; i <= n; i++)
    // {
    //     string str = "";
    //     string temp;
    //     str = s.substr(0, i);
    //     temp.resize(q);
    //     for (j = 0; j < q; j++)
    //     {
    //         // cout << str[i % (str.size())];
    //         temp[j] = str[j % (str.size())];
    //     }
    //     ans.push_back(temp);
    // }
    // sort(ans.begin(), ans.end());
    // cout << ans[0] << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    // cin >> t;
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