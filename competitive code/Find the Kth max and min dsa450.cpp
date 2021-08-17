//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;
int partition(vector<int> &a, int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
        if (a[i] == x)
            break;
    swap(a[i], a[r]);
    i = l;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= a[r])
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}
int findMedian(vector<int> &a, int l, int p = 5)
{
    sort(a.begin() + l, a.begin() + l + p);
    return a[l + p / 2];
}
int getPivot(vector<int> &a, int l, int r)
{
    // int mid = (l + r) / 2;
    // int x = a[mid];
    // return x;
    if ((r - l + 1) < 5)
        return findMedian(a, l, (r - l + 1) % 5);

    vector<int> median;
    int i=l;
    for (i = l; i + 5 <= r; i += 5)
    {
        median.push_back(findMedian(a, i, 5));
    }
    if (i <= r)
        median.push_back(findMedian(a, i, (r - l + 1) % 5));
    return getPivot(median, 0, median.size() - 1);
}

int kthSmallest(vector<int> &a, int l, int r, int k)
{
    // if (r - l + 1 < k)
    //     return INT_MAX;
    if (l > r)
        return INT_MAX;

    int x = getPivot(a, l, r);

    int index = partition(a, l, r, x);

    if (index + 1 == k)
        return a[index];

    else if (index + 1 < k)
    {
        return kthSmallest(a, index + 1, r, k);
    }
    else
    {
        return kthSmallest(a, l, index - 1, k);
    }
}

void solve()
{
    int i, j, k;
    cin >> n >> k;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    cout << kthSmallest(a, 0, n - 1, k) << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif