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
    vector<int> a(n);
    f(i, n) cin >> a[i];
    int cnt25 = 0, cnt50 = 0, cnt100 = 0;
    f(i,n)
    {
        if(a[i]==25)
            cnt25++;
        else if(a[i]==50)
        {
            if(cnt25>0)
            {
                cnt25--;
                cnt50++;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        else{
            if(cnt50>0&&cnt25>0)
            {
                cnt100++;
                cnt25--;
                cnt50--;
            }
            else if(cnt25>2)
            {
                cnt25 -= 3;
                cnt100++;
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;


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