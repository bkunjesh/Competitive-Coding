//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;
int fact[N + 1];

void factorial(int p = mod)
{
    fact[0] = 1;

    // precompute factorials
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

void solve()
{
    int i, j, k;
    cin >> n;
    vector<int> a(n),onecnt(32,0);
    map<int, int> mp;
    f(i, n) cin >> a[i], mp[a[i]]++;
    sort(a.begin(), a.end());
    f(j,32)
    {
        f(i,n)
        {
            if((a[i]&(1<<j)))
                onecnt[j]++;
        }
    }
    set<int> s;
    f(i,n) s.insert(i);

    f(j,32)
    {
        if(onecnt[j]==n)
            continue;
        f(i,n)
        {
            if ((a[i] & (1 << j)))
                s.erase(i);
        }
    }
    int x = s.size();
    int ans = x * (x - 1);
    ans %= mod;
    
    ans = ((ans % mod )* (fact[n - 2] % mod)) % mod;
    cout << ans << endl;





    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    factorial();
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