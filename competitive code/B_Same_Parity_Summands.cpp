//@CodesUp
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
int N=200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n >> k;
    if(n<k)
    {
        cout << "NO" << endl;
        return;
    }
    if(n%2==1)
    {
        if(k%2==0)
        {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        f(i, k - 1) cout << 1 << " ";
        cout << (n - (k - 1)) << endl;
        return;
    }
    else
    {
        // if(n<=2*(k-1)&&n!=k)
        // {
        //     cout << "NO" << endl;
        //     return;
        // }
        if ((n - (k - 1)) % 2 == 1 || n == k)
        {
            cout << "YES" << endl;
            f(i, k - 1) cout << 1 << " ";
            cout << (n - (k - 1)) << endl;
            return;
        }
        else if ((n > 2 * (k - 1)) && (n - 2 * (k - 1)) % 2 == 0)
        {
            cout << "YES" << endl;
            f(i, k - 1) cout << 2 << " ";
            cout << (n - 2 * (k - 1)) << endl;
            return;
        }
    }
    cout << "NO" << endl;

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