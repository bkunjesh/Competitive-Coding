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

vector<pair<int,int>> printDivisors(int n)
{
    vector<pair<int,int>> fac;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while(n%i==0)
                n /= i, cnt++;
            fac.push_back({i,cnt});
        }
    }
    if(n>1)
        fac.push_back({n,1});
    return fac;
}

int n;

void solve()
{
    int i, j, k, p, q;
    cin >> p >> q;
    if (p%q!=0)
    {
        cout << p << endl;
        return;
    }
    int ans = 0;
    auto qfac = printDivisors(q);
    for(auto it:qfac)
    {
        int pfq = it.F;
        int pi = p;
        int cnt = 0;
        while(pi%pfq==0)
            pi /= pfq, cnt++;
        int temp = 1;
        while(cnt>=it.S)
            temp *= pfq, cnt--;
        ans = max(ans, p / temp);
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