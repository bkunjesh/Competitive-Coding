//@CodesUp
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
int N = 200005;

int n;

void solve()
{
    int i, j, k;
 
    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    int l = 0, r = n - 1;
    if(n==1)
    {
        cout << "YES" << endl;
        return;
    }
    while (l < n-1 && a[l] >= a[l + 1])
    {
        l++;
    }
    if (l < n-1)
    {
        int temp = l+1;
        while (temp<n - 1&&a[temp]> a[l])
        {
            if (a[temp] > a[temp + 1])
                {
                    a[temp] -= a[l];
                    //break;
                }
            a[temp] -= a[l];
            
            temp++;
        }
        //cout<<temp<<" ";
        a[l] = 0;
    }
    while (r > l && a[r] >= a[r - 1])
    {
        r--;
    }
    if (r == l)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}