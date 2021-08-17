#define int long long 
int n;
vector<pair<int,int> > arr[1001];
int dp[1001][1001];
 int start,finish;
int solve(int node, int k) {
    int &res = dp[node][k];


    if (~res) return res;

    // if (k == 0) {

    //     if (node == start) return 0;
    //     else return 1e9;

    // }
    res = 1e9;
    for (int i = 0; i < arr[node].size(); i++) {

        int child = arr[node][i].first, cost = arr[node][i].second;
        dbg(node, child, cost);
        res = min({res, cost + solve(child, k)});
        if (k > 0) res = min(res, solve(child, k - 1));
    }
    // dbg(node, k, res);



    return res;
}
signed   main()
{
    fast
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        cin>>n;

       
        cin>>start>>finish;

        int k;
        cin>>k;

        int m,r;
        cin>>m>>r;

        for(int i=1;i<=m;i++) {
           int u,v,cost;
           cin>>u>>v>>cost;
           arr[u].push_back({v,cost});
           arr[v].push_back({u,cost});
        }

        for(int i=0;i<n;i++) for(int j=0;j<=k;j++) dp[i][j]=-1;

        for(int i=0;i<=k;i++) dp[start][i]=0;

        int ans=solve(finish,k);    

         if(ans==1e9) cout<<"-1"<<endl;
         else cout<<ans<<endl;

    
    }
    return 0;
}



// //@ikung
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define fast                      \
//     ios_base::sync_with_stdio(0); \
//     cin.tie(0);
// #define f(i, k) for (int i = 0; i < k; i++)
// #define F first
// #define S second
// #define endl "\n"
// #define rep(i, n) for (int i = 1; i <= n; i++)
// #define rew(i, a, b) for (int i = a; i <= b; i++)
// #define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
// template <typename... Args>
// void logger(string vars, Args &&...values)
// {
//     cout << vars << " = ";
//     string delim = "";
//     (..., (cout << delim << values, delim = ","));
//     cout << endl;
// }

// #define mod 1000000007
// const int inf = 1e18;
// const int N = 200005;

// int n;

// int power(int x, unsigned int y, unsigned int m)
// {
//     if (y == 0)
//         return 1;
//     int p = power(x, y / 2, m) % m;
//     p = (p * p) % m;

//     return (y % 2 == 0) ? p : (x * p) % m;
// }

// void solve()
// {
//     int i, j, k;

//     cin >> n;
//     vector<int> a(n), b(n);
//     for (i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     for (i = 0; i < n; i++)
//     {
//         cin >> b[i];
//     }
//     int ans = 0;
//     for (i = 0; i < n; i++)
//     {
//         ans = ans % mod + ((a[i] % mod) * (b[i] % mod) * power(2, mod - 2, mod)) % mod;
//     }
//     cout << ans << endl;

//     return;
// }

// signed main()
// {
//     fast int t = 1, i, j, k;
//     //cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }
// //#ifndef ONLINE_JUDGE
// //freopen("input.txt", "r", stdin);
// //freopen("output.txt", "w", stdout);
// //#endif