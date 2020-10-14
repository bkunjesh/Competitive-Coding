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

double check_for_y(double m1,double c1,double m2,double c2)
{
    double x=(c2-c1)/(m1-m2);

    double y1=m1*x+c1;
    double y2=m2*x+c2;
    if(y1==y2&&y1>0) return y1;
    
    return 0;
}

vector<double> make_m(ll interval_no,ll n)
{
    vector<double> m(3);
    m[0]=((double)1/(interval_no));
    m[1]=-((double)1/(n-interval_no+2));

    return m;
}

vector<double> make_c(ll interval_no,vector<double> a)
{
    vector<ll> X(a.size()+3);
    ll i;
    X[0]=0;
    for(i=a.size()-1;i>0;i--)
    {
        X[i]=a[i]-a[i-1];
    }
    double c1=0,c2=0;
    ll speed=1ll;
    for(i=1;i<interval_no;i++)
    {
        c1+=((double)X[i]/speed);
        speed++;
    }
    speed=(n-interval_no+2);
    //cout<<a.size()<<",";
    for(i=interval_no;i<=n+1;i++)
    {
        //cout<<speed<<" ";
        //if(speed==0) break;
        c2+=((double)X[i]/speed);
        speed--;
    }
    //cout<<endl;
    vector<double> c(3);
    c[0]=c1;
    c[1]=c2;

    return c;
}

double check_for_interval_k(ll interval_no,vector<double> a,ll n)
{
    vector<double> c(3);
    vector<double> m(3);
    c[0]=0.0;
    c[1]=0.0;
    c=make_c(interval_no,a);
    m=make_m(interval_no,n);
    //cout<<c[0]<<" "<<c[1]<<endl;
    double y;
    y=check_for_y(m[0],c[0],m[1],c[1]);
    //y=0;
    if(y==0) return 0;
    else return y;
}




int main()
{
    fast
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        
    
        ll l;
        cin>>n>>l;
        vector<double> a(n+3);
        a[0]=0;
        rep(i,n) cin>>a[i];
        a[n+1]=l;

        ll interval_no;
        ll flag=0;
        double y=0;
        
        for(interval_no=1;interval_no<=n+1;interval_no++)
        {
            //cout<<interval_no<<" ";            
            y=check_for_interval_k(interval_no,a,n);
            if(y!=0)
            {
                flag=1;
                break;                
            }
        }
        cout << fixed << setprecision(8);
        cout<<y<<endl;

    }
return 0;
}