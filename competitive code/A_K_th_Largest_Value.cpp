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
    int i, j,q, k,zcnt=0,ocnt=0;
    
    cin>>n>>q;
    vector<int> a(n+1);
    rep(i,n) cin>>a[i],(a[i]==0)?zcnt++:ocnt++;
    while(q--)
    {
        int type,x;
        cin>>type>>x;
        if(type==1)
        {
            if(a[x]==0)
            {
                a[x]=1;
                zcnt--;
                ocnt++;
            }
            else
            {
                a[x]=0;
                zcnt++;
                ocnt--;
            }
        }
        else
        {
            if(x<=ocnt)
            {
                cout<<1<<endl;

            }
            else{
                cout<<0<<endl;
            }
        }
    }

    
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