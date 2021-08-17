#include <bits/stdc++.h>
using namespace std;
#define int long long
#define jaldi_chal                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define REW(i, a, b) for (ll i = a; i <= b; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define clr(x) memset(x, 0, sizeof(x))
const int maxN = 1001;

char s[maxN][maxN];
int vis[maxN][maxN];
int dis[maxN][maxN];
int dis2[maxN][maxN];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int sx, sy;
int ex, ey;

bool check_2(int x, int y)
{

    if (x < 1 || x > n || y < 1 || y > m)
        return false;

    if (vis[x][y] || s[x][y] == '#' || dis[x][y] != -1)
        return false;

    return true;
}

bool check(int x, int y)
{

    if (x < 1 || x > n || y < 1 || y > m)
        return false;

    if (vis[x][y] || s[x][y] == '#')
        return false;

    return true;
}

void bfs()
{

    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;

    if (dis[sx][sy] != -1 || dis[ex][ey] != -1)
    {

        cout << "IMPOSSIBLE";
        exit(0);
    }

    while (!q.empty())
    {
        int currx = q.front().F;
        int curry = q.front().S;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (check_2(currx + dx[i], curry + dy[i]))
            {
                int nx = currx + dx[i], ny = curry + dy[i];
                dis2[nx][ny] = dis2[currx][curry] + 1;
                vis[nx][ny] = 1;

                q.push({nx, ny});
            }
        }
    }
}

signed main()
{

    jaldi_chal int t = 1, i;
    while (t--)
    {

        cin >> n >> m;
        int k;
        cin >> k;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> s[i][j];
                if (s[i][j] == 'S')
                    sx = i, sy = j;
                if (s[i][j] == 'E')
                    ex = i, ey = j;
            }
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        for (int i = 0; i < k; i++)
        {
            int r, c, d;
            cin >> r >> c >> d;

            q.push({d, {r, c}});
        }

        memset(dis, -1, sizeof dis);

        while (!q.empty())
        {
            int x = q.top().S.F;
            int y = q.top().S.S;
            int d = q.top().F;

            q.pop();
            vis[x][y] = 1;

            dis[x][y] = d;
            if (d > 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (check(x + dx[i], y + dy[i]))
                    {
                        int nx = x + dx[i], ny = y + dy[i];
                        dis[nx][ny] = dis[x][y] - 1;

                        q.push({d - 1, {nx, ny}});
                    }
                }
            }
        }

        clr(vis);

        bfs();

        if (dis2[ex][ey] == 0)
        {
            if (sx == ex && sy == ey)
                cout << "0" << endl;
            else
                cout << "IMPOSSIBLE" << endl;
        }
        else
            cout << dis2[ex][ey] << endl;
    }

    return 0;
}
