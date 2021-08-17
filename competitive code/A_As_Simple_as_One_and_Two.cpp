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
    n=s.size();
    vector<int> ans;
    for(i=0;i<n;)
    {
        if(i+3<=n)
        {
            if(s.substr(i,3)=="one")
            {
                ans.push_back(i+1);
                i+=3;
                continue;
            }
            else if(s.substr(i,3)=="two")
            {
                if(i+5<=n)
                {
                    if(s.substr(i,5)=="twone")
                    {
                        ans.push_back(i+2);
                        i+=5;
                        continue;
                    }
                    else
                    {
                        ans.push_back(i+1);
                        i+=3;
                        continue;
                    }
                }
                else
                {
                    ans.push_back(i+1);
                    i+=3;
                    continue;
                }
            }
            else i++;
        }
        else i++;

    }
    cout<<ans.size()<<endl;
    for(auto it:ans) cout<<it+1<<" ";
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