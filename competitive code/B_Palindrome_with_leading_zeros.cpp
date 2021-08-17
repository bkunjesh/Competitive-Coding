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
    cin >> s;
    n = s.size();
    j = n - 1;
    while(j>=0&&s[j]=='0')
        j--;
    i = 0;
    while(i<n&&s[i]=='0')
        i++;
    int flag = 1;
    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            flag = 0;
            break;
        }
        i++, j--;
    }
    if(flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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