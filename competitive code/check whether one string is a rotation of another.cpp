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
bool using_find_function(string a, string b)
{
    string c = a + a;
    if (a.size() != b.size())
        return 0;

    return (c.find(b) != c.size());
}
vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> pi(n + 1);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
bool using_kmp_algo(string a, string b)
{
    if (a.size() != b.size())
        return 0;

    string c = b + '#' + a + a;
    vector<int> pi = prefix_function(c);
    int m = b.size();
    for (auto it : pi)
    {
        if (it == m)
            return 1;
    }
    return 0;
}
vector<int> z_function(string s)
{
    int n = s.size();
    int l = 0, r = 0, i;
    vector<int> z(n + 1);

    for (i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && s[r - l] == s[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (z[k] < r - i + 1)
                z[i] = z[k];
            else
            {
                l = i;
                while (r < n && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}
bool using_z_function(string a, string b)
{
    if (a.size() != b.size())
        return 0;
    string c = b + '#' + a + a;
    vector<int> z = z_function(c);
    int m = b.size();
    for (auto it : z)
    {
        if (it == m)
        {
            return 1;
        }
    }
    return 0;
}
void solve()
{
    int i, j, k;

    string a, b;
    cin >> a >> b;
    cout << "isrotation(using find function): " << using_find_function(a, b) << endl;
    cout << "isrotation(using prefix function/kmp algo): " << using_kmp_algo(a, b) << endl;
    cout << "isrptaion(using z function): " << using_z_function(a, b) << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}