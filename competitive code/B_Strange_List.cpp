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
    int i, j, k=1e10,s=0;
    int x;

    cin >> n >> x;
    int a[n], power[n];
    memset(power, 0, sizeof(power));
    f(i, n) cin >> a[i],s+=a[i];
    f(i, n)
    {
        int cnt = 0;
        int temp = a[i];
        while (temp % x == 0)
        {
            cnt++;
            temp /= x;
        }
        power[i] = cnt;
        k = min(k, cnt);
    }

    {
        int sum = s+s*k, flag = 1;
        f(i, n)
        {
            power[i] -= k;
            if(power[i]>0)
                sum += a[i];
            else
                break;
        }
        cout << sum << endl;
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