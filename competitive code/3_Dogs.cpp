#include<bits/stdc++.h>
using namespace std;
#define int long long //delete if causing problems
#define F first
#define S second
#define setbit(n) builtin_popcountll(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
const int inf = 1e15;
int power(int a, int b);
// #ifndef ONLINE_JUDGE
// #define dbg(...) logger(#__VA_ARGS, VA_ARGS)
// template<typename ...Args>
// void logger(string vars, Args&&... values) {
//     cout << vars << " = ";
//     string delim = "";
//     (..., (cout << delim << values, delim = ","));
//     cout << endl;
// }
// #else
// #define dbg(...)
// #endif

vector<int> arr[100005];

int dp[100005][3];

int solve(int node, int have)
{

    int &res = dp[node][have];
    if (~res) return res;
    res = inf;

    int need = (have - 1 + 3) % 3;

    for (auto x : arr[node]) {
        int curr = solve(x, need);
        if (curr != inf);
        res = min(res, 1 + curr);
    }

    return res;

}



signed   main()
{
    fast
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {

        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            arr[v].push_back(u);

        }

        int start, end;
        cin >> start >> end;

        memset(dp, -1, sizeof dp);

        dp[start][0] = 0;

        int val = solve(end, 0);
        // dbg(val);

        if (val >= inf) {
            val = -3;
        }


        cout << val / 3 << endl;







    }
    return 0;
}

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2) b-- , res = res * a;
        else b = b / 2 , a *= a;
    }
    return res;
}

/*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
*/