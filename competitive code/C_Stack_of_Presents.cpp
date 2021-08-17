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
// class FenwickTree
// {
//     //(one based indexing)
//     // Refrence:- https://www.youtube.com/watch?v=CWDQJGaN1gY , cpalgorithms.

//     private:
//     int n;
//     vector<int> bit;
//     public:
//     FenwickTree(int n)
//     {
//         this->n=n+1; 
//         bit=vector<int>(n+1,0);
//     }

//     FenwickTree(vector<int> a) : FenwickTree(a.size()) {
//         for (size_t i = 0; i < a.size(); i++)
//             add(i, a[i]);
//     }

//     /*--who is parent--*/
//     /*
//          find parent of 6(110)
//          sol- flip right most set bit of 6(110) 
//               that is (100)=>4
//               so 4 is parent of 6...

//         //FOR QUERIE//
//          getparent = (orignal_no)-(orignal_no & 2's complement)
//         //FOR UPDATE//
//          getnext = (orignal_no)+(orignal_no&2's complement)
//     */


//     int sum(int ind)
//     {
//         int ret=0;
//         //getparent = (orignal_no)-(orignal_no & 2's complement)
//         for(ind++;ind>0;ind=ind-(ind&-ind))
//         ret+=bit[ind];

//         return ret;        
//     }

//     int sum(int l,int r)
//     {
//         return sum(r)-sum(l-1);
//     }

//     void add(int ind,int val)
//     {
//         //getnext = (orignal_no)+(orignal_no&2's complement)
//         for(ind++;ind<n;ind=ind+(ind&-ind))
//         bit[ind]+=val;
//     }

// };

void solve()
{
    int i, j, k;
    
    int m;
    map<int,int> mp;
    cin>>n>>m;
    vector<int> a(n);
    f(i,n) 
    {
        cin>>a[i];
        mp[a[i]]=i;
    }
    int ans=0,mxind=-1;
    // FenwickTree ft(n+1);
    j=0;
    while(m--)
    {
        int p;
        cin>>p;
        int curind=mp[p];
        // auto a_outed=ft.sum(curind);
        auto a_outed=j;

        if(curind<mxind)
        {
            ans++;
        }
        else
        {
            mxind=curind;
            ans=ans+(mxind-a_outed)*2+1;
        }

        // ft.add(curind,1);
        j++;
    }
    cout<<ans<<endl;
    // cout<<endl;
    
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif