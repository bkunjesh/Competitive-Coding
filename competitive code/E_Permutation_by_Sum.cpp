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
    int i, j, k,l,r,s;

    cin >> n >> l >> r >> s;

    int x = r - l + 1;

    int mx = n * x - x * (x - 1) / 2;
    int mn = x * (x + 1) / 2;

    if(s<mn||s>mx)
    {
        cout << -1 << endl;
        return;
    }

    int mid[x],sum=0;
    f(i, x) mid[i] = i + 1,sum+=mid[i];

    j = x - 1;
    while(sum!=s)
    {
        int cnt = n - x;
        if(sum+cnt<=s)
        {
            mid[j] += cnt;
            sum += cnt;
        }
        else
        {
            mid[j] += (s - sum);
            sum = s;
        }
        // while(cnt>0&&sum!=s)
        // {
        //     mid[j]++;
        //     sum++;
        //     cnt--;
        // }
        j--;
    }
    map<int, int> mp;
    f(i, x) mp[mid[i]] = 1;

    vector<int> ans(n+1);
    j = 1;
    for (i = 1; i < l;i++)
    {
        while(mp[j]==1)
            j++;

        ans[i] = j;
        j++;
    }
    k = 0;
    for (i = l; i <= r;i++)
        ans[i] = mid[k++];

    for (i = r + 1; i <= n;i++)
    {
        while (mp[j] == 1)
            j++;

        ans[i] = j;
        j++;
    }

    rep(i, n) cout << ans[i] << " ";
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif