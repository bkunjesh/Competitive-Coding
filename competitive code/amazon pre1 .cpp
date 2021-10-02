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

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

pair<int, int> findTruckSpacePair(int truckSpace, int numPackage, vector<int> &packageSpace)
{
    vector<pair<int, int>> a;
    for (int i = 0; i < numPackage; i++)
    {
        a.push_back({packageSpace[i], i});
    }
    sort(a.begin(), a.end());
    int sumneed = truckSpace - 30;
    if (sumneed < 0)
        return make_pair(-1, -1);
    int i = 0, j = numPackage - 1;

    while (i < j)
    {
        if (a[i].first + a[j].first < sumneed)
            i++;
        else if (a[i].first + a[j].first > sumneed)
            j--;
        else if (a[i].first + a[j].first == sumneed)
            return make_pair(a[i].second, a[j].second);
    }
    return {-1, -1};
}

void solve()
{
    int i, j, k;
    vector<int> a = {1, 10, 25, 35, 60};
    auto p = findTruckSpacePair(90, 5, a);
    cout << p.first << " " << p.second << endl;

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