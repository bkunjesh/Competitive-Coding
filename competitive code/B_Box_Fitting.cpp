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
    int i, j, k, sum = 0, ans = 0;
    int w;
    cin >> n >> w;
    vector<int> a(n), pow;
    map<int, int> m;
    set<int> s;
    f(i, n) cin >> a[i], sum += a[i], m[a[i]]++, s.insert(a[i]);
    int mx;
    int cnt = 1;
    f(i, 32)
    {
        if ((w) & (1 << i))
        {
            pow.push_back((1 << i));
            mx = i;
        }
    }
    // for (i = mx; i >= 0; i--)
    // {
    //     ans += (m[(1 << i)] / cnt);
    //     cnt++;
    // }

    sort(pow.begin(), pow.end(), greater<int>());
    sort(a.begin(), a.end(), greater<int>());

    while (!s.empty())
    {
        int length = w;
        while (!s.empty())
        {
            auto it = s.upper_bound(length);
            if(it==s.begin())
                break;
            it--;
            length -= *it;
            m[*it]--;
            if (m[*it] == 0)
                s.erase(it);
        }
        ans++;
    }

    // auto check = [&](int h) {
    //     if (h >= n)
    //         return 1;

    //     int ht[h];
    //     set<int> s;

    //     f(i,n)
    //     {

    //     }

    //     // return (w * h) >= sum;
    // };
    // int low = 1, high = 1e9, ans;
    // while (low <= high)
    // {
    //     int mid = low + (high - low) / 2;
    //     if (check(mid))
    //     {
    //         ans = mid;
    //         high = mid - 1;
    //     }
    //     else
    //     {
    //         low = mid + 1;
    //     }
    // }
    // i = 0;
    // j = n - 1;
    // int val = 0, ans = 0;
    // f(i, n)
    // {
    //     val += a[i];
    //     if (i == n - 1 && val > w)
    //     {
    //         ans++;
    //         ans++;
    //         break;
    //     }
    //     if (val > w)
    //     {
    //         val = a[i];
    //         ans++;
    //     }
    // }

    // while (i <= j)
    // {
    //     val = a[j];
    //     while (i < j && val + a[i] <= w)
    //     {
    //         val += a[i];
    //         i++;
    //     }
    //     j--;
    //     ans++;
    // }
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