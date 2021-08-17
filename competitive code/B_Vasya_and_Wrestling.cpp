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
    int i, j, k,fst=0,sec=0;
    
    cin>>n;
    vector<int> a,b,c;
    f(i,n) 
    {
        cin>>j,a.push_back(j);
        if(j>0) 
        {
            fst+=j;
            b.push_back(j);
        }
        else{
            sec+=(-j);
            c.push_back(-j);
        }
    }
    if(fst>sec)
    {
        cout<<"first"<<endl;
        return;
    }
    else if(fst<sec)
    {
        cout<<"second"<<endl;
        return;
    }
    else 
    {
        //cout<<"YES"<<endl;
        vector<vector<int>> x;
        x.push_back(b);
        x.push_back(c);
        // sort(x.begin(),x.end());
        if(x[0]==x[1])
        {
            if(a[n-1]>0)
            {
                cout<<"first"<<endl;
                return;
            }
            else
            {
                cout<<"second"<<endl;
                return;
            }
        }
        else
        {
            if(x[1]>x[0])
            {
                cout<<"second"<<endl;
            }
            else
            {
                cout<<"first"<<endl;
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