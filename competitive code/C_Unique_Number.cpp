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
const int N = 200005;

int n;

void solve()
{
    int i, j, k, x;
    cin >> x;
    int arr[10];
    memset(arr, 0, sizeof(arr));
    if (x <= 9)
    {
        cout << x << endl;
        return;
    }
    string ans = "";
    int ptr = 9;
    while (x > ptr&&ptr>0)
    {
        ans = to_string(ptr) + ans;
        x -= ptr;
        ptr--;
    }
    if (x > ptr || x < 1)
    {
        cout << -1 << endl;
    }
    else if (x == 0)
    {
        cout << ans << endl;
        return;
    }
    else
    {
        ans = to_string(x) + ans;
        cout << ans << endl;
    }

    return;
}

signed main()
{
    fast int t =1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}