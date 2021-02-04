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
vector<int> prime;
void make_prime_vect()
{
    int MAXN = 4000000;
    vector<int> br(MAXN + 1, 0);
    for (int i = 2; i <= MAXN; i++)
    {
        if (br[i] == 0)
        {
            for (int j = i * 2; j <= MAXN; j = j + i)
            {
                br[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAXN; i++)
        if (br[i] == 0)
            prime.push_back(i);
}
void solve()
{
    int i, j = 0, k;
    cin >> n;
    int ocnt = 0, tcnt = 0;
    f(i, n) cin >> j, (j == 1) ? ocnt++ : tcnt++;
    int sum = ocnt + tcnt * 2, currsum = 0;
    j = 0;
    vector<int> ans;
    while (prime[j] <= sum)
    {
        int diff = prime[j] - currsum;
        int rtcnt = diff / 2, rocnt = diff % 2;
        if (rtcnt > tcnt)
        {
            rocnt += (rtcnt - tcnt) * 2;
            rtcnt = tcnt;
        }
        j++;

        if (rocnt > ocnt)
            continue;
        tcnt -= rtcnt;
        ocnt -= rocnt;
        while (rtcnt--)
            ans.push_back(2);
        while (rocnt--)
            ans.push_back(1);

        currsum = prime[j - 1];
    }

    while (tcnt>0)
        ans.push_back(2),tcnt--;
    while (ocnt)
        ans.push_back(1),ocnt--;

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    make_prime_vect();
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}