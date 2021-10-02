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

int removeDuplicate(vector<int> &a)
{
    sort(a.begin(), a.end());
    int n = a.size();
    int i = 0, j = 0, k = 0;

    for (i = 0; i < n;)
    {
        for (; j < n; j++)
        {
            if (a[i] != a[j])
                break;
        }
        k++;
        a[k] = a[j];
        i = j;
    }
    return k;
}

void calc(int n, int m, int **lvec, int **gvec, int **a)
{
    f(i, n)
    {
        vector<int> vec;
        f(j, m) dbg(i, j);
        // f(j, m) vec.push_back(a[i][j]), dbg(i, j);
        // int len = removeDuplicate(vec);
        // f(j, m)
        // {
        //     int x = (lower_bound(vec.begin(), vec.end(), a[i][j]) - vec.begin());
        //     lvec[i][j] = x;
        //     gvec[i][j] = len - (x + 1);
        // }
    }
}
int n, m;
void solve()
{
    int i, j, k;
    cin >> n >> m;
    int **a = new int[n][m];
    int a[n][m], lrow[n][m], lcol[n][m], grow[n][m], gcol[n][m];
    f(i, n)
            f(j, m)
                cin >>
        a[i][j],
        lrow[i][j] = lcol[i][j] = 0, grow[i][j] = gcol[i][j] = 0;

    calc(n, m, (int **)lrow, (int **)grow, (int **)a);
    // calc(m, n, (int **)lcol, (int **)gcol, (int **)a);

    // f(i, n)
    // {
    //     vector<int> row;
    //     f(j, m) row.push_back(a[i][j]);
    //     int len = removeDuplicate(row);
        
    //     f(j, m)
    //     {
    //         int x = (lower_bound(row.begin(), row.begin() + len, a[i][j]) - row.begin());
    //         lrow[i][j] = x;
    //         grow[i][j] = len - (x + 1);
    //     }
    // }

    // f(j, m)
    // {
    //     vector<int> col;
    //     f(i, n) col.push_back(a[i][j]);
    //     int len = removeDuplicate(col);
    //     f(i, n)
    //     {
    //         int x = (lower_bound(col.begin(), col.begin() + len, a[i][j]) - col.begin());
    //         lcol[i][j] = x;
    //         gcol[i][j] = len - (x + 1);
    //     }
    // }

    f(i, n)
    {
        f(j, m)
        {
            cout << max(lrow[i][j], lcol[i][j]) + 1 + max(grow[i][j], gcol[i][j]) << " ";
        }
        cout << endl;
    }

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