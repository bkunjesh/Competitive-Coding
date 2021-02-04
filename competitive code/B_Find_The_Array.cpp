
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
    int i, j, k,osum=0,esum=0;

    cin >> n;
    int a[n], b[n];
    f(i, n) cin >> a[i], b[i] = a[i],(i%2==1)?osum+=a[i]:esum+=a[i];

    if(osum<(osum+esum)/2) {f(i, n) if (i % 2) b[i] = 1;}
    else {f(i, n) if (i % 2==0) b[i] = 1;}

    f(i, n) cout << b[i] << " ";
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