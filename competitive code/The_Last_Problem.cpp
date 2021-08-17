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
int mat[1005][1005], mat2[1005][1005];
void make_mat()
{
    int i, j;
    memset(mat, 0, sizeof(mat));
    mat[1][1] = 1;
    int k = 1;
    for (j = 2; j < 1005; j++)
    {
        mat[1][j] = mat[1][j - 1] + k;
        k++;
    }
    for (i = 2; i < 1005; i++)
    {
        for (j = 1; j < 1005; j++)
        {

            mat[i][j] = mat[i - 1][j] + (i + j - 1);
            // if(j<5)
            // cout << mat[i][j] << " ";
        }
        // cout << endl;
    }
}

void solve()
{
    int i, j, k;
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int ans = 0;
    for (i = x1; i <= x2; i++)
        ans += mat[i][y1];
    for (i = y1+1; i <= y2; i++)
        ans += mat[x2][i];
    cout << ans << endl;
    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    make_mat();
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