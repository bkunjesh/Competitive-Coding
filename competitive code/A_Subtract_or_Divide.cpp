//@CodesUp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
int N = 200005;

int n;

vector<int> prime;
void make_prime_vect()
{
    int MAXN = 4000000;
    vector<int> br(MAXN + 1, 0);
    for (int i = 2; i <= MAXN; i++)
    {
        if (br[i] == 0)
        {
            for (int j = i * 2; j <= MAXN; j = j + i)
            {
                br[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAXN; i++)
        if (br[i] == 0)
            prime.push_back(i);
}

void solve()
{
    int i, j, k, tmp;

    cin >> n;
    if(n==1)
        {
            cout << 0 << endl;
            return;
        }
        int cnt = 0;
        if (n % 2 == 1)
        {
            cnt++;
            n--;
        }
    if(n%2==0)
    {
        if(n==2)
            cout << cnt+1 << endl;
        else
        {
            cout << cnt+2 << endl;
        }
        
    }
    
    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}