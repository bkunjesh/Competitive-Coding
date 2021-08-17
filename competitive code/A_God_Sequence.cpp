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

    int a, b;
    cin >> a >> b;
    vector<int> ans;

    i = 1;
    while (a > 1 && b > 1)
    {
        ans.push_back(i);
        ans.push_back(-i);
        b--, a--, i++;
    }
    int sum = 0;
    if (a > 1)
    {
        while (a > 0)
        {
            ans.push_back(i);
            sum += i;
            a--;
            i++;
        }
        ans.push_back(-sum);
    }
    else
    {
        while (b > 0)
        {
            ans.push_back(-i);
            sum += i;
            b--;
            i++;
        }
        ans.push_back(sum);
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
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