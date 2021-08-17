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

int n, k;
int cnt[26];
int need(char ch)
{
    return (k - cnt[ch - 'a'] % k) % k;
}
void solve()
{
    int i, j, sum = 0;
    f(i, 26) cnt[i] = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n % k != 0)
    {
        cout << -1 << endl;
        return;
    }

    for (auto it : s)
        cnt[it - 'a']++;
    // cout << s << endl;
    for (auto ch = 'a'; ch <= 'z'; ch++)
    {
        sum += (need(ch));
        // cout << ch << "-" << cnt[ch - 'a'] << "-" << need(ch) << " ";
    }
    // cout << endl;
    if (sum == 0)
    {
        cout << s << endl;
        return;
    }

    for (i = n - 1; i >= 0; i--)
    {
        sum -= need(s[i]);
        cnt[s[i] - 'a']--;
        sum += need(s[i]);
        // cout << i << " " << sum << endl;
        for (char j = s[i] + 1; j <= 'z'; j++)
        {
            sum -= need(j);
            cnt[j - 'a']++;
            sum += need(j);

            if (sum <= ((n - 1) - i))
            {
                string ans = s.substr(0, i), temp = "";
                ans += j;
                char c = 'a';
                while (c <= 'z')
                {
                    int x = need(c);
                    while (x--)
                        temp += c;
                    c++;
                }
                int extra = (n - 1) - (i + temp.size());
                while (extra--)
                    temp = 'a' + temp;
                cout << ans + temp << endl;
                return;
            }

            sum -= need(j);
            cnt[j - 'a']--;
            sum += need(j);
        }
    }

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