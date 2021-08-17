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
    vector<int> a(n);
    f(i,n) cin>>a[i];

    // if(*max_element(a.begin(),a.end())!=a[n-1])
    // {
    //     cout<<"No"<<endl;
    //     return;
    // }

    // int sml[n],lar[n];
    // sml[0]=a[0];
    // rep(i,n-1) sml[i]=min(sml[i-1],a[i]);
    // lar[n-1]=a[n-1];
    // for(i=n-2;i>=0;i--) lar[i]=max(lar[i+1],a[i]);


    for(i=0;i<n-1;i++)
    {
        if(a[i]<a[i+1])
        {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
    return;

    // int mxeleind=0,mx=*max_element(a.begin(),a.end());
    // for(i=0;i<n;i++) if(a[i]==mx) mxeleind=i;

    // if(sml[mxeleind]<mx)
    // {
    //     cout<<"Yes"<<endl;
    //     return;
    // }
    // else
    // {
    //     cout<<"No"<<endl;
    //     return;
    // }



    // int isdiff=0;
    // for(i=1;i<n;i++) if(a[i]!=a[i-1]) isdiff=1;

    // if(isdiff==0) 
    // {
    //     cout<<"No"<<endl;
    //     return;
    // }

    // int issml=0;
    // for(i=n-2;i>=0;i--) if(a[i]<a[n-1]) issml=1;

    // if(issml)
    // {
    //     cout<<"Yes"<<endl;
    //     return;
    // }
    // else 
    // {
    //     cout<<"No"<<endl;
    //     return;
    // }

    

    // // // for(auto it: sml) cout<<it<<" ";
    // // // cout<<endl;
    // // // for(auto it: lar) cout<<it<<" ";
    // // // cout<<endl;

    // // for(i=n-2;i>=0;i--)
    // // {
    // //     if(a[i]>a[i+1])
    // //     {
    // //         if(sml[i]>=lar[i])
    // //         {
    // //             cout<<"NO"<<endl;
    // //             return;
    // //         }
    // //     }
    // // }

    // // // int prev=min(sml[0],lar[0]);
    // // // for(i=1;i<n;i++)
    // // // {
    // // //     if(sml[i]<prev&&lar[i]<prev)
    // // //     {
    // // //         cout<<"No"<<endl;
    // // //         return;
    // // //     }
    // // //     if(sml[i]-prev<lar[i]-prev)
    // // //     {
    // // //         prev=sml[i];
    // // //     }
    // // //     else prev=lar[i];
        

    // // // }
    // // cout<<"Yes"<<endl;
    
    
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