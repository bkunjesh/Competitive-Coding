//@ikung
#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
// const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k, ans = 0;

    cin >> n >> k;
    vector<int> a(n + 1), mxind(n + 2, n + 1);
    map<int, int> pro; //product,index
    map<int, int> no_pro;
    rep(i, n)
    {
        cin >> a[i];
        k = a[i];
        // a[i] = 9999991;
        int oddpro = 1;
        if(no_pro[a[i]]==0)
        {
            for (j = 2; j * j <= a[i]; j++)
            {
                int cnt = 0, d = j;
                while (a[i] % d == 0)
                    cnt++, a[i] /= d;
                if (cnt % 2)
                    oddpro *= j;
            }
            if (a[i] > 1)
                oddpro *= a[i];
            no_pro[k] = oddpro;
        }
        else
            oddpro = no_pro[k];

        mxind[pro[oddpro]] = i;
        pro[oddpro] = i;
    }

    j = mxind[1];

    for (i = 1; i <= n; i++)
    {
        // cout << mxind[i] << " ";
        j = min(j, mxind[i]);
        if (j == i + 1)
            ans++, j = mxind[i + 1];
    }
    cout << ans << endl;

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