//@bkunjesh
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;
void solve()
{
    cin>>n;
    ll i;
    vector<string> grid(n+1);
    rep(i,n) cin>>grid[i];
    char s1=grid[1][1],s2=grid[2][0],en=grid[n][n-2],en_1=grid[n-1][n-1];
    //cout<<s1<<" "<<s2<<" "<<en<<" "<<en_1<<endl;

    if(((en!=s1&&en_1!=s2)||(en!=s2)&&(en_1!=s1))&&en_1!=en)
    {
        //cout<<"YES";
        if(en!=s1)
        {
            cout<<2<<endl;
            cout<<n<<" "<<n-1<<endl;
            cout<<1<<" "<<2<<endl;
        }
        else if((en!=s2))
        {
            cout<<2<<endl;
            cout<<n<<" "<<n-1<<endl;
            cout<<2<<" "<<1<<endl;
        }
        
    }
    if(s1==s2)
    {
        if(en==en_1&&en==s1)
        {
            cout<<2<<endl;
            cout<<n<<" "<<n-1<<endl;
            cout<<n-1<<" "<<n<<endl;
            return;            
        }
        else if(en==en_1&&en!=s1)
        {
            cout<<0<<endl;
            return;
        }
        else if(en!=en_1)
        {
            if(en==s1)
            {
                cout<<1<<endl;
                cout<<n<<" "<<n-1<<endl;
                return;
            }
            else if(en_1==s1)
            {
                cout<<1<<endl;
                cout<<n-1<<" "<<n<<endl;
                return;                
            }           
        }
    }
    if(en==en_1)
    {
        if(s1==s2&&en==s1)
        {
            cout<<2<<endl;
            cout<<n<<" "<<n-1<<endl;
            cout<<n-1<<" "<<n<<endl;
            return;            
        }
        else if(s1==s2&&en!=s1)
        {
            cout<<0<<endl;
            return;
        }
        else if(s1!=s2)
        {
            if(en==s1)
            {
                cout<<1<<endl;
                cout<<1<<" "<<2<<endl;
                return;
            }
            else if(en_1==s2)
            {
                cout<<1<<endl;
                cout<<2<<" "<<1<<endl;
                return;                
            }           
        }
    }
}

int main()
{
    fast
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();  
    }
return 0;
}