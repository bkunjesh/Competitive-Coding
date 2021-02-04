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

    int m;
    cin >> n >> m;
    int freq = n / m;
    int tenth_p = freq / 10;
    int digit_p = freq % 10;
    int sum = 0,tenth_sum=0;
    m = m % 10;
    i = 1;
    while (i<=10)
    {
        tenth_sum += ((m * i) % 10);
        if(i==digit_p)
            sum += tenth_sum;
        i++;
    }
    sum += (tenth_sum * tenth_p);
    cout << sum << endl;
    



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