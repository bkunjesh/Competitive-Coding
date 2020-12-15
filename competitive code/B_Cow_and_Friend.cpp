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
    int i, j, k, x;

    cin >> n >> x;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    if (binary_search(a.begin(), a.end(), x))
    {
        cout << 1 << endl;
        return;
    }
    else
    {
        if (a[n - 1] > x)
        {
            cout << 2 << endl;
            return;
        }
        else
        {
            if(x%a[n-1]!=0)
            cout << x / a[n - 1] + 1 << endl;
            else
            {
                cout << x / a[n - 1] << endl;
            }
            
            return;
        }
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