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
    int i, j, k, q;
    cin >> n >> q;
    vector<int> a[3];
    a[0].assign(n + 1, 0);
    a[1].assign(n + 1, 0);

    int ans = 0;
    while (q--)
    {
        int r, c;
        cin >> r >> c;
        r--, c--;
        int temp = (a[r][c] == 0 ? +1 : -1);
        a[r][c] = 1 - a[r][c];
        for (i = -1; i < 2;i++)
        {
            if(c+i<0||c+i>=n)
                continue;
            if(a[1-r][c+i]==1)
                ans += temp;
        }
        if(ans==0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
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