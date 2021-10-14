//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define dbg(...) logger(#__VA_ARGS__,__VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}
#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;

void solve()
{

    int i, j, k;

    int a[3];
    f(i,3) cin>>a[i];
    // int mx=max({a[0],a[1],a[2]});
    // // cout<<mx-a[0]+1<<" "<<mx-a[1]+1<<" "<<mx-a[2]+1<<endl;
    // if(a[0]==a[1]&&a[1]==a[2])
    // {
    //     cout<<a[0]+1<<" "<<a[0]+1<<" "<<a[0]+1<<endl;
    //     return;
    // }
    // if((a[0]==a[1]&&a[0]==mx)||(a[0]==a[2]&&a[0]==mx)||(a[2]==a[1]&&a[1]==mx))
    // {
    //     if((a[0]==a[1]&&a[0]==mx))
    //     {

    //         cout<<mx-a[0]+1<<" "<<mx-a[0]+1<<" "<<mx-a[2]+1<<endl;
    //         return;
    //     }
    //     else if((a[0]==a[2]&&a[0]==mx))
    //     {
    //         cout<<mx-a[0]+1<<" "<<mx-a[1]+1<<" "<<mx-a[2]+1<<endl;
    //         return;
    //     }
    //     else if((a[2]==a[1]&&a[1]==mx))
    //     {
    //     // cout<<"Y"<<endl;
    //         cout<<mx-a[0]+1<<" "<<mx-a[1]+1<<" "<<mx-a[2]+1<<endl;
    //         return;
    //     }
    // }
    f(i,3)
    {
        // dbg(mx);
        // int ans=mx-a[i]+1;
        // if(a[i]==mx) ans--;
        // cout<<ans<<" ";
        int mx=-1;
        f(j,3)
        {
            if(i==j) continue;
            mx=max(mx,a[j]);
        }
        if(a[i]>mx) cout<<0<<" ";
        else
        {
            cout<<mx-a[i]+1<<" ";
        }
        

    }
    cout<<endl;


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