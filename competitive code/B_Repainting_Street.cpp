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

void solve()
{
    int i, j, k;

    cin >> n >> k;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    auto check = [&](int days)
    {
        
        for (int c = 1; c <= 100;c++)
        {
            int d = 0;
            i = 0;
            while(i<n)
            {
                while(i<n&&a[i]==c)
                    i++;
                if(i<n)
                {
                    i += k;
                    d++;
                }
            }
            if(d<=days)
                return 1;
        }
        return 0;
    };
    int l = 0,h = 1e5 + 5, ans = n;
    while(l<=h)
    {
        int mid = l + (h - l) / 2;
        if(check(mid))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;

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