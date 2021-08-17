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
    string s;
    cin >> s;
    set<char> st;
    for (auto it : s)
        st.insert(it);
    int sz = st.size();

    auto check = [&](int x)
    {
        set<char> st;
        map<char, int> m;
        for (i = 0; i < x; i++)
            st.insert(s[i]), m[s[i]]++;
        // cout << st.size() << endl;
        j = 0;
        for (; i < n; i++)
        {
            // if (i == 10)
            // {
            //     for (auto it : m)
            //         cout << it.F << "->" << it.S << endl;

            //     cout << st.size() << endl;
            // }
            // cout << st.size() << "->";
            // for(auto it:st)
            //     cout << it << ","<<m[it]<<" ";
            // cout << " j "<<j << s[j];
            if (sz == st.size())
                return 1;
            if (m[s[j]] == 1)
            {
                //cout << "in";
                st.erase(s[j]);
            }
            
            m[s[j]]--;
            j++;

            st.insert(s[i]);
            m[s[i]]++;
            //cout << endl;
        }
        if (sz == st.size())
            return 1;
        return 0;
    };
    // cout << check(3) << endl;
    int l = 1, h = n, ans;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        //cout << mid << endl;
        if (check(mid))
        {
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
    // map<char, int> m;
    // for(auto it:s)
    //     m[it]++;

    // for (i = 0; i < n;i++)
    // {
    //     if(m[s[i]]==1)
    //         break;
    //     else
    //         m[s[i]]--;
    // }
    // for (j = n - 1; j >= i&&j >= 0;j--)
    // {
    //     if(m[s[j]]==1)
    //         break;
    //     else
    //         m[s[j]]--;
    // }
    // int ans = j - i + 1;

    // m.clear();
    // for (auto it : s)
    //     m[it]++;
    // for (j = n - 1; j > i && j >= 0; j--)
    // {
    //     if (m[s[j]] == 1)
    //         break;
    //     else
    //         m[s[j]]--;
    // }
    // for (i = 0; i < n; i++)
    // {
    //     if (m[s[i]] == 1)
    //         break;
    //     else
    //         m[s[i]]--;
    // }
    // ans = min(j - i + 1, ans);
    // cout << ans << endl;

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