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

int main()
{
    fast
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        map<char,ll> m1,m2;
        //cin>>n;
        string a,b;cin>>a>>b;
        j=0;
        for(i=0;i<a.size();)
        {
            ll cnt_f=1;
            while(i<(a.size()-1)&&a[i]==a[i+1]) i++,cnt_f++;
            ll cnt_s=0;
            while(j<b.size()&&b[j]==a[i]) j++,cnt_s++;
            //cout<<a[i]<<" "<<cnt_f<<" "<<cnt_s<<endl;
            if(cnt_s<cnt_f) 
            {
                //cout<<"NO"<<endl;
                break;
            }
            
            i++;
        }
        if(i>=a.size()&&j>=b.size()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        // for(auto it:a) m1[it]++;
        // for(auto it:b) m2[it]++;
        // if(m1.size()!=m2.size())
        // {
        //     cout<<"NO"<<endl;
        //     continue;
        // }
        // auto it=m1.begin();
        // for(;it!=m1.end();it++)
        // {
        //     char ch=(*it).F;
        //     if(m1[ch]<m2[ch])
        //     {
        //         cout<<"NO"<<endl;
        //         break;
        //     }
        // }
        // if(it==m1.end()) cout<<"YES"<<endl;
    }
return 0;
}