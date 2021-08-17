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
    int m,q;

    cin>>n>>m>>q;
    while(q--)
    {
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        // if(max(n,m)%min(n,m)!=0) 
        // {
        //     cout<<"YES"<<endl;
        //     continue;
        // }
        //if(n<m)
        {
            int pern=n/__gcd(n,m);
            int perm=m/__gcd(n,m);
            int sbox,ebox;
            if(sx==1)
            {
                sbox=(sy+pern-1)/pern;
            }
            else sbox=(sy+perm-1)/perm;
            if(ex==1)
            {
                ebox=(ey+pern-1)/pern;
            }
            else ebox=(ey+perm-1)/perm;
            // cout<<sbox<<" "<<ebox<<" ";
            if(sbox==ebox) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            // int mpern=n/m;
            // if(sx==2)
            // {
            //     sx=1;
            //     sy=sy/mpern;
            // }
            // if(ex==2)
            // {
            //     ex=1;
            //     ey=ey/mpern;
            // }

            // if(sx==ex&&sy==ey)
            // {
            //     cout<<"YES"<<endl;
            // }
            // else
            // {
            //     cout<<"NO"<<endl;
            // }
        }
        // else
        // {
        //     int nperm=m/n;
        //     if(sx==1)
        //     {
        //         sx=2;
        //         sy=sy/nperm;
        //     }
        //     if(ex==2)
        //     {
        //         ex=2;
        //         ey=ey/nperm;
        //     }

        //     if(sx==ex&&sy==ey)
        //     {
        //         cout<<"YES"<<endl;
        //     }
        //     else
        //     {
        //         cout<<"NO"<<endl;
        //     }
        // }
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