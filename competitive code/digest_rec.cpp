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
const int N = 100005;

int n;
vector<int> userConnection[N], userStoryConnection[N], storyCreator(N);

void solve()
{
    int i, j, k;

    int m;
    cin >> n >> m;
    rep(i, n) cin >> storyCreator[i];
    int p, q;
    cin >> p >> q;
    f(i, p) cin >> j >> k, userConnection[j].push_back(k);
    f(i, q) cin >> j >> k, userStoryConnection[j].push_back(k);

    int a[m + 1][m + 1];
    rep(i, m)
        rep(j, m)
    {
        if (i == j)
        {
            a[i][j] = 0;
            continue;
        }

        int isValid = 0;
        for (auto conn : userConnection[i])
        {
            if (conn == j)
            {
                a[i][j] = 3;
                isValid = 1;
                break;
            }
        }
        if (isValid)
            continue;

        map<int, int> storyCreatedByj;
        for (int x = 1; x <= n; x++)
        {
            if (storyCreator[x] == j)
                storyCreatedByj[x] = 1;
        }
        for (auto storyfollowed : userStoryConnection[i])
        {
            if (storyCreatedByj[storyfollowed] == 1)
            {
                a[i][j] = 2;
                isValid = 1;
                break;
            }
        }
        if (isValid)
            continue;

        map<int, int> storyFollowedByj;
        for (auto storyFollowed : userStoryConnection[j])
            storyFollowedByj[storyFollowed] = 1;

        for (auto storyFollowed : userStoryConnection[i])
            if (storyFollowedByj[storyFollowed] == 1)
            {
                isValid = 1;
                a[i][j] = 1;
                break;
            }

        if (isValid)
            continue;

        a[i][j] = 0;
    }

    int b[m + 1][n + 1];
    rep(user, m)
    {
        map<int, int> storyCreatedByj;
        for (int x = 1; x <= n; x++)
        {
            if (storyCreator[x] == j)
                storyCreatedByj[x] = 1;
        }
        map<int, int> storyFollowedByj;
        for (auto storyFollowed : userStoryConnection[j])
            storyFollowedByj[storyFollowed] = 1;

        rep(story, n)
        {
            b[user][story] = 0;
            if (storyFollowedByj[story] == 1)
                b[user][story] = 1;
            if (storyCreatedByj[story] == 1)
                b[user][story] = 2;
        }
    }

    rep(user, m)
    {
        map<int, int> storyCreatedByi;
        for (int x = 1; x <= n; x++)
        {
            if (storyCreator[x] == i)
                storyCreatedByi[x] = 1;
        }
        map<int, int> storyFollowedByi;
        for (auto storyFollowed : userStoryConnection[i])
            storyFollowedByi[storyFollowed] = 1;

        priority_queue<pair<int, int>> ansForUser;
        rep(story, n)
        {
            if (storyCreatedByi[story] == 1 || storyFollowedByi[story] == 1)
            {
                ansForUser.push({-1, story});
                continue;
            }
            int score = 0;

            for (int y = 1; y <= m; y++)
            {
                score += (a[user][y] * b[y][story]);
            }
            ansForUser.push({score, story});
        }
        for (int y = 0; y < 3; y++)
        {
            auto pair = ansForUser.top();
            cout << pair.S << " ";
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