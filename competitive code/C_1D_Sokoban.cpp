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

int getans(vector<int> box, vector<int> special)
{
    int ans = 0, goodTill = 0, val = 0;

    for (auto it : box)
    {
        if (binary_search(special.begin(), special.end(), it))
        {
            val++;
        }
    }

    goodTill = 0;
    int i = 0;


    for (auto it : special)
    {
        if (binary_search(box.begin(), box.end(), it))
        {
            goodTill++;
        }

        int temp = val - goodTill;

        int boxCnt = abs(box.begin()-upper_bound(box.begin(),box.end(),it));


        int newgood = 0;

        newgood = abs(lower_bound(special.begin(), special.end(), it - boxCnt)-lower_bound(special.begin(), special.end(), it));


        if (!binary_search(special.begin(), special.end(), it-boxCnt))
            newgood++;
            // cout << newgood << " ";
            temp += newgood;
        ans = max(ans, temp);

        i++;
    }

    return ans;
}

int n;
void solve()
{
    int i, j, k, m, ans1 = 0, ans2 = 0;

    cin >> n >> m;
    vector<int> a(n), b(m);
    f(i, n) cin >> a[i];
    f(i, m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    vector<int> box, special;

    f(i, n) j = (a[i] > 0) ? box.push_back(a[i]), 1 : 1;
    f(i, m) j = (b[i] > 0) ? special.push_back(b[i]), 1 : 1;

    sort(box.begin(), box.end());
    sort(special.begin(), special.end());

    ans1 = getans(box, special);

    vector<int> box2, special2;


    f(i, n) j = (a[i] < 0) ? box2.push_back(-a[i]), 1 : 1;
    f(i, m) j = (b[i] < 0) ? special2.push_back(-b[i]), 1 : 1;

    sort(box2.begin(), box2.end());
    sort(special2.begin(), special2.end());
    
    ans2 = getans(box2, special2);

    int ans = ans1 + ans2;
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