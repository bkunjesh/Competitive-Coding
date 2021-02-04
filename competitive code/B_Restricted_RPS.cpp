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

    cin >> n;
    int rock, paper, scissor,bob_rock=0,bob_paper=0,bob_scissor=0;
    string s;
    cin >> rock >> paper >> scissor >> s;
    for(auto it:s)
    {
        if(it=='R')
            bob_rock++;
        if(it=='P')
            bob_paper++;
        if(it=='S')
            bob_scissor++;
    }
    int alice_score = 0, bob_score = 0;
    alice_score += min(bob_rock, paper);
    bob_rock -= min(bob_rock, paper);
    alice_score += min(bob_paper, scissor);
    bob_paper -= min(bob_paper, scissor);
    alice_score += min(bob_scissor, rock);
    bob_paper -= min(bob_scissor, rock);

    if(alice_score>=(n+1)/2)
    {
        cout << "YES" << endl;
        vector<char> ans(n,'.');
        for (i = 0; i < n&&paper>0;i++)
        {
            if(s[i]=='R')
                ans[i] = 'P',paper--;
        }
        for (i = 0; i < n&&scissor>0;i++)
        {
            if(s[i]=='P')
                ans[i] = 'S',scissor--;
        }
        for (i = 0; i < n&&rock>0;i++)
        {
            if(s[i]=='S')
                ans[i] = 'R',rock--;
        }
        f(i,n)
        {
            if(ans[i]=='.')
            {
                if(s[i]=='R')
                {
                    if(paper>0) 
                    {
                        ans[i] = 'P';
                        paper--;
                    }
                    else if(rock>0)
                    {
                        ans[i] = 'R';
                        rock--;
                    }
                    else
                    {
                        ans[i] = 'S';
                        scissor--;
                    }
                }
                else if(s[i]=='P')
                {
                    if(scissor>0) 
                    {
                        ans[i] = 'S';
                        scissor--;
                    }
                    else if(paper>0)
                    {
                        ans[i] = 'P';
                        paper--;
                    }
                    else
                    {
                        ans[i] = 'R';
                        rock--;
                    }
                }
                else if(s[i]=='S')
                {
                    if(rock>0) 
                    {
                        ans[i] = 'R';
                        rock--;
                    }
                    else if(scissor>0)
                    {
                        ans[i] = 'S';
                        scissor--;
                    }
                    else
                    {
                        ans[i] = 'P';
                        paper--;
                    }
                }
            }
        }
        f(i,n)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


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