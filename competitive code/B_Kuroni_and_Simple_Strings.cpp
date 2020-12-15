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

    string s;
    cin >> s;
    n = s.size();
    vector<int> opening, closing,ans;
    f(i,n)
    {
        if(s[i]=='(')
            opening.push_back(i);
        else
        {
            closing.push_back(i);
        }        
    }
    i = 0, j = closing.size() - 1;
    if(opening.size()>0&&closing.size()>0)
    while (i < opening.size()&&j>=0)
    {
        if(opening[i]<closing[j])
        {
            ans.push_back(opening[i]);
            ans.push_back(closing[j]);
        }
        i++, j--;
    }
    if(ans.size()==0)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        cout << 1 << endl << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for(auto it:ans)
            cout << it+1 << " ";
        cout << endl;
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