//@ikung
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
// #define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
// #define mod 1000000007
//const int inf = 1e18;
const int N=200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    int step = 0,a;
    int o_i = 1, o_y = 2;
    int e_i = 1, e_y = 1;
    while(step<n*n)
    {
        cin >> a;
        if(a!=1)
        {
            cout << 1 << " " << e_i << " " << e_y << endl;
            e_y += 2;
            if(e_y>n)
            {
                e_i++;
                e_y = 1;
                if(e_i%2==0)
                    e_y++;
                if(e_i>n)
                    break;
            }
        }
        else
        {
            cout << 2 << " " << o_i << " " << o_y << endl;
            o_y += 2;
            if (o_y > n)
            {
                o_i++;
                o_y = 2;
                if (o_i % 2 == 0)
                    o_y--;
                if (o_i > n)
                    break;
            }
        }
        step++;
    }
    
    while(step<n*n)
    {
//    	cout<<"o_i:"<<o_i<<" o_y:"<<o_y<<" e_i: "<<e_i<<" e_y:"<<e_y<<endl;
        cin >> a;

        if(o_i<=n)
        {
            if(a!=2)
                cout << 2 << " " << o_i << " " << o_y << endl;
            else
                cout << 3 << " " << o_i << " " << o_y << endl;
            o_y += 2;
            if (o_y > n)
            {
                o_i++;
                o_y = 2;
                if (o_i % 2 == 0)
                    o_y--;
                if (o_i > n)
                    break;
            }
        }
        else if(e_i<=n)
        {
            if(a!=1)
            cout << 1 << " " << e_i << " " << e_y << endl;
            else
            cout << 3 << " " << e_i << " " << e_y << endl;
            e_y += 2;
            if (e_y > n)
            {
                e_i++;
                e_y = 1;
                if (e_i % 2 == 0)
                    e_y++;
                if (e_i > n)
                    break;
            }
        }

        step++;
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
