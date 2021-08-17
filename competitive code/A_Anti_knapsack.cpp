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

    int done[n + 1];
    vector<int> ans;
    memset(done, 0, sizeof(done));

    for (i = 1; i <= n; i++)
    {
        if (i > k)
            ans.push_back(i);
        else if (i < k)
        {
            int flag = 1;

            if (done[k - i] == 0)
            {
                for (j = 1; j <= k; j++)
                {
                    if (done[j])
                    {
                        if (j + i == k)
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    ans.push_back(i);
                    done[i] = 1;
                    for (auto it : ans)
                    {
                        if(it==i)
                            continue;
                        done[i + it] = 1;
                    }
                }
            }
        }
    }

    // for (i = 1; i <= n; i++)
    // {
    //     if (done[i] == 0)
    //     {
    //         if (i > k)
    //             ans.push_back(i);
    //         if (i < k && done[k - i] == 0)
    //         {
    //             done[i] = 1;
    //             for (j = 0; j <= i; j++)
    //             {
    //                 if (done[j] == 1)
    //                 {
    //                     if(j+i<=k) done[j + i] = 1;
    //                 }
    //             }
    //             ans.push_back(i);
    //         }
    //     }
    // }
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    // int ans = 0;
    // ans = (n - k);
    // int bonus = k - 1;
    // if(bonus % 2==1)
    //     ans++;
    // ans += (bonus / 2);

    // int val = (k - (bonus / 2));

    // if (bonus % 2 == 1)
    //     val--;

    // cout << ans << endl;
    // for (i = val; i <= n;i++)
    // {
    //     if(i==k)
    //         continue;
    //     cout << i << " ";
    // }
    // cout << endl;
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