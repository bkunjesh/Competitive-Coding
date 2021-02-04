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

long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long sum = 0;
    long long ans = 0;
    vector<long long> v;

    if (n == 0)
        return 0;
    else if (n == 1)
        return arr[0];
    for (long long i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() != 1)
    {

        long long a = pq.top();
        pq.pop();
        sum = a + pq.top();
        cerr << a << " " << pq.top() << " " << pq.size() << endl;
        pq.push(sum);
        v.push_back(sum);
        pq.pop();
    }
    for (long long i = 0; i < v.size(); i++)
        ans = ans + v[i];
    return ans;
}

void solve()
{
    int i, j, k;
    cin >> n;
    int a[n];
    f(i, n) cin >> a[i];
    cout << minCost(a, n) << endl;

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