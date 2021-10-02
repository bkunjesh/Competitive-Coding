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

int n, m;

int getans(int x, int y, vector<int> &aones, vector<int> &bones, vector<int> &asuff, vector<int> &bsuff)
{

    int indx = lower_bound(aones.begin(), aones.end(), x) - aones.begin();
    int indy = lower_bound(bones.begin(), bones.end(), y) - bones.begin();

    int valx = (indx >= aones.size()) ? 0 : asuff[indx] - (x - 1) * (aones.size() - indx);
    int valy = (indy >= bones.size()) ? 0 : bsuff[indy] - (y - 1) * (bones.size() - indy);

    // dbg(indx, indy, valx, valy);
    return valx * valy;
}

void solve()
{
    int i, j, k, ans = 0;

    int m;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), aones, bones;
    f(i, n) cin >> a[i];
    f(i, m) cin >> b[i];
    int cnt = 0;
    f(i, n)
    {
        if (a[i] == 0 && cnt != 0)
        {
            aones.push_back(cnt);
            cnt = 0;
        }
        else if (a[i] == 1)
        {
            cnt++;
            if (i == n - 1)
            {
                aones.push_back(cnt);
                cnt = 0;
            }
        }
    }

    cnt = 0;
    f(i, m)
    {
        if (b[i] == 0 && cnt != 0)
        {
            bones.push_back(cnt);
            cnt = 0;
        }
        else if (b[i] == 1)
        {
            cnt++;
            if (i == m - 1)
            {
                bones.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(aones.begin(), aones.end());
    sort(bones.begin(), bones.end());

    vector<int> asuff = aones, bsuff = bones;
    // dbg(asuff.size(), bsuff.size());
    for (i = asuff.size() - 2ll; i >= 0; i--)
    {
        // dbg(i);
        asuff[i] += asuff[i + 1];
    }
    for (i = bsuff.size() - 2ll; i >= 0; i--)
    {
        bsuff[i] += bsuff[i + 1];
    }

    for (i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            int x = i, y = k / i;
            int val1 = getans(x, y, aones, bones, asuff, bsuff), val2 = -1;
            ans += val1;
            if (x != y)
            {
                val2 = getans(y, x, aones, bones, asuff, bsuff);
                ans += val2;
            }
            // dbg(x, y, val1, val2);
        }
    }

    cout << ans << endl;

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