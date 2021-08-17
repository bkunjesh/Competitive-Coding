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
    int i, j, k, m;
    cin >> n >> m;
    vector<string> a(n);
    f(i, n) cin >> a[i];
    int visited[n + 1][m + 1];
    memset(visited, 0, sizeof(visited));
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    auto isvalid = [&](int x, int y) {
        if(x>=0&&x<n&&y>=0&&y<m)
            return 1;
        return 0;
    };
    map<pair<int, int>, pair<int, int>> parent;
    queue<pair<int, int>> q;
    f(i, n)
    {
        f(j, m)
        {
            if (!visited[i][j])
            {
                q.push({i, j});
                visited[i][j] = 1;
                char c = a[i][j];


                while (!q.empty())
                {
                    int sz = q.size();
                    while(sz--)
                    {
                        auto p = q.front();
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (k = 0; k < 4; k++)
                        {
                            int neighbor_x = x + dx[k];
                            int neighbor_y = y + dy[k];
                            auto neighbor = make_pair(x + dx[k], y + dy[k]);

                            if (isvalid(neighbor_x, neighbor_y) && a[neighbor_x][neighbor_y] == c)
                            {
                                if (!visited[neighbor_x][neighbor_y])
                                {
                                    visited[neighbor_x][neighbor_y] = 1;
                                    q.push({neighbor_x, neighbor_y});
                                    parent[{neighbor_x, neighbor_y}] = p;
                                }
                                else if(neighbor!=parent[p])
                                {
                                    cout << "Yes" << endl;
                                    return;
                                }
                            }
                        }
                    }
                    
                }
            }
        }
    }
    cout << "No" << endl;

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