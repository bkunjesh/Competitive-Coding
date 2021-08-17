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
    int i, j, k,with_a=0;
    
    cin>>n;
    vector<vector<int>> a;
    vector<int> maxvec,minvec;
    f(i,n)
    {
        int l,is_a=0,mn,mx;
        vector<int> temp;
        cin>>l;
        f(j,l) 
        {
            cin>>k;
            temp.push_back(k);
            if(j==0)
            {
                mn=k;
                mx=k;
            }
            if(mn<k)
            {
                is_a=1;
            }
            mn=min(k,mn);
            mx=max(k,mx);
        }
        if(is_a) with_a++;
        minvec.push_back(mn);
        maxvec.push_back(mx);
        a.push_back(temp);
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