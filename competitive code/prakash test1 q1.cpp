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

vector<int> solution(vector<int> &a, int f, int m)
{
    vector<int> ans;
    int n = a.size(), i, j, k;
    int sum = m * (f + n);
    for (auto x : a)
        sum -= x;

    if (sum >= f && sum <= 6 * f)
    {
        int x = sum / f;
        int y = sum % f;
        int cnt = 0;
        while (cnt < y)
        {
            ans.push_back(x + 1);
            cnt++;
        }
        while (cnt < f)
        {
            ans.push_back(x);
            cnt++;
        }
    }
    else
    {
        ans.push_back(0);
    }
    for (auto x : ans)
        cout << x << " ";
    return ans;
}

void solve()
{
    int i, j, k;
    vector<int> a = {6, 1};
    solution(a, 1, 6);

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