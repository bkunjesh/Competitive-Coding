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
    
    string s,ans="";
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++)
    {
        int x=ans.size();
        if((x>1&&s[i]==ans[x-1]&&s[i]==ans[x-2])||((x>2)&&(s[i]==ans[x-1])&&(ans[x-2]==ans[x-3]))) continue;
        else ans+=s[i];

    }
    // s+='#';
    // n=s.size();
    // int cur=1;

    // for(i=1;i<n;i++)
    // {
        
    //     if(s[i]==s[i-1]) cur++;
    //     else if(s[i]!=s[i-1])
    //     {
    //         // cout<<s[i]<<cur<<" ";
    //         if(cur>=2) ans=ans+s[i-1]+s[i-1];
    //         else if(cur==1) ans+=s[i-1];
    //         cur=1;
    //     }
    // }
    // s=ans;
    // s+='#';
    // n=s.size();
    // ans="";
    // cur=1;
    // int prev=-1;
    // for(i=1;i<n;i++)
    // {
    //     if(s[i-1]==s[i])
    //     {
    //         cur++;
    //     }
    //     else if(s[i-1]!=s[i]&&cur==1)
    //     {
    //         ans+=s[i-1];
    //         cur=1;
    //         prev=-1;
    //     }
    //     else if(s[i-1]!=s[i]&&cur==2){
    //         if(prev==-1)
    //         {
    //             ans=ans+s[i-1]+s[i-1];
    //             prev=1;
    //             cur=1;
    //         }
    //         else
    //         {
    //             ans=ans+s[i-1];
    //             prev=-1;
    //             cur=1;
    //         }
    //     }
    // }

    cout<<ans<<endl;
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