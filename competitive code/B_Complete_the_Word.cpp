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

    string s;
    cin >> s;
    n = s.size();
    int quecnt = 0;
    j = 0;
    map<char, int> m;

    for (i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            quecnt++;
        }
        else
        {
            if (m[s[i]] == 1)
            {
                while (s[j] != s[i])
                {
                    if (s[j] == '?')
                    {
                        quecnt--;
                    }
                    else
                    {
                        m[s[j]] = 0;
                    }
                    j++;
                }
                j++;
            }
            else
            {
                m[s[i]] = 1;
            }
        }

        if (i - j + 1 == 26)
        {

            int start = j, end = i;
            // cout << i << " " << j << endl;
            char ch = 'A';
            stack<char> st;
            while (ch <= 'Z')
            {
                if (m[ch] == 0)
                {
                    st.push(ch);
                }
                ch++;
            }
            for (k = start; k <= end; k++)
            {
                if (s[k] == '?')
                {
                    s[k] = st.top();
                    st.pop();
                }
            }
            for (k = 0; k < n; k++)
                if (s[k] == '?')
                    s[k] = 'Z';

            cout << s << endl;
            return;
        }
    }

    cout << -1 << endl;
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