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

    cin >> n >> k;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    // vector<int> smlind;
    // f(i, n - 1) if (a[i] < a[i + 1]) smlind.push_back(i);
    // int sum = 0;

    // for (i = 0; i < smlind.size(); i++)
    // {
    //     int ind = smlind[i];
    //     int diff = a[ind + 1] - a[ind];
    //     sum += diff;
    //     if (sum >= k)
    //     {
    //         cout << ind + 1 << endl;
    //         return;
    //     }
    // }
    // cout << -1 << endl;

    int used = 0;
    stack<int> st;
    st.push(a[0]);
    i = 1;
    while(i<n)
    {

        if(a[i]>st.top())
        {
            int topElm = st.top();
            st.pop();
            int topcnt = 1;
            while(!st.empty()&&st.top()==topElm)
                st.pop(), topcnt++;
            int prev;
            if(st.empty())
            {
                prev = a[i];
            }
            else prev = st.top();
            if(prev>a[i])
            {
                if (used + (a[i] - topElm) * topcnt<k)
                {
                    used += (a[i] -topElm) * topcnt;
                }
                else
                {
                    int stoneleft = k - used;
                    int ans = i - stoneleft % topcnt;
                    if (stoneleft % topcnt==0)
                        ans -= topcnt;
                    cout << ans+1 << endl;
                    return;
                }
                while(topcnt--) st.push(a[i]);
                st.push(a[i]);
                i++;
            }
            else
            {
                if (used + (prev - topElm) * topcnt < k)
                {
                    used += (prev - topElm) * topcnt;
                }
                else
                {
                    int stoneleft = k - used;
                    int ans = i - stoneleft % topcnt;
                    if (stoneleft % topcnt == 0)
                        ans -= topcnt;
                    cout << ans+1 << endl;
                    return;
                }
                while(topcnt--) st.push(prev);
            }
            // int to_add=st.size()

        }
        else
        {
            st.push(a[i]);
            i++;
        }
    }
    cout << -1 << endl;

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