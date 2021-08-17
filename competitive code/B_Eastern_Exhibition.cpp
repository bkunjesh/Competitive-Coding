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
    
    cin>>n;
    vector<int> x(n),y(n);
    set<int> X,Y;
    f(i,n) cin>>x[i]>>y[i],X.insert(x[i]),Y.insert(y[i]);

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if (n%2 == 0)
    {
        cout << (x[n/2] - x[n/2 - 1] + 1)*(y[n/2] - y[n/2 - 1] + 1)<< endl;
    }
    else
    {
        cout << "1\n";
    }

    // map<int,int> x_sum,y_sum,visitedx,visitedy;
    // f(i,n)
    // {
    //     if(!visitedx[x[i]])
    //     f(j,n)
    //     {
    //         x_sum[x[i]]+=abs(x[i]-x[j]);
    //         visitedx[x[i]]=1;
    //     }
    // }
    // f(i,n)
    // {
    //     if(!visitedy[y[i]])
    //     f(j,n)
    //     {
    //         y_sum[y[i]]+=abs(y[i]-y[j]);
    //         visitedy[y[i]]=1;
    //     }
    // }

    // for(auto it:X)
    // {
    //     for(auto it2:X)
    //     {
    //         x_sum[it]+=abs(it-it2);
    //     }
    // }
    // for(auto it:Y)
    // {
    //     for(auto it2:Y)
    //     {
    //         y_sum[it]+=abs(it-it2);
    //     }
    // }

    // cout<<x_sum[1]<<"y_sum";
    // map<int,int> ans;
    // // f(i,n)
    // // {
    // //     f(j,n)
    // //     {
    // //         ans[x_sum[x[i]]+y_sum[y[j]]]++;
    // //     }
    // // }
    // for(auto it:X)
    // {
    //     for(auto it2:Y)
    //     {
    //         ans[x_sum[it]+y_sum[it2]]++;
    //     }
    // }
    // // for(auto it:ans)
    // // {
    // //     cout<<it.F<<" "<<it.S<<endl;
    // // }

    // cout<<(ans.begin())->S<<endl;
    // //cout<<endl;

    
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