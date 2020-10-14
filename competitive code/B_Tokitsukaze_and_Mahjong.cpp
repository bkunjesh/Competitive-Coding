#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;

int main()
{
    fast
    ll t = 1, i, j;
    //cin >> t;
    while (t--)
    {
        string s[3];cin>>s[0]>>s[1]>>s[2];
        
        map<char,int> m_char;
        for(i=0;i<3;i++) m_char[s[i][1]]++;
        map<int,int> m_int;
        for(i=0;i<3;i++) m_int[s[i][0]-'0']++;
        if(m_char.size()==1)
        {
            if(m_int.size()==1)
            {
                cout<<0<<endl;
            }
            else if(m_int.size()==2)
            {
                cout<<1<<endl;                
            }
            else
            {
                auto it=m_int.begin();
                ll fst=(*it).first;
                it++;
                ll scd=(*it).first;
                it++;
                ll trd=(*it).first;
                if(fst+1==scd&&scd+1==trd)
                {
                    cout<<0<<endl;
                }
                else if(fst+1==scd||scd+1==trd||fst+2==trd||fst+2==scd)
                {
                    cout<<1<<endl;
                }
                else
                {
                    cout<<2<<endl;
                }
                
                
            }
            
        }
        else
        {
            if(m_char.size()==3)
            {
                cout<<2<<endl;
            }            
            else
            {
                char tofind;
                if(s[0][1]==s[1][1]&&(s[0][0]==s[1][0]||(abs(s[0][0]-s[1][0])<=2)))
                {
                    cout<<1<<endl;
                }
                else if(s[0][1]==s[2][1]&&(s[0][0]==s[2][0]||(abs(s[0][0]-s[2][0])<=2)))
                {
                    cout<<1<<endl;
                }
                else if(s[2][1]==s[1][1]&&(s[2][0]==s[1][0]||(abs(s[2][0]-s[1][0])<=2)))
                {
                    cout<<1<<endl;
                }
                else
                {
                    cout<<2<<endl;
                }
                

            }
        }
        

    }
return 0;
}