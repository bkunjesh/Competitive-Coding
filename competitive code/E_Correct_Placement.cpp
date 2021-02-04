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
class tuple_class
{
    public:
        int h, w, id;
};
int output[200005];
vector<tuple_class> a, y;

bool compare(tuple_class a,tuple_class b)
{
    if(a.h==b.h)
        return a.w > b.w;
    else
        return a.h > b.h;
}
vector<int> b;
set<int> c;
map<int, int> z;


void solve()
{
    int i, j, k;
    cin >> n;
    a.resize(n);
    y.resize(n);
    b.resize(n);

    c.clear();
    z.clear();

    f(i,n)
    {
        cin >> a[i].h >> a[i].w;
        if(a[i].h<a[i].w)
            swap(a[i].h, a[i].w);

        y[i].h = a[i].h, y[i].w = a[i].w;

        a[i].id = i;
        output[i] = -1;
    }

    sort(a.begin(), a.end(), compare);

    int mn = a[n - 1].w;
    b[n - 1] = a[n - 1].id;
    c.insert(a[n - 1].h);
    z[a[n - 1].h] = n - 1;

    for (i = n - 2; i >= 0;i--)
    {
        if(a[i].w<mn)
        {
            mn = a[i].w;
            b[i] = a[i].id;
        }
        else
        {
            b[i] = b[i + 1];
        }
        if(c.count(a[i].h))
        {
            z[a[i].h] = i;
        }
        else
        {
            c.insert(a[i].h);
            z[a[i].h] = i;
        }
    }

    f(i,n)

    {
        auto it = c.lower_bound(a[i].h);

        if(it!=c.begin())
        {
            it--;
            int index = z[*it];
            if(y[b[index]].w<a[i].w)
            {
                output[a[i].id] = b[index] + 1;
            }
        }
    }
    for (i = 0; i < n;i++)

    {
        cout << output[i] << " ";
    }
    cout << endl;

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