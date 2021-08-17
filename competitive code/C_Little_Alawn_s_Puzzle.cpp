//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;
int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = ((res % mod) * (a % mod)) % mod;
        }
        n >>= 1;
        a = ((a % mod) * (a % mod)) % mod;
    }
    return res;
}

void solve()
{
    int i, j, k;
    cin >> n;
    vector<int> g[n+2];
    vector<int> visited(n+2, 0);
    vector<int> a(n), b(n);
    f(i, n) cin >> a[i];
    f(i, n) cin >> b[i];
    f(i, n) g[a[i]].push_back(b[i]);
    int cnt = 0;

    rep(i,n)
    {
        if(!visited[i])
        {
            int node = i;
            visited[node] = 1;
            do{
                visited[node] = 1;
                node = g[node][0];
            } while (node != i);
            cnt++;
        }
    }
    cout << power(2, cnt) % mod << endl;
    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
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