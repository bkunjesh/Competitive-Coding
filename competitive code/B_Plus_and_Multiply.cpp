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

    int a, b;
    cin >> n >> a >> b;
    vector<int> temp;
    if (n == 1)
    {
        cout << "Yes" << endl;
        return;
    }
    int x = 1;
    while (temp.size() < 30 && x <= 1e9)
    {
        temp.push_back(x);
        x *= a;
    }
    for (auto p : temp)
    {
        // cout << p << endl;
        if ((n - p) >= 0 && ((n - p) % b == 0))
        {
            cout << "Yes" << endl;
            return;
        }
    }
    // while(n>0)
    // {
    //     while(n%a==0)
    //         n /= a;
    //     if(n==1)
    //     {
    //         cout << "Yes" << endl;
    //         return;
    //     }
    //     n -= b;
    //     if (n == 1)
    //     {
    //         cout << "Yes" << endl;
    //         return;
    //     }
    // }
    // if (n == 1)
    // {
    //     cout << "Yes" << endl;
    //     return;
    // }
    // else
    {
        cout << "No" << endl;
    }

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