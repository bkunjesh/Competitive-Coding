//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define dbg(...) logger(#__VA_ARGS__, VA_ARGS)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}
#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;

vector<int> prime;
void make_prime_vect()
{
    int MAXN = 4000000;
    vector<int> br(MAXN + 1, 0);
    for (int i = 2; i <= MAXN;i++)
    {
        if(br[i]==0)
        {
            for (int j = i * 2; j <= MAXN;j=j+i)
            {
                br[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAXN;i++)
    if(br[i]==0)
        prime.push_back(i);
}

void solve()
{

    int i, j, k;

    // cout<<__gcd(9,6)<<endl;
    char c;
    string s;
    cin>>n>>c>>s;
    vector<int> mismatch;
    unordered_map<int,int> mp;

    
    k=1;
    for(i=0;i<n;i++)
    {
        if(s[i]!=c) 
        {
            k=0;
            mismatch.push_back(i+1);
            int x=i+1;
            for(j=1;j*j<=x;j++)
            {
                if(x%j==0)
                {

                    // while(x%j==0) x/=j;
                    mp[j]=1;
                    mp[x/j]=1;
                }
            }
            // if(x>=2) mp[x]=1;
        }
    }
    if(k)
    {
        cout<<0<<endl;
        return;
    }
    // for(auto it:mismatch) cout<<it<<" ";
    // cout<<endl;
    // for(auto it:mp)
    // {
    //     // dbg(it.F,it.S);
    //     cout<<it.F<<"->"<<it.S<<endl;
    
    // }


    {
        for(i=2;i<=n;i++)
        {
            if(mp[i]==0)
            {
                cout<<1<<endl;
                cout<<i<<endl;
                return;
            }
        }

        cout<<2<<endl;
        int temp=(n%2==0)?n-1:n;
        cout<<2<<" "<<temp<<endl;
        // for(i=0;prime[i]<=n;i++)
        // {
        //     if(n%prime[i]!=0)
        //     {
        //         cout<<2<<endl;
        //         cout<<n<<" "<<prime[i]<<endl;
        //         return;
        //     }
        // }
    }


    

    // vector<int> ans;

    // for(auto it:mp)
    // {
    //     if(it.S==1)
    //     {
    //         ans.push_back(it.F);
    //     }
    // }
    // cout<<ans.size()<<endl;
    // for(auto it:ans) cout<<it<<" ";
    // cout<<endl;



return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    make_prime_vect();
    cin >> t;
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