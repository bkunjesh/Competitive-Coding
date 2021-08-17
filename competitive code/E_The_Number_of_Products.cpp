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
#define rew(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;
void solve()
{
    int i, j, k;
    cin >> n;

    // int sum = 0;
    // int cnt[2] = {1, 0}, ans[2] = {0};

    // rew(i, 0, n)
    // {
    //     int k;
    //     cin >> k;
    //     if (k < 0)
    //         sum = !sum;
    //     rew(j, 0, 2) ans[j] += cnt[j ^ sum];
    //     cnt[sum]++;
    // }

    // cout << ans[1] << ' ' << ans[0] << endl;

    
    int x, totneg = 0, cnt1 = 0, cnt2 = 0,pos=0;

    // cnt1 and cnt2 — the number of elements such that there is an even number of negative elements before them(cnt1) or an odd number of negative elements before them(cnt2).;
    
    for (i = 0; i < n; i++)
    {
        cin >> x;

        if(totneg%2==0)
            cnt1++;
        else
            cnt2++;
        if(x<0)
            totneg++;

        if(totneg%2==0)
        {
            pos += cnt1;
        }
        else
        {
            pos += cnt2;
        }
    }
    cout << n * (n + 1) / 2 - pos << " " << pos << endl;

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