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
string minnum(string s)
{
    int sum = 0;
    s = "0" + s;
    for (int i = 0; i < s.size(); i++)
    {
        sum += (s[i] - '0');
        int j = i;
        if (sum == n)
        {
            j++;
            while (j < s.size() && s[j] == '0')
                j++;
            if (j >= s.size())
            {
                return s;
            }
        }
        j = i;
        if (sum >= n)
        {
            while (j < s.size())
            {
                s[j] = '0';
                j++;
            }
            i--;
            while (i >= 0 && s[i] == '9')
            {
                s[i] = '0';
                i--;
            }
            s[i] = s[i] + 1;
            return s;
        }
    }
    return s;
}
int to_int(string s)
{
    int ans = 0;
    for (auto it : s)
    {
        ans = ans * 10 + (it - '0');
    }
    return ans;
}
void solve()
{
    int i, j, k, s;

    cin >> s >> n;
    string str = to_string(s);
    string mnno = minnum(str);

    int finno = to_int(mnno);
    cout << finno - s << endl;

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