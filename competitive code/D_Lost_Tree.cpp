//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define S second
// #define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
// #define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
//template<typename ...Args>
//void logger(string vars, Args&&... values) {
//    cout << vars << " = ";
//    string delim = "";
//    (..., (cout << delim << values, delim = ","));
//    cout << endl;
//}

#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;

void solve()
{
    int i, j, k;

    cin >>n;
//    vector<pair<int, int>> ans;
    // vector<int> graph[n + 1];
    vector<int> visited(n + 1, 0);
    map<pair<int, int>,int> mp;

    rep(i,n)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);

            while(!q.empty())
            {
                if(visited[q.front()]) 
                {
                    q.pop();
                    continue;
                }
                int x = q.front();
                q.pop();
                if (!visited[x])
                {
                    cout << "? " << x << endl;
                    visited[x] = 1;
                    vector<int> a(n + 1);
                    rep(j, n) cin >> a[j];
                    vector<int> g[n + 1],unvisited(n+1,0);
                    rep(j, n) 
                    {
                        g[a[j]].push_back(j);
                        if(!visited[j])
                            unvisited[a[j]]++;
                    }

                    j = 1, k = x;

                    while (g[j].size() == 1)
                    {
                        mp[{min(k, g[j][0]), max(k, g[j][0])}] = 1;
                        k = g[j][0];
                        visited[k] = 1;
                        j++;
                    }
                    for (int p = 0; p < g[j].size(); p++)
                    {
                        int gnode = g[j][p];
                        visited[gnode] = 1;
                        q.push(gnode);
                        mp[{min(k, gnode), max(k, gnode)}] = 1;
                    }

                    if (mp.size() == (n - 1))
                        break;
                }
                
            }

            if (mp.size() == (n - 1))
                break;
        }
    }
    cout << "!" << endl;
    for(auto it:mp)
    {
        auto p = it.F;
        cout << p.F << " " << p.S << endl;
    }

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
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
