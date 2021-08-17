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
    int i, j, k;

    cin >> n;
    vector<int> s;
    f(i, n) cin >> j, s.push_back(j);
    sort(s.begin(), s.end(), greater<int>());
    // set<int, greater<int>> s;
    // f(i, n) cin >> j, s.insert(j);
    // for (auto it : s)
    // {
    //     cout << it << " ";
    // }
    auto find = [&](int x)
    {
        f(p, s.size())
        {

            if (s[p] == x)
                return 1;
        }
        return 0;
    };
    for (i = 0; i < s.size(); i++)
    {
        // auto it2 = it;
        for (j = i + 1; j < s.size(); j++)
        {
            // dbg(i, j, s[i], s[j], s.size());
            if (!find(abs(s[i] - s[j])))
            {
                s.push_back(abs(s[i] - s[j]));
                sort(s.begin(), s.begin() + s.size(), greater<int>());
                i = -1;
                break;
                // f(p, s.size())
                // {
                //     cout << s[p] << " ";
                // }
                // cout << endl;
                // return;
            }
            if (s.size() > 300)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    // for (auto it = s.begin(); it != s.end(); it++)
    // {
    //     auto it2 = it;
    //     for (++it2; it2 != s.end(); it2++)
    //     {
    //         dbg(*it, *it2);
    //         if (s.find(abs((*it) - (*it2))) == s.end())
    //         {
    //             s.insert(abs((*it - *it2)));
    //         }
    //         if (s.size() > 300)
    //         {
    //             cout << "NO" << endl;
    //             return;
    //         }
    //     }
    // }
    cout << "YES" << endl;
    cout << s.size() << endl;
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;
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