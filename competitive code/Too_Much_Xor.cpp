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

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    else if (n == 2)
    {
        if ((a[0] ^ a[1]) > 0)
        {
            cout << 0 << endl;
            return;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
    else
    {
        j = -1;
        map<int, int> m;
        vector<vector<int>> ans;
        //i i+2 i+1
        vector<int> v(3);
        for (i = 0; i < n; i++)
        {
            if (m.find(a[i]) != m.end())
            {
                int ind = m[a[i]];
                if ((i - ind) == 1)
                {
                    if (n == 3)
                    {
                        cout << -1 << endl;
                        return;
                    }
                    int x, y;
                    if (i - 2 >= 0)
                        x = i - 2, y = i + 1;
                    else
                        x = i + 1, y = i + 2;

                    v[0] = i, v[1] = ind, v[2] = x;
                    ans.push_back(v);

                    v[0] = i, v[1] = ind, v[2] = y;
                    ans.push_back(v);

                    if (y - x == 1)
                    {
                        v[0] = x, v[1] = y, v[2] = i - 1;
                        ans.push_back(v);
                        j = i - 1;
                    }
                    else
                    {
                        v[0] = x, v[1] = y, v[2] = i;
                        ans.push_back(v);
                        j = i - 2;
                    }
                    break;
                }
                else
                {
                    //i ind i-1
                    v[0] = i, v[1] = ind, v[2] = i - 1;
                    ans.push_back(v);
                    //i i-1 i-2
                    v[0] = i, v[1] = i - 1, v[2] = i - 2;
                    ans.push_back(v);
                    j = i - 2;
                    break;
                }
            }
            else if (a[i] != 0 && m.find(0) != m.end())
            {
                // int ind = m[0];

                // if((ind-i)>2)
                // {
                //     v[0] = i, v[1] = ind, v[2] = i-2;
                //     ans.push_back(v);
                //     //1 2 0 8 9 2 0 2
                // }

                // if ((i - ind) == 1)
                // {
                //     if (n == 3)
                //     {
                //         cout << -1 << endl;
                //         return;
                //     }
                //     int x, y;
                //     if (i - 2 >= 0)
                //         x = i - 2, y = i + 1;
                //     else
                //         x = i + 1, y = i + 2;

                //     v[0] = i, v[1] = ind, v[2] = x;
                //     ans.push_back(v);

                //     v[0] = i, v[1] = ind, v[2] = y;
                //     ans.push_back(v);

                //     if (y - x == 1)
                //     {
                //         v[0] = x, v[1] = y, v[2] = i - 1;
                //         ans.push_back(v);
                //         j = i - 1;
                //     }
                //     else
                //     {
                //         v[0] = x, v[1] = y, v[2] = i;
                //         ans.push_back(v);
                //         j = i - 2;
                //     }
                //     break;
                // }
                // else
                // {
                //     //i ind i-1
                //     v[0] = i, v[1] = ind, v[2] = i - 1;
                //     ans.push_back(v);
                //     //i i-1 i-2
                //     v[0] = i, v[1] = i - 1, v[2] = i - 2;
                //     ans.push_back(v);
                //     j = i - 2;
                //     break;
                // }
            }
            else
                m[a[i]] = i;
            // if (a[i] == a[i + 2])
            // {
            //     j = i;
            //     break;
            // }
        }
        if (j == -1)
        {
            cout << -1 << endl;
            return;
        }

        v[0] = (j);
        v[1] = (j + 2);
        v[2] = (j + 1);
        ans.push_back(v);
        a[v[2]] = a[v[1]] ^ a[v[0]];

        for (i = 0; i < n; i++)
        {
            if (i >= j && (i - j) <= 2)
                continue;
            v[2] = i;
            v[1] = j;
            if ((i % 2) == (j % 2))
            {
                v[0] = j + 1;
            }
            else
                v[0] = j + 2;
            ans.push_back(v);
            a[v[2]] = a[v[1]] ^ a[v[0]];
        }
        for (auto it : a)
            cout << it << " ";
        cout << endl;
        cout << ans.size() << endl;
        for (auto v : ans)
        {
            for (auto it : v)
                cout << it + 1 << " ";
            cout << endl;
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