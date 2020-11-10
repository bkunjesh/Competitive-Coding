//@CodesUp
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
int N=200005;

int n;

void solve()
{
    int i, j, k,x,l=-1,r,sum=0;

    cin >> n >> x;
    vector<int> a(n);
    f(i,n)
    {
        cin >>j;
        if(j%x!=0)
        {
            if(l==-1)
                l = i;
            r = i;
        }
        sum += j;
    }
    if(sum%x!=0)
        cout << n << endl;
    else if(l==-1)
        cout<<-1<<endl;
    else
        cout << n - min(l+1, n - r) << endl;

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