//@ikung
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
const int N = 200005;

int n;

void solve()
{
    int i, j, k;
    string s, sa = "", sb = "";
    cin >> n >> s;
    stack<char> a, b;
    int zcnt = 0, ocnt = 0;
    f(i, n)(s[i] == '0') ? zcnt++ : ocnt++;
    int fb = 0, ayega = zcnt / 2;
    
    f(i,n)
    {
        if (s[i] == '1')
        {
            if (a.empty() || b.empty())
            {
                a.push('(');
                fb++;
                b.push('(');
                sa += '(';
                sb += '(';
            }
            else if (fb + ayega < n / 2)
            {
                a.push('(');
                b.push('(');
                fb++;
                sa += '(';
                sb += '(';
                
            }
            else
            {
                a.pop();
                b.pop();
                sa += ')';
                sb += ')';
            }
        }
        else
        {
            if (a.empty() && b.empty())
            {
                cout << "NO" << endl;
                return;
            }
            else if (a.size() > b.size())
            {
                a.pop();
                b.push('(');
                sa += ')';
                sb += '(';
            }
            else
            {
                b.pop();
                a.push('(');
                fb++;
                ayega--;
                sa += '(';
                sb += ')';
            }
        }
    }
    if (a.empty() && b.empty())
    {
        cout << "YES" << endl;
        cout << sa << endl;
        cout << sb << endl;
    }
    else
    {
        cout << "NO" << endl;
        return;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif