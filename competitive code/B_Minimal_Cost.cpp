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
const int N=105;

int n;

// int mat[N][1e6+1];
bool canreach(int a[])
{
    int i,j,k;


    // for(k=1;k<=1e6+1;k++)
    // {
    //     i=1,j=k;
    //     while(j>=0&&i<=n)
    //     {
    //         if(a[i]!=j) break;
    //         else
    //         {
    //             i++;
    //             j--;
    //         }
    //     }
    //     if(j<0||i>n)
    //     {
    //         return 0;
    //     }
    // }
    // for(k=2;k<n;k++)
    // {
    //     i=k,j=1e6+1;
    //     while(i<=n&&j>=0)
    //     {
    //         if(a[i]!=j) break;
    //         else
    //         {
    //             i++;
    //             j--;
    //         }
    //     }
    //     if(j<0||i>n)
    //     {
    //         return 0;
    //     }
    // }

    for(i=1;i<n;i++)
    {
        if(abs(a[i]-a[i+1])>1)
        {
            return 1;
        }
    }

    return 0;
    
}
void solve()
{
    int i, j, k,u,v,isdiff=0;
    
    cin>>n>>u>>v;

    int a[n+1];
    

    rep(i,n) 
    {
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1])
        {
            isdiff=1;
        }
    }
    if(isdiff==0)
    {
        cout<<v+min(u,v)<<endl;
        return ;
    }

    if(canreach(a))
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<min(u,v)<<endl;
    }
    

    
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