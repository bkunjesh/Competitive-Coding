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

void solve()
{
    int i, j, k;

    cin >> n;
    char s[n+10];
    int a[n],pref[n + 5][2], suf[n + 5][2];
    f(i,n+5)
    {
        if(i<=n&&i>0)
        {
            cin >> s[i];
            a[i]=(s[i] == 'L') ? 0 : 1;
        }
        pref[i][0] = pref[i][1] = suf[i][0] = suf[i][1] = 0;
    }
    rep(i,n)
    {
        if(a[i]==1)
        {
            pref[i][1] = pref[i - 1][0] + 1;
            pref[i][0] = 0;
        }
        else
        {
            pref[i][0] = pref[i - 1][1] + 1;
            pref[i][1] = 0;
        }
    }
    for (i = n; i > 0;i--)
    {
        if (a[i] == 1)
        {
            suf[i][1] = suf[i + 1][0] + 1;
            suf[i][0] = 0;
        }
        else
        {
            suf[i][0] = suf[i + 1][1] + 1;
            suf[i][1] = 0;
        }
    }
    for (i = 0; i <= n;i++)
    {
        cout << pref[i][0] + suf[i + 1][1] + 1 << " ";
    }
    cout << endl;

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