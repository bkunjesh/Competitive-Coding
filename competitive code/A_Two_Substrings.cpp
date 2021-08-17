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

    string s;
    cin>>s;
    n = s.size();
    int ab = 1, ba = 1;
    for (i = 1; i < n;i++)
    {
        if(s[i]=='B'&&s[i-1]=='A'&&ab)
        {
            ab = 0;
            i++;
            
        }
        else if(s[i]=='A'&&s[i-1]=='B'&&ba&&ab==0)
        {
            ba = 0;
            i++;

        }

        if (ab == 0 && ba == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    if (ab == 0 && ba == 0)
    {
        cout << "YES" << endl;
        return;
    }
    ab = 1, ba = 1;
    for (i = 1; i < n;i++)
    {
        
        if(s[i]=='A'&&s[i-1]=='B'&&ba)
        {
            ba = 0;
            i++;

        }
        else if(s[i]=='B'&&s[i-1]=='A'&&ab&&ba==0)
        {
            ab = 0;
            i++;
            
        }

        if (ab == 0 && ba == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    if(ab==0&&ba==0)
        {
            cout << "YES" << endl;
            return;
        }
    cout << "NO" << endl;

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