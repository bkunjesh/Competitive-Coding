//@CodesUp
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
int N = 200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    unordered_map<char, unordered_map<char, int>> m;
    map<int, int> ma, mb;
    f(i, n)
    {
        m[b[i]][a[i]]++;
        ma[a[i] - 'a']++;
        mb[b[i] - 'a']++;
    }
    f(i, 26)
    {
        if (abs(ma[i] - mb[i]) % k || mb[i] > ma[i])
        {
            cout << "No" << endl;
            return;
        }
        ma[i + 1] = ma[i + 1] + (ma[i] - mb[i]);
    }
    cout << "Yes" << endl;

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