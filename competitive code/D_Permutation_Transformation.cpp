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
int depth[105];

vector<int> a(N);

void findDepth(int start, int end, int d)
{

    if (start >= end || end < 0 || start >= n)
    {
        // if (start == end)
        // {
        //     cout << start << " " << end << " " << d << " " << endl;
        //     depth[start] = d;
        // }
        return;
    }

    int mxEleInd = max_element(a.begin() + start, a.begin() + end) - a.begin();

    
    depth[mxEleInd] = d;

    //cout << start << " " << end << " " << d << " " << mxEleInd <<" "<< depth[mxEleInd] << " " << endl;
    findDepth(start, mxEleInd, d + 1);
    findDepth(mxEleInd + 1, end, d + 1);
}

void solve()
{
    int i, j, k;

    cin >> n;
    f(i, n) cin >> a[i];
    memset(depth, 0, sizeof(depth));
    findDepth(0, n, 0);

    for (i = 0; i < n; i++)
        cout << depth[i] << " ";
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