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
    int i, j, k;

    cin >> n;
    vector<int> a(n), cnt(n + 1, 0), ind, minimal, maximal;
    f(i, n)
    {
        cin >> a[i], cnt[a[i]] = 1;
        if (i == 0)
            continue;
        if (a[i] == a[i - 1])
            ind.push_back(i);
    }
    vector<int> notpresent;
    rep(i, n) if (!cnt[i]) notpresent.push_back(i);
    minimal = a, maximal = a;
    for (i = 0; i < ind.size(); i++)
    {
        minimal[ind[i]] = notpresent[i];
    }
    // sort(notpresent.begin(), notpresent.end(), greater<int>());
    // for (i = 0; i < ind.size(); i++)
    // {
    //     maximal[ind[ind.size()-i-1]] = notpresent[i];
    // }

    f(i, n) cout << minimal[i] << " ";
    cout << endl;
    // 

    set<int> rem_no;
    rep(i, n) if(!cnt[i]) rem_no.insert(i);
    int count = 0;
    for (i = 1; i < n;i++)
    {
        if(a[i]==a[i-1])
        {
            j = i - 1;
            while(j<n&&a[i]==a[j])
            {
                auto it = rem_no.lower_bound(a[j]);
                it--;
                maximal[i] = *it;
                rem_no.erase(it);
                i++;
            }
        }
    }
    f(i, n) cout << maximal[i] << " ";
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif