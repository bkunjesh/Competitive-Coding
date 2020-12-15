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

    cin >> n;
    vector<string> a(n);
    f(i, n) cin >> a[i];
    for (i = 0; i < n; i = i + 3)
    {
        for (j = 0; j < n; j = j + 3)
        {
            //check
            
            

            if (a[i][j] == 'X')
                a[i][j] = 'O';

            if (i + 1 < n && j + 1 < n && a[i + 1][j + 1] == 'X')
                a[i + 1][j + 1] = 'O';
            if (i + 2 < n && j + 2 < n && a[i + 2][j + 2] == 'X')
                a[i + 2][j + 2] = 'O';
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
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